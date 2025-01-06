#include <lvgl.h>
#include "display.h"
#include "esp_bsp.h"
#include "lv_port.h"
#include <esp_log.h>   // Add this line to include the header file that declares ESP_LOGI
#include <esp_flash.h> // Add this line to include the header file that declares esp_flash_t
#include <esp_chip_info.h>
#include <esp_system.h>
#include <esp_heap_caps.h>
#include "ui/ui.h"

#include "driver/gpio.h"
#include "hid_dev.h"
#include "i2s_player.h"
#include "ble/ble_controller.c"
#include "configration.h"
#include "version.h"

static const char *TAG = "HD2 Macropad";

extern uint16_t hid_conn_id;
extern bool sec_conn;

bool lvglReady = false;

#define logSection(section) \
  ESP_LOGI(TAG, "\n\n************* %s **************\n", section);

uint8_t keymapIndex = 0;
uint8_t stratagemCode[8];
uint8_t stratagemMask;
bool soundPlayback = false;
char *soundFile;

bool playerMuted;
int inputDelay = 100;
int screenRotation = LV_DISP_ROT_90;

const uint8_t keymaps[2][4] = {
	{HID_KEY_W,
	 HID_KEY_S,
	 HID_KEY_A,
	 HID_KEY_D},
	{HID_KEY_UP_ARROW,
	 HID_KEY_LEFT_ARROW,
	 HID_KEY_DOWN_ARROW,
	 HID_KEY_RIGHT_ARROW}};

uint8_t LookupKeycode(uint8_t keyCode)
{
  uint8_t *keymap = keymaps[keymapIndex];
  uint8_t lookupIndex = keyCode - 1;

	keyCode = keymap[lookupIndex];

	return keyCode;
}

void setStratagemCode(uint8_t sequence[8], uint8_t mask)
{
  uint8_t sequenceLength = 0;

  for (uint8_t c = 0; c < 8; c++)
  {
    if (sequence[c] > 0)
    {
      stratagemCode[c] = LookupKeycode(sequence[c]);
      sequenceLength++;
    }
    else
    {
      break;
    }
  }

  stratagemMask = mask;
}

void playbackSound(char *path)
{
  soundPlayback = true;
  soundFile = path;
}

void dimScreen(int brightness)
{
  bsp_display_brightness_set(brightness);
}

void updateBluetooth()
{
  if (!lvglReady)
  {
    return;
  }

  if (sec_conn)
  {
    lv_obj_add_state(uic_CntBT, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(uic_CntBT, LV_STATE_CHECKED);
  }
}

#define CHECK_DELAY 50

void hid_input_task(void *pvParameters)
{
  while (1)
  {
    vTaskDelay(CHECK_DELAY / portTICK_PERIOD_MS);

    if (sec_conn && stratagemCode[0] > 0)
    {
      ESP_LOGI(TAG, "Send command");

      uint8_t cmdIndex = 0;

      esp_hidd_send_keyboard_value(hid_conn_id, stratagemMask, 0, 0);
      vTaskDelay(inputDelay / portTICK_PERIOD_MS);

      while (stratagemCode[cmdIndex] > 0 && cmdIndex < 8)
      {
        esp_hidd_send_keyboard_value(hid_conn_id, stratagemMask, &stratagemCode[cmdIndex], 1);
        vTaskDelay(inputDelay / portTICK_PERIOD_MS);

        esp_hidd_send_keyboard_value(hid_conn_id, stratagemMask, &stratagemCode[cmdIndex], 0);
        vTaskDelay(inputDelay / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "CMD Index: %c", (char)(cmdIndex + '0'));
        ESP_LOGI(TAG, "CMD Value: %d", stratagemCode[cmdIndex]);

        stratagemCode[cmdIndex] = 0;
        cmdIndex++;
      }

      esp_hidd_send_keyboard_value(hid_conn_id, 0, 0, 0);

      ESP_LOGI(TAG, "Finish command");
    }

    if (soundPlayback)
    {
      soundPlayback = false;

      if (!playerMuted)
      {
        play_wav(soundFile);
      }
    }
  }
}

void app_main()
{
  initConfig();
  ble_controller_init();

  xTaskCreate(&hid_input_task, "hid_input_task", 2048, NULL, 5, NULL);

  screenRotation = peekConfig("rotation", LV_DISP_ROT_90);

  logSection("Initialize panel device");
  // ESP_LOGI(TAG, "Initialize panel device");
  bsp_display_cfg_t cfg = {
      .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
      .buffer_size = EXAMPLE_LCD_QSPI_H_RES * EXAMPLE_LCD_QSPI_V_RES,
      .rotate = screenRotation,
  };

  bsp_display_start_with_config(&cfg);
  bsp_display_backlight_off();

  /* Lock the mutex due to the LVGL APIs are not thread-safe */
  bsp_display_lock(0);

  ui_init();

  /* Release the mutex */
  bsp_display_unlock();

  vTaskDelay(200 / portTICK_PERIOD_MS);

  bsp_display_backlight_on();

  /* Read config */
  loadConfig();

  lvglReady = true;
  updateBluetooth();

  playbackSound("S:assets/sound/intro.wav");

  char softwareVersion[12];
  strcpy(softwareVersion, SW_VER);

  lv_label_set_text(ui_LblVersion, softwareVersion);
}
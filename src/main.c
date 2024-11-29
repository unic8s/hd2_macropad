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

#include "nvs_flash.h"
#include "driver/gpio.h"
#include "hid_dev.h"
#include "i2s_sdcard.h"
#include "i2s_player.h"
#include "ble_controller.c"

static const char *TAG = "HD2 Macropad";

#define logSection(section) \
  ESP_LOGI(TAG, "\n\n************* %s **************\n", section);

uint8_t stratagemCode[8];
uint8_t stratagemMask;
bool soundPlayback = false;
char *soundFile;
bool playerMuted;

nvs_handle_t nvsConfig;

void setStratagemCode(uint8_t sequence[8], uint8_t mask)
{
  uint8_t sequenceLength = 0;

  for (uint8_t c = 0; c < 8; c++)
  {
    if (sequence[c] > 0)
    {
      stratagemCode[c] = sequence[c];
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

int inputDelay = 100;
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

uint8_t getConfig(char *key, uint8_t defaultValue)
{
  uint8_t value;

  esp_err_t ret = nvs_get_u8(nvsConfig, key, &value);

  switch (ret)
  {
  case ESP_OK:
    printf("%s = %" PRIu8 "\n", key, value);
    return value;
  case ESP_ERR_NVS_NOT_FOUND:
    printf("The value is not initialized yet!\n");
    break;
  default:
    printf("Error (%s) reading!\n", esp_err_to_name(ret));
  }

  return defaultValue;
}

void setConfig(char *key, uint8_t value)
{
  esp_err_t ret;

  ret = nvs_open("config", NVS_READWRITE, &nvsConfig);
  if (ret != ESP_OK)
  {
    printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
    return;
  }

  ret = nvs_set_u8(nvsConfig, key, value);
  printf((ret != ESP_OK) ? "Failed!\n" : "Done\n");

  nvs_close(nvsConfig);
}

void setDelay(int delay, bool restore)
{
  inputDelay = delay;

  char *textDelay[3];
  itoa(delay, textDelay, 10);

  lv_label_set_text(ui_LblDelay, &textDelay);

  if (restore)
  {
    lv_slider_set_value(ui_SldDelay, (int)(delay / 10), LV_ANIM_OFF);
  }
  else
  {
    setConfig("delay", delay);
  }
}

void setBrightness(int brightness, bool restore)
{
  bsp_display_brightness_set(brightness);

  char *textBrightness[3];
  itoa(brightness, textBrightness, 10);

  lv_label_set_text(ui_LblBrightness, &textBrightness);

  if (restore)
  {
    lv_slider_set_value(ui_SldBrightness, (int)(brightness / 10), LV_ANIM_OFF);
  }
  else
  {
    setConfig("brightness", brightness);
  }
}

void setMuted(bool muted, bool restore)
{
  playerMuted = muted;

  if (restore)
  {
    if (muted)
    {
      lv_obj_add_state(ui_ChbMute, LV_STATE_CHECKED);
    }
    else
    {
      lv_obj_clear_state(ui_ChbMute, LV_STATE_CHECKED);
    }
  }
  else
  {
    setConfig("muted", playerMuted ? 1 : 0);
  }
}

void loadConfig()
{
  esp_err_t ret;

  ret = nvs_open("config", NVS_READWRITE, &nvsConfig);
  if (ret != ESP_OK)
  {
    printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
    return;
  }

  uint8_t delay = getConfig("delay", 100);
  setDelay(delay, true);

  uint8_t screen_brightness = getConfig("brightness", 50);
  setBrightness(screen_brightness, true);

  uint8_t sound_muted = getConfig("muted", 0);
  setMuted(sound_muted == 1, true);

  nvs_close(nvsConfig);
}

void resetConfig()
{
  esp_err_t ret;

  ret = nvs_open("config", NVS_READWRITE, &nvsConfig);
  if (ret != ESP_OK)
  {
    printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
    return;
  }

  nvs_erase_all(nvsConfig);
  nvs_close(nvsConfig);

  setDelay(100, true);
  setBrightness(50, true);
  setMuted(0, true);
}

void app_main()
{
  esp_err_t ret;

  // Initialize NVS.
  ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(init_sdcard());
  lv_fs_fatfs_init();

  ret = ble_controller_init();

  xTaskCreate(&hid_input_task, "hid_input_task", 2048, NULL, 5, NULL);

  logSection("Initialize panel device");
  // ESP_LOGI(TAG, "Initialize panel device");
  bsp_display_cfg_t cfg = {
      .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
      .buffer_size = EXAMPLE_LCD_QSPI_H_RES * EXAMPLE_LCD_QSPI_V_RES,
      .rotate = LV_DISP_ROT_90,
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

  playbackSound("S:assets/sound/intro.wav");
}
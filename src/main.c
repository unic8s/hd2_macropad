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
#include "keymaps.h"
#include "version.h"


// Tag for logging
static const char *TAG = "HD2 Macropad";

// Bluetooth connection ID for HID device
extern uint16_t hid_conn_id;
// Bluetooth connection status
extern bool sec_conn;

// Flag for ready state of LVGL after init
bool lvglReady = false;

// Logging helper function for grouping
#define logSection(section) \
  ESP_LOGI(TAG, "\n\n************* %s **************\n", section);

// Stratagem code sequence (buffer) for execution
uint8_t stratagemCode[8];
// Stratagem mask for modifier key combination (ctrl, alt, etc.)
uint8_t stratagemMask;

// Flag for sound playback state
bool soundPlayback = false;
// Path to sound file which should be played
char *soundFile;
// Flag for muting sound playback
bool playerMuted;

// Delay for HID input execution in milliseconds (default: 100)
int inputDelay = 100;

// Rotation of screen (default: 90)
int screenRotation = LV_DISP_ROT_90;


// Set stratagem code sequence which should be executed
// sequence - keycode buffer
// mask - modifier keys
// plain - resolve via keymap or send directly (raw)
void setStratagemCode(uint8_t sequence[8], uint8_t mask, bool plain)
{
  uint8_t sequenceLength = 0;

  for (uint8_t c = 0; c < 8; c++)
  {
    if (sequence[c] > 0)
    {
      uint8_t rawCode = sequence[c];
      stratagemCode[c] = plain ? rawCode : LookupKeycode(rawCode);
      sequenceLength++;
    }
    else
    {
      break;
    }
  }

  stratagemMask = mask;
}

// Playback sound file from specified path
// path - path to the sound file
void playbackSound(char *path)
{
  soundPlayback = true;
  soundFile = path;
}

// Dim the screen to a specific value
// brightness - A brightness value between 0 and 100 (percent)
void dimScreen(int brightness)
{
  bsp_display_brightness_set(brightness);
}

// Update UI relating to bluetooth connection state
void updateBluetooth()
{
  if (!lvglReady)
  {
    return;
  }

  // Check bluetooth connection state
  if (sec_conn)
  {
    lv_obj_add_state(uic_CntBT, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(uic_CntBT, LV_STATE_CHECKED);
  }
}

// Delay for checking if a the stratagem execution buffer is filled
#define CHECK_DELAY 50

// Task for exeuction of HID inputs
void hid_input_task(void *pvParameters)
{
  while (1)
  {
    vTaskDelay(CHECK_DELAY / portTICK_PERIOD_MS);

    if (sec_conn && stratagemCode[0] > 0)
    {
      ESP_LOGI(TAG, "Send command");

      uint8_t cmdIndex = 0;

      // Send modifier keys (mask)
      esp_hidd_send_keyboard_value(hid_conn_id, stratagemMask, 0, 0);
      vTaskDelay(inputDelay / portTICK_PERIOD_MS);

      // Loop through command sequence from buffer
      while (stratagemCode[cmdIndex] > 0 && cmdIndex < 8)
      {
        // Press key defined by the keycode
        esp_hidd_send_keyboard_value(hid_conn_id, stratagemMask, &stratagemCode[cmdIndex], 1);
        vTaskDelay(inputDelay / portTICK_PERIOD_MS);

        // Release key defined by the keycode
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

    // Check if a sound playback is ongoing
    if (soundPlayback)
    {
      soundPlayback = false;

      // Check is playback is not muted
      if (!playerMuted)
      {
        play_wav(soundFile);
      }
    }
  }
}

// App main function
void app_main()
{
  // Init and load config from NVS storage
  initConfig();
  
  // Init bluetooth controller
  ble_controller_init();

  // Setup HID input task (async)
  xTaskCreate(&hid_input_task, "hid_input_task", 2048, NULL, 5, NULL);

  // Resolve screen rotation from config
  screenRotation = peekConfig("rotation", LV_DISP_ROT_90);

  logSection("Initialize panel device");
  // Display configuration
  bsp_display_cfg_t cfg = {
      .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
      .buffer_size = EXAMPLE_LCD_QSPI_H_RES * EXAMPLE_LCD_QSPI_V_RES,
      .rotate = screenRotation,
  };

  // Init display
  bsp_display_start_with_config(&cfg);
  // Turn of display backlight
  bsp_display_backlight_off();

  /* Lock the mutex due to the LVGL APIs are not thread-safe */
  bsp_display_lock(0);

  // Start LVGL
  ui_init();

  /* Release the mutex */
  bsp_display_unlock();

  vTaskDelay(200 / portTICK_PERIOD_MS);

  // Turn on display backlight
  bsp_display_backlight_on();

  /* Read config */
  loadConfig();

  lvglReady = true;
  updateBluetooth();

  // Playback intro sound
  playbackSound("S:assets/sound/intro.wav");

  // Update software version in UI
  char softwareVersion[12];
  strcpy(softwareVersion, SW_VER);

  lv_label_set_text(ui_LblVersion, softwareVersion);
}

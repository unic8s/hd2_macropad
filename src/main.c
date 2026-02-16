#include <lvgl.h>
#include "display.h"
#include "esp_bsp.h"
#include "lv_port.h"
#include <esp_log.h>   // Add this line to include the header file that declares ESP_LOGI
#include <esp_flash.h> // Add this line to include the header file that declares esp_flash_t
#include <esp_chip_info.h>
#include <esp_system.h>
#include <esp_heap_caps.h>
#include <ui/ui.h>
#include <ui/vars.h>
#include <ui/screens.h>
#include <ui/actions.h>
#include <ui/images.h>
#include <ui/ui_events.h>
#include <ui/ui_post.h>
#include "driver/gpio.h"
#include "hid_dev.h"
#include "i2s_player.h"
#include "ble/ble_controller.h"
#include "usb/usb_controller.h"
#include "configuration.h"
#include "keymaps.h"
#include "main.h"

// Tag for logging
static const char *TAG = "HD2 Macropad";

// Connection type
uint8_t connectionType = CT_NONE;

// Flag for ready state of LVGL after init
bool lvglReady = false;

// Logging helper function for grouping
#define logSection(section) \
  ESP_LOGI(TAG, "\n\n************* %s **************\n", section);

// Stratagem code sequence (buffer) for execution
uint8_t stratagemCode[MAX_CMD_LENGTH];
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

bool manualAutoComplete = true;
bool showCooldowns = false;

// Rotation of screen (default: 90)
int screenRotation = LV_DISP_ROT_90;

extern lv_obj_t *cooldownLabels[MAX_USER_STRATAGEMS];
extern uint32_t cooldownValues[MAX_USER_STRATAGEMS];
uint16_t lastCooldownDiffs[MAX_USER_STRATAGEMS];

lv_timer_t *cooldownTimer;

// Set stratagem code sequence which should be executed
// sequence - keycode buffer
// mask - modifier keys
// plain - resolve via keymap or send directly (raw)
void setStratagemCode(uint8_t sequence[MAX_CMD_LENGTH], uint8_t mask, bool plain)
{
  switch (connectionType)
  {
  case CT_BLUETOOTH:
    if (!ble_connected())
    {
      return;
    }
    break;
  case CT_USB:
    if (!usb_connected())
    {
      return;
    }
    break;
  default:
    return;
  }

  uint8_t sequenceLength = 0;

  for (uint8_t c = 0; c < MAX_CMD_LENGTH; c++)
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

// Update UI relating to connection state
void updateConnection()
{
  if (!lvglReady)
  {
    return;
  }

  lv_img_dsc_t *imgConnection;

  switch (connectionType)
  {
  case CT_BLUETOOTH:
    // Check bluetooth connection state
    if (ble_connected())
    {
      imgConnection = (lv_img_dsc_t *)&img_btcon;
    }
    else
    {
      imgConnection = (lv_img_dsc_t *)&img_btdis;
    }
    break;
  case CT_USB:
    // Check USB connection state
    if (usb_connected())
    {
      imgConnection = (lv_img_dsc_t *)&img_us_bcon;
    }
    else
    {
      imgConnection = (lv_img_dsc_t *)&img_us_bdis;
    }
    break;
  default:
    return;
  }

  lv_obj_set_style_bg_img_src(objects.img_connection1, imgConnection, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_img_src(objects.img_connection2, imgConnection, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Delay for checking if a the stratagem execution buffer is filled
#define INPUT_CHECK_DELAY 50

// Task for exeuction of HID inputs
void hid_input_task(void *pvParameters)
{
  while (1)
  {
    vTaskDelay(INPUT_CHECK_DELAY / portTICK_PERIOD_MS);

    if (stratagemCode[0] > 0)
    {
      ESP_LOGI(TAG, "Send command");

      uint8_t cmdIndex = 0;

      void (*fptr)(unsigned char, unsigned char, unsigned char);

      switch (connectionType)
      {
      case CT_BLUETOOTH:
        fptr = &ble_keyboard_send;
        break;
      case CT_USB:
        fptr = &usb_keyboard_send;
        break;
      default:
        return;
      }

      // Send modifier keys (mask)
      fptr(stratagemMask, 0, 0);

      vTaskDelay(inputDelay / portTICK_PERIOD_MS);

      // Loop through command sequence from buffer
      while (stratagemCode[cmdIndex] > 0 && cmdIndex < MAX_CMD_LENGTH)
      {
        // Press key defined by the keycode
        fptr(stratagemMask, stratagemCode[cmdIndex], 1);

        vTaskDelay(inputDelay / portTICK_PERIOD_MS);

        // Release key defined by the keycode
        fptr(stratagemMask, stratagemCode[cmdIndex], 0);

        vTaskDelay(inputDelay / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "CMD Index: %c", (char)(cmdIndex + '0'));
        ESP_LOGI(TAG, "CMD Value: %d", stratagemCode[cmdIndex]);

        stratagemCode[cmdIndex] = 0;
        cmdIndex++;
      }

      fptr(0, 0, 0);

      ESP_LOGI(TAG, "Finish command");
    }

    // Check if a sound playback is ongoing
    if (soundPlayback && lvglReady)
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

// Task for exeuction of EEZ Flows
void flow_tick_task(lv_timer_t *timer)
{
  ui_tick();
}

void ui_update_task(lv_timer_t *timer)
{
  if (!lvglReady)
  {
    return;
  }

  bool activeTimer = false;

  for (uint8_t c = 0; c < MAX_USER_STRATAGEMS; c++)
  {
    uint32_t cooldownValue = cooldownValues[c];
    lv_obj_t *cooldownLabel = cooldownLabels[c];
    int16_t diff = cooldownValue - getNow();

    if (cooldownValue > 0 && diff > 0)
    {
      activeTimer = true;

      if (lastCooldownDiffs[c] == diff)
      {
        continue;
      }

      lastCooldownDiffs[c] = diff;

      uint8_t min = 0;
      uint16_t sec = diff;

      while (sec >= 60)
      {
        min++;
        sec -= 60;
      }

      char *textCooldown = (char *)malloc(8 * sizeof(char));
      sprintf(textCooldown, "%d:%02d", min, sec);

      lv_label_set_text(cooldownLabel, (void *)textCooldown);

      if (lv_obj_has_flag(cooldownLabel, LV_OBJ_FLAG_HIDDEN))
      {
        lv_obj_clear_flag(cooldownLabel, LV_OBJ_FLAG_HIDDEN);
      }
    }
    else
    {
      cooldownValues[c] = 0;

      if (!lv_obj_has_flag(cooldownLabel, LV_OBJ_FLAG_HIDDEN))
      {
        lv_obj_add_flag(cooldownLabel, LV_OBJ_FLAG_HIDDEN);
      }
    }
  }

  if(!activeTimer && !cooldownTimer->paused){
    lv_timer_pause(cooldownTimer);
  }
}

// App main function
void app_main()
{
  // Init and load config from NVS storage
  initConfig();

  // Setup HID input task (async)
  xTaskCreatePinnedToCore(&hid_input_task, "hid_input_task", 2048, NULL, 5, NULL, 0);

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

  // Lock the mutex due to the LVGL APIs are not thread-safe
  bsp_display_lock(0);

  // Start LVGL
  ui_init();
  // UI post processing
  ui_post();

  // Release the mutex
  bsp_display_unlock();

  vTaskDelay(200 / portTICK_PERIOD_MS);

  // Turn on display backlight
  bsp_display_backlight_on();

  // Setup cooldown timer
  cooldownTimer = lv_timer_create(ui_update_task, 1000, NULL);
  cooldownTimer->repeat_count = -1;
  lv_timer_pause(cooldownTimer);

  // Read config
  loadConfig();

  lvglReady = true;

  // Playback intro sound
  playbackSound(SND_INTRO);

  updateConnection();
  updateStratagemSelection();
  updatePresets();

  // Setup timer for EEZ Flow ui tick
  lv_timer_t *flowTickTimer = lv_timer_create(flow_tick_task, 10, NULL);
  flowTickTimer->repeat_count = -1;
}
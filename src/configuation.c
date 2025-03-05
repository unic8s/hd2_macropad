#include <esp_system.h>
#include "nvs_flash.h"
#include "i2s_sdcard.h"
#include <lvgl.h>
#include "ui/ui.h"
#include "main.h"

// Handle for NVS config
nvs_handle_t nvsConfig;

extern bool playerMuted;
extern int inputDelay;
extern int screenRotation;
extern uint8_t keymapIndex;
extern uint8_t connectionType;

extern esp_err_t ble_controller_init();
extern esp_err_t ble_controller_deinit();
extern esp_err_t usb_controller_init();
extern esp_err_t usb_controller_deinit();

// Init configuration from NVS
esp_err_t initConfig()
{
    // Initialize NVS.
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(init_sdcard());
    lv_fs_fatfs_init();

    return ret;
}

// Read configuration value by key
// key - Identifier for configuration value
// defaultValue - Default value which will be returned if the key/value does not exist
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

// Write configuration value by key
// key - Identifier for configuration value
// value - Value which should be stored
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

// Write the HID input delay to configuration
void setDelay(int delay, bool restore)
{
    inputDelay = delay;

    char textDelay[] = "   ";
    itoa(delay, textDelay, 10);

    lv_label_set_text(ui_LblDelay, (void *)textDelay);

    if (restore)
    {
        lv_slider_set_value(ui_SldDelay, (int)(delay / 10), LV_ANIM_OFF);
    }
    else
    {
        setConfig("delay", delay);
    }
}

// Write the display rotation to configuration
void setRotation(int rotation, bool restore)
{
    screenRotation = rotation;

    if (restore)
    {
        if (screenRotation == LV_DISP_ROT_270)
        {
            lv_obj_add_state(ui_ChbFlip, LV_STATE_CHECKED);
        }
        else
        {
            lv_obj_clear_state(ui_ChbFlip, LV_STATE_CHECKED);
        }
    }
    else
    {
        setConfig("rotation", screenRotation);
    }

    playbackSound("S:assets/sound/_swt.wav");
}

// Write the display brightness to configuration
void setBrightness(int brightness, bool restore)
{
    dimScreen(brightness);

    char textBrightness[] = "   ";
    itoa(brightness, textBrightness, 10);

    lv_label_set_text(ui_LblBrightness, (void *)textBrightness);

    if (restore)
    {
        lv_slider_set_value(ui_SldBrightness, (int)(brightness / 10), LV_ANIM_OFF);
    }
    else
    {
        setConfig("brightness", brightness);
    }
}

// Write the sound mute state to configuration
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

    playbackSound("S:assets/sound/_swt.wav");
}

// Write the keymap assignment to configuration
void setConnectivity(int8_t index, bool restore)
{
    if (restore)
    {
        lv_dropdown_set_selected(ui_DdConnectivity, index - 1);
    }
    else
    {
        setConfig("connectivity", index);
    }

    playbackSound("S:assets/sound/_swt.wav");

    switch (connectionType)
    {
    case 1:
        // Deinit Bluetooth controller
        ble_controller_deinit();
        break;
    case 2:
        // Deinit USB controller
        usb_controller_deinit();
        break;
    }

    connectionType = index;

    switch (connectionType)
    {
    case 1:
        // Init Bluetooth controller
        ble_controller_init();
        break;
    case 2:
        // Init USB controller
        usb_controller_init();
        break;
    }

    vTaskDelay(500 / portTICK_PERIOD_MS);

    updateConnection();
}

// Write the keymap assignment to configuration
void setKeymap(uint8_t index, bool restore)
{
    keymapIndex = index;

    if (restore)
    {
        lv_dropdown_set_selected(ui_DdKeymap, index);
    }
    else
    {
        setConfig("keymap", index);
    }

    playbackSound("S:assets/sound/_swt.wav");
}

// Load complete configuration from NVS
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

    uint8_t rotation = getConfig("rotation", 100);
    setRotation(rotation, true);

    uint8_t screen_brightness = getConfig("brightness", 50);
    setBrightness(screen_brightness, true);

    uint8_t sound_muted = getConfig("muted", 0);
    setMuted(sound_muted == 1, true);

    uint8_t connectivity_index = getConfig("connectivity", 0);
    setConnectivity(connectivity_index, true);

    uint8_t keymap_index = getConfig("keymap", 0);
    setKeymap(keymap_index, true);

    nvs_close(nvsConfig);
}

// Load single configuration of a key/value from NVS
uint8_t peekConfig(char *key, uint8_t defaultValue)
{
    esp_err_t ret;

    ret = nvs_open("config", NVS_READWRITE, &nvsConfig);
    if (ret != ESP_OK)
    {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
        return defaultValue;
    }

    uint8_t value = getConfig(key, defaultValue);

    nvs_close(nvsConfig);

    return value;
}

// Clear all stored configuration in NVS and write it to default values
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
    setConnectivity(0, true);
    setKeymap(0, true);
    setRotation(LV_DISP_ROT_90, true);
}
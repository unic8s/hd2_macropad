#include <esp_system.h>
#include "esp_log.h"
#include "nvs_flash.h"
#include "i2s_sdcard.h"
#include <lvgl.h>
#include "ui/ui.h"
#include "ui/screens.h"
#include "main.h"

const char *TAG_CFG = "Configuration";

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
uint8_t getConfig(char *key, int8_t defaultValue)
{
    uint8_t value;

    esp_err_t ret = nvs_get_u8(nvsConfig, key, &value);

    switch (ret)
    {
    case ESP_OK:
        ESP_LOGI(TAG_CFG, "%s = %" PRIu8 "\n", key, value);
        return value;
    case ESP_ERR_NVS_NOT_FOUND:
        ESP_LOGI(TAG_CFG, "The value is not initialized yet!\n");
        break;
    default:
        ESP_LOGE(TAG_CFG, "Error (%s) reading!\n", esp_err_to_name(ret));
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
        ESP_LOGE(TAG_CFG, "Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
        return;
    }

    ret = nvs_set_u8(nvsConfig, key, value);

    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG_CFG, "Failed!\n");
    }
    else
    {
        ESP_LOGI(TAG_CFG, "Done\n");
    }

    nvs_close(nvsConfig);
}

// Write the HID input delay to configuration
void setDelay(int delay, bool restore)
{
    inputDelay = delay;

    char *textDelay = (char *)malloc(7 * sizeof(char));
    sprintf(textDelay, "%d %s", delay, " ms");

    lv_label_set_text(objects.lbl_delay, (void *)textDelay);

    if (restore)
    {
        lv_slider_set_value(objects.sld_delay, (int)(delay / 10), LV_ANIM_OFF);
    }
    else
    {
        setConfig("delay", delay);
    }
}

// Write the display rotation to configuration
void setRotation(int rotation, bool restore)
{
    bool restart = !restore && screenRotation != rotation;

    screenRotation = rotation;

    if (restore)
    {
        if (screenRotation == LV_DISP_ROT_270)
        {
            lv_obj_add_state(objects.chb_flip, LV_STATE_CHECKED);
        }
        else
        {
            lv_obj_clear_state(objects.chb_flip, LV_STATE_CHECKED);
        }
    }
    else
    {
        setConfig("rotation", screenRotation);
    }

    playbackSound(SND_SWITCH);

    if (restart)
    {
        esp_restart();
    }
}

// Write the display brightness to configuration
void setBrightness(int brightness, bool restore)
{
    dimScreen(brightness);

    char *textBrightness = (char *)malloc(5 * sizeof(char));
    sprintf(textBrightness, "%d %s", brightness, " %");

    lv_label_set_text(objects.lbl_brightness, (void *)textBrightness);

    if (restore)
    {
        lv_slider_set_value(objects.sld_brightness, (int)(brightness / 10), LV_ANIM_OFF);
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
            lv_obj_add_state(objects.chb_mute, LV_STATE_CHECKED);
        }
        else
        {
            lv_obj_clear_state(objects.chb_mute, LV_STATE_CHECKED);
        }
    }
    else
    {
        setConfig("muted", playerMuted ? 1 : 0);
    }

    playbackSound(SND_SWITCH);
}

// Write the keymap assignment to configuration
void setConnectivity(uint8_t index, bool restore)
{
    if (restore)
    {
        lv_dropdown_set_selected(objects.dd_connectivity, index - 1);
    }
    else
    {
        setConfig("connectivity", index);
    }

    playbackSound(SND_SWITCH);

    switch (connectionType)
    {
    case CT_BLUETOOTH:
        // Deinit Bluetooth controller
        ble_controller_deinit();
        break;
    case CT_USB:
        // Deinit USB controller
        usb_controller_deinit();
        break;
    default:
        break;
    }

    connectionType = index;

    switch (connectionType)
    {
    case CT_BLUETOOTH:
        // Init Bluetooth controller
        ble_controller_init();
        break;
    case CT_USB:
        // Init USB controller
        usb_controller_init();
        break;
    default:
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
        lv_dropdown_set_selected(objects.dd_keymap, index);
    }
    else
    {
        setConfig("keymap", index);
    }

    playbackSound(SND_SWITCH);
}

esp_err_t openConfig()
{
    esp_err_t ret = nvs_open("config", NVS_READWRITE, &nvsConfig);

    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG_CFG, "Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
        return ret;
    }

    return ret;
}

void closeConfig()
{
    nvs_close(nvsConfig);
}

// Load complete configuration from NVS
void loadConfig()
{
    if (openConfig() != ESP_OK)
    {
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

    closeConfig();
}

// Load single configuration of a key/value from NVS
int8_t peekConfig(char *key, int8_t defaultValue)
{
    if (openConfig() != ESP_OK)
    {
        return defaultValue;
    }

    int8_t value = getConfig(key, defaultValue);

    closeConfig();

    return value;
}

// Clear all stored configuration in NVS and write it to default values
void resetConfig()
{
    if (openConfig() != ESP_OK)
    {
        return;
    }

    nvs_erase_all(nvsConfig);

    closeConfig();

    setDelay(100, true);
    setBrightness(50, true);
    setMuted(0, true);
    setKeymap(0, true);
    setRotation(LV_DISP_ROT_90, true);
}
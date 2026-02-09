#include <esp_system.h>
#include "esp_log.h"
#include "nvs_flash.h"
#include "i2s_sdcard.h"
#include <lvgl.h>
#include "ui/ui.h"
#include "ui/screens.h"
#include "main.h"
#include "configuration.h"

const char *TAG_CFG = "Configuration";

// Handle for NVS config
nvs_handle_t nvsConfig;

extern bool playerMuted;
extern int inputDelay;
extern int screenRotation;
extern uint8_t keymapIndex;
extern uint8_t connectionType;
extern bool manualAutoComplete;
extern bool showCooldowns;

extern esp_err_t ble_controller_init();
extern esp_err_t ble_controller_deinit();
extern esp_err_t usb_controller_init();
extern esp_err_t usb_controller_deinit();

#define CFG_KEY_DELAY "delay"
#define CFG_KEY_ROTATION "rotation"
#define CFG_KEY_BRIGHTNESS "brightness"
#define CFG_KEY_MUTED "muted"
#define CFG_KEY_CONNECTIVITY "connectivity"
#define CFG_KEY_KEYMAP "keymap"
#define CFG_KEY_AUTOCOMPLETE "autoComplete"
#define CFG_KEY_COOLDOWN "showCooldown"
#define CFG_KEY_SHIPMODULES "shipModules"

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
int8_t getConfig(char *key, int8_t defaultValue)
{
    uint8_t value;

    esp_err_t ret = nvs_get_u8(nvsConfig, key, &value);

    switch (ret)
    {
    case ESP_OK:
        ESP_LOGI(TAG_CFG, "%s = %" PRIu8 "\n", key, value);
        return value;
    case ESP_ERR_NVS_NOT_FOUND:
        ESP_LOGI(TAG_CFG, "The value of (%s) is not initialized yet!\n", key);
        break;
    default:
        ESP_LOGE(TAG_CFG, "Error (%s) reading!\n", esp_err_to_name(ret));
    }

    return defaultValue;
}

int8_t getConfigBig(char *key, int16_t defaultValue)
{
    uint8_t value;

    esp_err_t ret = nvs_get_u16(nvsConfig, key, &value);

    switch (ret)
    {
    case ESP_OK:
        ESP_LOGI(TAG_CFG, "%s = %" PRIu16 "\n", key, value);
        return value;
    case ESP_ERR_NVS_NOT_FOUND:
        ESP_LOGI(TAG_CFG, "The value of (%s) is not initialized yet!\n", key);
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
        ESP_LOGE(TAG_CFG, "Write (%s) failed!\n", key);
    }
    else
    {
        ESP_LOGI(TAG_CFG, "Done\n");
    }

    nvs_close(nvsConfig);
}

void setConfigBig(char *key, uint16_t value)
{
    esp_err_t ret;

    ret = nvs_open("config", NVS_READWRITE, &nvsConfig);
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG_CFG, "Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
        return;
    }

    ret = nvs_set_u16(nvsConfig, key, value);

    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG_CFG, "Write (%s) failed!\n", key);
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
        setConfig(CFG_KEY_DELAY, delay);
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
        setConfig(CFG_KEY_ROTATION, screenRotation);
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
        setConfig(CFG_KEY_BRIGHTNESS, brightness);
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
        setConfig(CFG_KEY_MUTED, playerMuted ? 1 : 0);
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
        setConfig(CFG_KEY_CONNECTIVITY, index);
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
        setConfig(CFG_KEY_KEYMAP, index);
    }

    playbackSound(SND_SWITCH);
}

void setAutoComplete(bool enable, bool restore)
{
    manualAutoComplete = enable;

    if (restore)
    {
        if (enable)
        {
            lv_obj_add_state(objects.chb_auto_complete, LV_STATE_CHECKED);
        }
        else
        {
            lv_obj_clear_state(objects.chb_auto_complete, LV_STATE_CHECKED);
        }
    }
    else
    {
        setConfig(CFG_KEY_AUTOCOMPLETE, manualAutoComplete ? 1 : 0);
    }

    playbackSound(SND_SWITCH);
}

void setCooldown(bool enable, bool restore)
{
    showCooldowns = enable;

    if (restore)
    {
        if (enable)
        {
            lv_obj_add_state(objects.chb_cooldowns, LV_STATE_CHECKED);
        }
        else
        {
            lv_obj_clear_state(objects.chb_cooldowns, LV_STATE_CHECKED);
        }
    }
    else
    {
        setConfig(CFG_KEY_COOLDOWN, showCooldowns ? 1 : 0);
    }

    playbackSound(SND_SWITCH);
}

void setShipModules(bool restore)
{
    shipModule list[MAX_SHIP_MODULES] = {
        {SHIP_LVC, objects.chb_ship_mod_lvc},
        {SHIP_ZBL, objects.chb_ship_mod_zbl},
        {SHIP_HC, objects.chb_ship_mod_hc},
        {SHIP_MA, objects.chb_ship_mod_ma},
        {SHIP_SRP, objects.chb_ship_mod_srp},
        {SHIP_SS, objects.chb_ship_mod_ss},
        {SHIP_ACT, objects.chb_ship_mod_act},
        {SHIP_TSU, objects.chb_ship_mod_tsu},
        {SHIP_RLS, objects.chb_ship_mod_rls},
        {SHIP_DT, objects.chb_ship_mod_dt}};

    if (restore)
    {
        uint16_t shipModules = getConfigBig(CFG_KEY_SHIPMODULES, 0);

        for (uint8_t c = 0; c < MAX_SHIP_MODULES; c++)
        {
            shipModule item = list[c];

            if (shipModules >= item.value)
            {
                shipModules -= item.value;

                lv_obj_add_state(item.checkbox, LV_STATE_CHECKED);
            }
            else
            {
                lv_obj_clear_state(item.checkbox, LV_STATE_CHECKED);
            }
        }
    }
    else
    {
        uint16_t shipModules = 0;

        for (uint8_t c = 0; c < MAX_SHIP_MODULES; c++)
        {
            shipModule item = list[c];

            if (lv_obj_has_state(item.checkbox, LV_STATE_CHECKED))
            {
                shipModules += item.value;
            }
        }

        setConfigBig(CFG_KEY_SHIPMODULES, shipModules);
    }
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

    uint8_t delay = getConfig(CFG_KEY_DELAY, 100);
    setDelay(delay, true);

    uint8_t rotation = getConfig(CFG_KEY_ROTATION, 100);
    setRotation(rotation, true);

    uint8_t screen_brightness = getConfig(CFG_KEY_BRIGHTNESS, 50);
    setBrightness(screen_brightness, true);

    uint8_t sound_muted = getConfig(CFG_KEY_MUTED, 0);
    setMuted(sound_muted == 1, true);

    uint8_t connectivity_index = getConfig(CFG_KEY_CONNECTIVITY, 0);
    setConnectivity(connectivity_index, true);

    uint8_t keymap_index = getConfig(CFG_KEY_KEYMAP, 0);
    setKeymap(keymap_index, true);

    uint8_t auto_complete = getConfig(CFG_KEY_AUTOCOMPLETE, 0);
    setAutoComplete(auto_complete == 1, true);

    uint8_t show_cooldown = getConfig(CFG_KEY_COOLDOWN, 0);
    setCooldown(show_cooldown == 1, true);

    setShipModules(true);

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
    setAutoComplete(1, true);
    setCooldown(0, true);
    setShipModules(true);

    setRotation(LV_DISP_ROT_90, true);
}
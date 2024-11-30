#include <esp_system.h>
#include "nvs_flash.h"
#include "i2s_sdcard.h"
#include <lvgl.h>
#include "ui/ui.h"
#include "main.h"

nvs_handle_t nvsConfig;

extern bool playerMuted;
extern int inputDelay;
extern int screenRotation;

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
}

void setBrightness(int brightness, bool restore)
{
    dimScreen(brightness);

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

    uint8_t rotation = getConfig("rotation", 100);
    setRotation(rotation, true);

    uint8_t screen_brightness = getConfig("brightness", 50);
    setBrightness(screen_brightness, true);

    uint8_t sound_muted = getConfig("muted", 0);
    setMuted(sound_muted == 1, true);

    nvs_close(nvsConfig);
}

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
    setRotation(LV_DISP_ROT_90, true);
}
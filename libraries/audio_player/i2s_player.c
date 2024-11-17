#include "i2s_configuration.h" // basic sysetm includes and pin setup
#include "driver/i2s_std.h"    // i2s setup
#include "lvgl.h"

#define AUDIO_BUFFER 2048

static const char *TAG = "I2S Audio Player";

i2s_chan_handle_t tx_handle;

esp_err_t i2s_setup(void)
{
    // setup a standard config and the channel
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_AUTO, I2S_ROLE_MASTER);
    ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, &tx_handle, NULL));

    // setup the i2s config
    i2s_std_config_t std_cfg = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(48000),                                                    // the wav file sample rate
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO), // the wav faile bit and channel config
        .gpio_cfg = {
            // refer to configuration.h for pin setup
            .mclk = AUDIO_I2S_MCK_IO,
            .bclk = AUDIO_I2S_BCK_IO,
            .ws = AUDIO_I2S_LRCK_IO,
            .dout = AUDIO_I2S_DO_IO,
            .din = 0,
            .invert_flags = {
                .mclk_inv = false,
                .bclk_inv = false,
                .ws_inv = false,
            },
        },
    };
    return i2s_channel_init_std_mode(tx_handle, &std_cfg);
}

esp_err_t play_wav(char *fp)
{
    lv_fs_file_t f;
    lv_fs_res_t res;

    res = lv_fs_open(&f, fp, LV_FS_MODE_RD);
    if (res != LV_FS_RES_OK)
    {
        ESP_LOGE(TAG, "(%s) FS open failed.", fp);
        lv_fs_close(&f);
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "(%s) FS opened.", fp);

    // skip the header...
    res = lv_fs_seek(&f, 44, LV_FS_SEEK_SET);
    if (res != LV_FS_RES_OK)
    {
        ESP_LOGE(TAG, "(%s) Seek failed.", fp);
        lv_fs_close(&f);
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "(%s) FS seeked.", fp);

    // create a writer buffer
    size_t chunkSize = sizeof(int16_t);
    int16_t *buf = calloc(AUDIO_BUFFER, chunkSize);
    uint32_t bytes_read = 0;
    size_t bytes_written = 0;

    lv_fs_read(&f, buf, AUDIO_BUFFER, &bytes_read);
    //ESP_LOGI(TAG, "Bytes read: %lx", bytes_read);

    i2s_channel_enable(tx_handle);

    while (bytes_read > 0)
    {
        // write the buffer to the i2s
        i2s_channel_write(tx_handle, buf, bytes_read * (uint32_t)chunkSize, &bytes_written, portMAX_DELAY);
        lv_fs_read(&f, buf, AUDIO_BUFFER, &bytes_read);
        //ESP_LOGI(TAG, "Bytes read: %lx", bytes_read);
    }

    i2s_channel_disable(tx_handle);
    free(buf);

    lv_fs_close(&f);

    return ESP_OK;
}
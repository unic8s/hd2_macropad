

#include <esp_system.h>
#include <esp_log.h>
#include "i2s_configuration.h" // basic sysetm includes and pin setup
#include "i2s_sdcard.h"        // sdcard intialization
#include "driver/i2s_std.h"    // i2s setup


#define AUDIO_BUFFER 2048 


static const char *TAG = "DEMO_LVGL";

i2s_chan_handle_t tx_handle;


esp_err_t i2s_setup(void)
{
    // setup a standard config and the channel
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_AUTO, I2S_ROLE_MASTER);
    ESP_ERROR_CHECK(i2s_new_channel(&chan_cfg, &tx_handle, NULL));

    // setup the i2s config
    i2s_std_config_t std_cfg = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(44100),                                                    // the wav file sample rate
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO), // the wav faile bit and channel config
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
    FILE *fh = fopen(fp, "rb");
    if (fh == NULL)
    {
        ESP_LOGE(TAG, "Failed to open file");
        return ESP_ERR_INVALID_ARG;
    }

    // skip the header...
    fseek(fh, 44, SEEK_SET);

    // create a writer buffer
    int16_t *buf = calloc(AUDIO_BUFFER, sizeof(int16_t));
    size_t bytes_read = 0;
    size_t bytes_written = 0;

    bytes_read = fread(buf, sizeof(int16_t), AUDIO_BUFFER, fh);

    i2s_channel_enable(tx_handle);

    while (bytes_read > 0)
    {
        // write the buffer to the i2s
        i2s_channel_write(tx_handle, buf, bytes_read * sizeof(int16_t), &bytes_written, portMAX_DELAY);
        bytes_read = fread(buf, sizeof(int16_t), AUDIO_BUFFER, fh);
        ESP_LOGV(TAG, "Bytes read: %d", bytes_read);
    }

    i2s_channel_disable(tx_handle);
    free(buf);

    return ESP_OK;
}
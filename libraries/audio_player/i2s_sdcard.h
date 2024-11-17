// Copyright (c) 2023 Michael Heijmans
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Description:
// This file contains helpers for the SD card.

#pragma once

#include "i2s_configuration.h"
#include "driver/sdmmc_host.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"

sdmmc_card_t *card;

esp_err_t init_sdcard(void)
{
  char TAG[] = "SDCARD";

  ESP_LOGI(TAG, "Initializing SD card");

  sdmmc_host_t host = SDMMC_HOST_DEFAULT();
  sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
  slot_config.width = 1;
  slot_config.clk = SD_MMC_CLK;
  slot_config.cmd = SD_MMC_CMD;
  slot_config.d0 = SD_MMC_D0;
  slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
      .format_if_mount_failed = false,
      .max_files = 5,
      .allocation_unit_size = 16 * 1024};

  esp_err_t ret = esp_vfs_fat_sdmmc_mount(MOUNT_POINT, &host, &slot_config, &mount_config, &card);

  if (ret != ESP_OK)
  {
    if (ret == ESP_FAIL)
    {
      ESP_LOGE(TAG, "Failed to mount filesystem. "
                    "If you want the card to be formatted, set format_if_mount_failed = true.");
    }
    else
    {
      ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                    "Make sure SD card lines have pull-up resistors in place.",
               esp_err_to_name(ret));
    }
    return ESP_FAIL;
  }
  return ESP_OK;
}

void print_sdcard_info(void)
{
  char TAG[] = "sdcard";
  ESP_LOGI(TAG, "SD card info:");
  ESP_LOGI(TAG, "Name: %s", card->cid.name);
  ESP_LOGI(TAG, "Speed: %s", (card->csd.tr_speed < 25000000) ? "Default Speed" : "High Speed");
  ESP_LOGI(TAG, "Frequency: %ukHz", card->max_freq_khz);
  ESP_LOGI(TAG, "Log Bus Width: %u", card->log_bus_width);
  ESP_LOGI(TAG, "Read Block Length: %u", card->csd.read_block_len);
}
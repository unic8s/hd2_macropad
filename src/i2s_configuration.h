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
// This file contains the configuration for the ESP32-WROVER-E board.
// It is used by the main.c file to configure the board.

#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_mac.h"
#include "esp_chip_info.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/i2s_std.h"

// Pin Configurations

// I2S Configuration
#define AUDIO_I2S_PORT I2S_NUM_0
#define AUDIO_I2S_MCK_IO -1 // MCK
#define AUDIO_I2S_BCK_IO 42 // BCK
#define AUDIO_I2S_LRCK_IO 2   // LCK
#define AUDIO_I2S_DO_IO 41  // DIN

void print_system_info(void)
{
  char TAG[] = "conf";
  // print idf version
  ESP_LOGI(TAG, "IDF version: %s", esp_get_idf_version());

  // show chip info
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  ESP_LOGI(TAG, "Chip Model: %s", CONFIG_IDF_TARGET);

  ESP_LOGI(TAG, "This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  ESP_LOGI(TAG, "silicon revision %d, ", chip_info.revision);

  // mac address
  uint8_t mac[6];
  esp_efuse_mac_get_default(mac);
  ESP_LOGI(TAG, "default mac: %02x:%02x:%02x:%02x:%02x:%02x",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}
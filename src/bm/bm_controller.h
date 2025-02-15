#ifndef _BM_CONTROLLER_H
#define _BM_CONTROLLER_H

#include "esp_err.h"
#include <stdbool.h>

// I2C configuration
#ifdef CONFIG_IDF_TARGET_ESP32S3
#define I2C_MASTER_NUM (I2C_NUM_1) // I2C port number
#else
#define I2C_MASTER_NUM (I2C_NUM_0) // I2C port number
#endif
#define I2C_MASTER_SDA_IO 10      // SDA pin
#define I2C_MASTER_SCL_IO 11      // SCL pin
#define I2C_MASTER_FREQ_HZ 100000 // I2C clock frequency
#define BM_I2C_ADDR 0x34     // AXP2101 I2C address

/**
 * @brief Check if the battery is connected
 *
 * @return true if the battery is connected, false otherwise
 */
bool bm_is_battery_connected(void);

/**
 * @brief Check if the device is charging
 *
 * @return true if charging, false otherwise
 */
bool bm_is_charging(void);

/**
 * @brief Initialize I2C and AXP2101 communication
 *
 * @return esp_err_t ESP_OK if successful, an error code otherwise
 */
esp_err_t bm_init(void);

/**
 * @brief Deinitialize I2C and AXP2101 communication
 *
 * @return esp_err_t ESP_OK if successful, an error code otherwise
 */
esp_err_t bm_deinit(void);

/**
 * @brief Get the power level from the AXP2101 module
 *
 * @param[out] power_level Pointer to store the power level (0-100%)
 * @return esp_err_t ESP_OK if successful, an error code otherwise
 */
esp_err_t bm_get_power_level(uint8_t *power_level);

#endif /* _BM_CONTROLLER_H */
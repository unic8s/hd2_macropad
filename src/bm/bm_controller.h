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
#define BM_I2C_ADDR 0x75          // IP5306 I2C address


void bm_i2c_write(uint8_t slave_address, uint8_t register_address, uint8_t data);
uint8_t bm_i2c_read(uint8_t slave_address, uint8_t register_address);

void bm_init();

void bm_boost_mode(uint8_t boost_en);
void bm_charger_mode(uint8_t charger_en);
void bm_power_on_load(uint8_t power_on_en);
void bm_boost_output(uint8_t output_val);
void bm_button_shutdown(uint8_t shutdown_val);

void bm_boost_ctrl_signal(uint8_t press_val);
void bm_short_press_boost(uint8_t boost_en);
void bm_boost_after_vin(uint8_t val);
void bm_low_battery_shutdown(uint8_t shutdown_en);

void bm_set_long_press_time(uint8_t press_time_val);
void bm_set_light_load_shutdown_time(uint8_t shutdown_time);

void bm_set_charging_stop_voltage(uint8_t voltage_val);
void bm_end_charge_current(uint8_t current_val);
void bm_charger_under_voltage(uint8_t voltage_val);

void bm_set_battery_voltage(uint8_t voltage_val);
void bm_set_voltage_pressure(uint8_t voltage_val);
void bm_set_cc_loop(uint8_t current_val);

uint8_t bm_check_charging_status(void);
uint8_t bm_check_battery_status(void);
uint8_t bm_check_load_level(void);
uint8_t bm_short_press_detect(void);
uint8_t bm_long_press_detect(void);
uint8_t bm_double_press_detect(void);

uint8_t bm_get_battery_level();

esp_err_t bm_error_state();

#endif /* _BM_CONTROLLER_H */
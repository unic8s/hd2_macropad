#include "driver/i2c.h"
#include "bm_controller.h"
#include <stdio.h>

bool i2c_initialized = false;
bool bm_has_error = false;

#define IP5306_ADDRESS 0x75

#define SYS_CTL0 0x00
#define SYS_CTL1 0x01
#define SYS_CTL2 0x02

#define Charger_CTL0 0x20
#define Charger_CTL1 0x21
#define Charger_CTL2 0x22
#define Charger_CTL3 0x23

#define CHG_DIG_CTL0 0x24

#define REG_READ0 0x70
#define REG_READ1 0x71
#define REG_READ2 0x72
#define REG_READ3 0x77

/*SYS_CTL0*/
union
{
    struct
    {
        uint8_t BUTTON_SHUTDOWN : 1;
        uint8_t SET_BOOST_OUTPUT_ENABLE : 1;
        uint8_t POWER_ON_LOAD : 1;
        uint8_t RSVD : 1;
        uint8_t CHARGER_ENABLE : 1;
        uint8_t BOOST_ENABLE : 1;
        uint8_t RSVD2 : 2;

    } bits;

    uint8_t reg_byte;

} reg_SYS_CTL0_t;

/*SYS_CTL1*/
union
{
    struct
    {
        uint8_t LOW_BATTERY_SHUTDOWN_ENABLE : 1;
        uint8_t RSVD : 1;
        uint8_t BOOST_AFTER_VIN : 1;
        uint8_t RSVD2 : 2;
        uint8_t SHORT_PRESS_BOOST_SWITCH_ENABLE : 1;
        uint8_t FLASHLIGHT_CTRL_SIGNAL_SELECTION : 1;
        uint8_t BOOST_CTRL_SIGNAL_SELECTION : 1;
    } bits;

    uint8_t reg_byte;

} reg_SYS_CTL1_t;

/*SYS_CTL2*/
union
{
    struct
    {
        uint8_t RSVD : 2;
        uint8_t LIGHT_LOAD_SHUTDOWN_TIME : 2;
        uint8_t LONG_PRESS_TIME : 1;
        uint8_t RSVD2 : 3;
    } bits;

    uint8_t reg_byte;
} reg_SYS_CTL2_t;

/*SHUTDOWN_TIME_VALUE*/
#define SHUTDOWN_8s 0
#define SHUTDOWN_32s 1
#define SHUTDOWN_16s 2
#define SHUTDOWN_64s 3

/*Charger_CTL0*/
union
{
    struct
    {
        uint8_t CHARGING_FULL_STOP_VOLTAGE : 2;
        uint8_t RSVD : 6;
    } bits;

    uint8_t reg_byte;
} reg_Charger_CTL0_t;

/*CUT-OFF VOLTAGE RANGE*/
#define CUT_OFF_VOLTAGE_0 0 // 4.14/4.26/4.305/4.35  V
#define CUT_OFF_VOLTAGE_1 1 // 4.17/4.275/4.32/4.365 V
#define CUT_OFF_VOLTAGE_2 2 // 4.185/4.29/4.335/4.38 V
#define CUT_OFF_VOLTAGE_3 3 // 4.2/4.305/4.35/4.395  V

/*Charger_CTL1*/
union
{
    struct
    {
        uint8_t RSVD : 2;
        uint8_t CHARGE_UNDER_VOLTAGE_LOOP : 3;
        uint8_t RSVD2 : 1;
        uint8_t END_CHARGE_CURRENT_DETECTION : 2;
    } bits;

    uint8_t reg_byte;
} reg_Charger_CTL1_t;

/*BATTERY STOP CHARGING CURRENT*/
#define CURRENT_200 0
#define CURRENT_400 1
#define CURRENT_500 2
#define CURRENT_600 3

/*VOLTAGE SETTING FOR CHARGING*/
#define VOUT_0 0 // 4.45
#define VOUT_1 1 // 4.5
#define VOUT_2 2 // 4.55
#define VOUT_3 3 // 4.6
#define VOUT_4 4 // 4.65
#define VOUT_5 5 // 4.7
#define VOUT_6 6 // 4.75
#define VOUT_7 7 // 4.8

/*Charger_CTL2*/
union
{
    struct
    {
        uint8_t VOLTAGE_PRESSURE : 2;
        uint8_t BATTERY_VOLTAGE : 2;
        uint8_t RSVD : 4;
    } bits;

    uint8_t reg_byte;
} reg_Charger_CTL2_t;

/*Battery Voltage */
#define BATT_VOLTAGE_3 3 // 4.4
#define BATT_VOLTAGE_2 2 // 4.35
#define BATT_VOLTAGE_1 1 // 4.3
#define BATT_VOLTAGE_0 0 // 4.2

/*Voltage Pressure setting*/
#define Pressurized_42 3
#define Pressurized_28 2
#define Pressurized_14 1
#define Not_pressurized 0

/*Charger_CTL3*/
union
{
    struct
    {
        uint8_t RSVD : 5;
        uint8_t CHARGE_CC_LOOP : 1;
        uint8_t RSVD2 : 2;
    } bits;

    uint8_t reg_byte;
} reg_Charger_CTL3_t;

/*CHG_DIG_CTL0*/
union
{
    struct
    {
        uint8_t VIN_CURRENT : 5;
        uint8_t RSVD : 3;
    } bits;

    uint8_t reg_byte;
} reg_CHG_DIG_CTL0_t;

/*REG_READ0*/
union
{
    struct
    {
        uint8_t RSVD : 3;
        uint8_t CHARGE_ENABLE : 1;
        uint8_t RSVD2 : 4;
    } bits;

    uint8_t reg_byte;
} reg_READ0_t;

/*REG_READ1*/
union
{
    struct
    {
        uint8_t RSVD : 3;
        uint8_t BATTERY_STATUS : 1;
        uint8_t RSVD2 : 4;
    } bits;

    uint8_t reg_byte;
} reg_READ1_t;

/*REG_READ2*/
union
{
    struct
    {
        uint8_t RSVD : 2;
        uint8_t LOAD_LEVEL : 1;
        uint8_t RSVD2 : 5;
    } bits;

    uint8_t reg_byte;
} reg_READ2_t;

/*REG_READ3*/
union
{
    struct
    {
        uint8_t SHORT_PRESS_DETECT : 1;
        uint8_t LONG_PRESS_DETECT : 1;
        uint8_t DOUBLE_PRESS_DETECT : 1;
        uint8_t RSVD : 5;
    } bits;

    uint8_t reg_byte;
} reg_READ3_t;

void bm_init()
{
  reg_SYS_CTL0_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, SYS_CTL0);
  reg_SYS_CTL1_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, SYS_CTL1);
  reg_SYS_CTL2_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, SYS_CTL2);

  reg_Charger_CTL0_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, Charger_CTL0);
  reg_Charger_CTL1_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, Charger_CTL1);
  reg_Charger_CTL2_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, Charger_CTL2);
  reg_Charger_CTL3_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, Charger_CTL3);
}

void bm_i2c_write(uint8_t slave_address, uint8_t register_address, uint8_t data)
{
  esp_err_t err = i2c_master_write_to_device(I2C_MASTER_NUM, slave_address,
                                             &register_address, 1, pdMS_TO_TICKS(100));
  if (err != ESP_OK)
  {
    printf("ERROR [%s]: Failed to write register address 0x%02X: %s\n",
           __func__, register_address, esp_err_to_name(err));
    bm_has_error = true;
  }
}

/*@brief  read the register value
@param  register address to read,and i2c address of the device
@retval current register data
*/
uint8_t bm_i2c_read(uint8_t slave_address, uint8_t register_address)
{
  esp_err_t err = i2c_master_read_from_device(I2C_MASTER_NUM, slave_address, &register_address, 1,
                                              pdMS_TO_TICKS(100));
  if (err != ESP_OK)
  {
    printf("ERROR [%s]: Failed to read register 0x%02X: %s\n", __func__,
           register_address, esp_err_to_name(err));
    bm_has_error = true;
    return false;
  }

  return register_address;
}

void bm_boost_mode(uint8_t boost_en)
{
  reg_SYS_CTL0_t.bits.BOOST_ENABLE = boost_en;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL0, reg_SYS_CTL0_t.reg_byte);
}

/*@brief  select charger mode
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void bm_charger_mode(uint8_t charger_en)
{
  reg_SYS_CTL0_t.bits.CHARGER_ENABLE = charger_en;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL0, reg_SYS_CTL0_t.reg_byte);
}

/*@brief  select auto power on once load detected
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void bm_power_on_load(uint8_t power_on_en)
{
  reg_SYS_CTL0_t.bits.POWER_ON_LOAD = power_on_en;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL0, reg_SYS_CTL0_t.reg_byte);
}

/*@brief  boost o/p normally open function
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void bm_boost_output(uint8_t output_val)
{
  reg_SYS_CTL0_t.bits.SET_BOOST_OUTPUT_ENABLE = output_val;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL0, reg_SYS_CTL0_t.reg_byte);
}

/*@brief  enter shutdown mode using button
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void bm_button_shutdown(uint8_t shutdown_val)
{
  reg_SYS_CTL0_t.bits.BUTTON_SHUTDOWN = shutdown_val;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL0, reg_SYS_CTL0_t.reg_byte);
}

/*@brief  boost control mode using button
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void bm_boost_ctrl_signal(uint8_t press_val)
{
  reg_SYS_CTL1_t.bits.BOOST_CTRL_SIGNAL_SELECTION = press_val;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL1, reg_SYS_CTL1_t.reg_byte);
}

/*@brief
  @param  enable or disable bit
  @retval None
  @note   Default value - disable
*/
void bm_short_press_boost(uint8_t boost_en)
{
  reg_SYS_CTL1_t.bits.SHORT_PRESS_BOOST_SWITCH_ENABLE = boost_en;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL1, reg_SYS_CTL1_t.reg_byte);
}

/*@brief  keep boost mode on after input supply removal
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void bm_boost_after_vin(uint8_t val)
{
  reg_SYS_CTL1_t.bits.BOOST_AFTER_VIN = val;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL1, reg_SYS_CTL1_t.reg_byte);
}

/*@brief  shutdown if battery voltage reaches 3V
  @param  enable or disable bit
  @retval None
  @note   Default value - enable
*/
void bm_low_battery_shutdown(uint8_t shutdown_en)
{
  reg_SYS_CTL1_t.bits.LOW_BATTERY_SHUTDOWN_ENABLE = shutdown_en;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL1, reg_SYS_CTL1_t.reg_byte);
}

/*@brief  set long press timing
  @param  long press time value - 0 for 2s , 1 for 3s
  @retval None
  @note   Default value - disable
*/
void bm_set_long_press_time(uint8_t press_time_val)
{
  reg_SYS_CTL2_t.bits.LONG_PRESS_TIME = press_time_val;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL2, reg_SYS_CTL2_t.reg_byte);
}

/*@brief  set light load shutdown timing
  @param  shutdown time value - 0 for 8s, 1 for 32s, 2 for 16s and 3 for 64s
  @retval None
  @note   Default value - disable
*/
void bm_set_light_load_shutdown_time(uint8_t shutdown_time)
{
  reg_SYS_CTL2_t.bits.LIGHT_LOAD_SHUTDOWN_TIME = shutdown_time;

  bm_i2c_write(IP5306_ADDRESS, SYS_CTL2, reg_SYS_CTL2_t.reg_byte);
}

/*@brief  set charging cutoff voltage range for battery
  @param  voltage range value - 0 for 4.14/4.26/4.305/4.35  V
                                1 for 4.17/4.275/4.32/4.365 V
                                2 for 4.185/4.29/4.335/4.38 V
                                3 for 4.2/4.305/4.35/4.395  V
  @retval None
  @note   Default value - 2
*/
void bm_set_charging_stop_voltage(uint8_t voltage_val)
{
  reg_Charger_CTL0_t.bits.CHARGING_FULL_STOP_VOLTAGE = voltage_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL0, reg_Charger_CTL0_t.reg_byte);
}

/*@brief  set charging complete current detection
  @param  current value - 3 : 600mA
                          2 : 500mA
                          1 : 400mA
                          0 : 200mA

  @retval None
  @note   Default value - 1
*/
void bm_end_charge_current(uint8_t current_val)
{
  reg_Charger_CTL1_t.bits.END_CHARGE_CURRENT_DETECTION = current_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL1, reg_Charger_CTL1_t.reg_byte);
}

/*@brief  set voltage Vout for charging
  @param  voltage value - 111:4.8
                          110:4.75
                          101:4.7
                          100:4.65
                          011:4.6
                          010:4.55
                          001:4.5
                          000:4.45
  @retval None
  @note   Default value - 101
*/
void bm_charger_under_voltage(uint8_t voltage_val)
{
  reg_Charger_CTL1_t.bits.CHARGE_UNDER_VOLTAGE_LOOP = voltage_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL1, reg_Charger_CTL1_t.reg_byte);
}

/*@brief  set battery voltage
  @param  voltage value - 00:4.2
                          01:4.3
                          02:4.35
                          03:4.4
  @retval None
  @note   Default value - 00
*/
void bm_set_battery_voltage(uint8_t voltage_val)
{
  reg_Charger_CTL2_t.bits.BATTERY_VOLTAGE = voltage_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL2, reg_Charger_CTL2_t.reg_byte);
}

/*@brief  set constant voltage charging setting
  @param  voltage value - 11: Pressurized 42mV
                          10: Pressurized 28mV
                          01: Pressurized 14mV
                          00: Not pressurized
  @retval None
  @note   Default value - 01
  @note :4.30V/4.35V/4.4V It is recommended to pressurize 14mV
         4.2V It is recommended to pressurize 28mV
*/
void bm_set_voltage_pressure(uint8_t voltage_val)
{
  reg_Charger_CTL2_t.bits.VOLTAGE_PRESSURE = voltage_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL2, reg_Charger_CTL2_t.reg_byte);
}

/*@brief  set constant current charging setting
  @param  value - 1:VIN end CC Constant current
                  0:BAT end CC Constant current
  @retval None
  @note   Default value - 1
*/
void bm_set_cc_loop(uint8_t current_val)
{
  reg_Charger_CTL3_t.bits.CHARGE_CC_LOOP = current_val;

  bm_i2c_write(IP5306_ADDRESS, Charger_CTL3, reg_Charger_CTL3_t.reg_byte);
}

/*@brief  get current charging status
  @param  None
  @retval integer representation of charging status(1 - charging is on and 0 if  charging is off)
*/
uint8_t bm_check_charging_status(void)
{
  reg_READ0_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ0);

  return reg_READ0_t.bits.CHARGE_ENABLE;
}

/*@brief  get current battery status
  @param  None
  @retval integer representation of battery status(1 - fully charged and 0 if still charging)
*/
uint8_t bm_check_battery_status(void)
{
  reg_READ1_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ1);

  return reg_READ1_t.bits.BATTERY_STATUS;
}

/*@brief  get output load level
  @param  None
  @retval integer representation of load status(1 - light load and 0 if heavy load)
*/
uint8_t bm_check_load_level(void)
{
  reg_READ2_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ2);

  return reg_READ2_t.bits.LOAD_LEVEL;
}

/*@brief  detect if a short press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t bm_short_press_detect(void)
{
  reg_READ3_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ3);

  return reg_READ3_t.bits.SHORT_PRESS_DETECT;
}

/*@brief  detect if a long press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t bm_long_press_detect(void)
{
  reg_READ3_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ3);

  return reg_READ3_t.bits.LONG_PRESS_DETECT;
}

/*@brief  detect if a double press occurred
  @param  None
  @retval button status
  @note clear this bit after reading by writing 1
*/
uint8_t bm_double_press_detect(void)
{
  reg_READ3_t.reg_byte = bm_i2c_read(IP5306_ADDRESS, REG_READ3);

  return reg_READ3_t.bits.DOUBLE_PRESS_DETECT;
}

esp_err_t bm_error_state()
{
  return bm_has_error ? ESP_ERR_INVALID_RESPONSE : ESP_OK;
}
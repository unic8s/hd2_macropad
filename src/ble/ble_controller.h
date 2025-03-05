#ifndef _BLE_CONTROLLER_H
#define _BLE_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t ble_controller_init();
esp_err_t ble_controller_deinit();
bool ble_connected();
void ble_keyboard_send(uint8_t special_key_mask, uint8_t keyboard_cmd, uint8_t num_key);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

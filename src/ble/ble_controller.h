#ifndef _BLE_CONTROLLER_H
#define _BLE_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t ble_controller_init();
void ble_keyboard_send(key_mask_t special_key_mask, uint8_t *keyboard_cmd, uint8_t num_key);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

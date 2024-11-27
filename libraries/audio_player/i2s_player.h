#ifndef _I2S_PLAYER_H
#define _I2S_PLAYER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <esp_system.h>

esp_err_t i2s_setup(void);
esp_err_t play_wav(char *fp);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

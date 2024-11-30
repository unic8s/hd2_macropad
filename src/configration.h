#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <esp_system.h>

esp_err_t initConfig();
uint8_t getConfig(char *key, uint8_t defaultValue);
void setConfig(char *key, uint8_t value);
void setDelay(int delay, bool restore);
void setRotation(int rotation, bool restore);
void setBrightness(int brightness, bool restore);
void setMuted(bool muted, bool restore);
void loadConfig();
void resetConfig();
uint8_t peekConfig(char *key, uint8_t defaultValue);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
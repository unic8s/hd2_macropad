#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <esp_system.h>

esp_err_t initConfig();
int8_t getConfig(char *key, int8_t defaultValue);
void setConfig(char *key, uint8_t value);
void setDelay(int delay, bool restore);
void setRotation(int rotation, bool restore);
void setBrightness(int brightness, bool restore);
void setMuted(bool muted, bool restore);
void setConnectivity(uint8_t index, bool restore);
void setKeymap(uint8_t index, bool restore);
void loadConfig();
esp_err_t openConfig();
void closeConfig();
void resetConfig();
int8_t peekConfig(char *key, int8_t defaultValue);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
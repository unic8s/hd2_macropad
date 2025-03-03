#ifndef MAIN
#define MAIN

#include <esp_system.h>

void app_main();
void playbackSound(char *path);
void setStratagemCode(uint8_t sequence[8], uint8_t mask, bool plain);
void dimScreen(int brightness);
void updateConnection();
void updateBatteryInfo();

#endif

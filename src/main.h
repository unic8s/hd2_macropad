#ifndef MAIN
#define MAIN

#include <esp_system.h>

#ifdef __cplusplus
extern "C"
{
#endif

    enum // ConnectionType
    {
        CT_NONE = 0,
        CT_BLUETOOTH = 1,
        CT_USB = 2,
    };

#ifdef __cplusplus
} /*extern "C"*/
#endif

void app_main();
void playbackSound(char *path);
void setStratagemCode(uint8_t sequence[8], uint8_t mask, bool plain);
void dimScreen(int brightness);
void updateConnection();
void updateBatteryInfo();

#endif

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

// UI Sounds
#define SND_SWITCH "S:assets/sound/_swt.wav"
#define SND_INTRO "S:assets/sound/intro.wav"
#define SND_SELECT "S:assets/sound/_sel.wav"
#define SND_DESELECT "S:assets/sound/_des.wav"
#define SND_RESET "S:assets/sound/_rst.wav"
#define SND_SWIPE "S:assets/sound/_swp.wav"

// Default stratagems
#define SND_REINFORCE "S:assets/sound/reinf.wav"
#define SND_SUPPLY "S:assets/sound/supp.wav"
#define SND_SOS "S:assets/sound/sos.wav"
#define SND_EAGLE_RELOAD "S:assets/sound/eagrel.wav"

// User selected stratagems
#define SND_BACKPACK "S:assets/sound/bkpk.wav"
#define SND_BOT "S:assets/sound/bot.wav"
#define SND_EAGLE "S:assets/sound/eagstk.wav"
#define SND_MINES "S:assets/sound/min.wav"
#define SND_MORTAR "S:assets/sound/mrt.wav"
#define SND_ORBITAL "S:assets/sound/orbstk.wav"
#define SND_SHIELD "S:assets/sound/shd.wav"
#define SND_SENTRY "S:assets/sound/snt.wav"
#define SND_WEAPON "S:assets/sound/weap.wav"

void app_main();
void playbackSound(char *path);
void setStratagemCode(uint8_t sequence[8], uint8_t mask, bool plain);
void dimScreen(int brightness);
void updateConnection();
void updateBatteryInfo();

#endif

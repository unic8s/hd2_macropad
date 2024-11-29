#ifndef MAIN
#define MAIN

void app_main();
void playbackSound(char *path);
void setStratagemCode(uint8_t sequence[8], uint8_t mask);
void setDelay(int delay, bool restore);
void setBrightness(int brightness, bool restore);
void setMuted(bool muted, bool restore);
void resetConfig();

#endif
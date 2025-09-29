#ifndef _UI_POST_H
#define _UI_POST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

void ui_post();
void animate_preset_load(lv_obj_t *target);
void animate_preset_save(lv_obj_t *target);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
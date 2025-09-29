#ifndef _UI_POST_H
#define _UI_POST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

void ui_post();
void PresetSaveAnim_Animation(lv_obj_t * TargetObject, int delay);
void PresetLoadAnim_Animation(lv_obj_t * TargetObject, int delay);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
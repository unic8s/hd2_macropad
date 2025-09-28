#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_setup_2_game(lv_event_t * e);
extern void action_reset_stratagems(lv_event_t * e);
extern void action_intro_2_setup(lv_event_t * e);
extern void action_setup_2_config(lv_event_t * e);
extern void action_config_2_about(lv_event_t * e);
extern void action_about_2_config(lv_event_t * e);
extern void action_config_2_reset(lv_event_t * e);
extern void action_reset_cancel(lv_event_t * e);
extern void action_reset_confirm(lv_event_t * e);
extern void action_get_preset(lv_event_t * e);
extern void action_set_preset(lv_event_t * e);
extern void action_config_2_setup(lv_event_t * e);
extern void action_game_2_setup(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/
#include "main.h"
#include "ui.h"
#include "ui_events.h"
#include "configration.h"

// Change HID input delay
void action_change_delay(lv_event_t *e)
{
	int32_t delay = lv_slider_get_value(e->target);

	setDelay(delay * 10, false);
}

// Change display brightness
void action_change_brightness(lv_event_t *e)
{
	int32_t brightness = lv_slider_get_value(e->target);

	setBrightness(brightness * 10, false);
}

// Change sound mute (on/off)
void action_mute_sound(lv_event_t *e)
{
	bool muted = lv_obj_get_state(e->target) & LV_STATE_CHECKED ? true : false;

	setMuted(muted, false);
}

// Trigger when tab navigation has changed
void action_tab_changed(lv_event_t *e)
{
	playbackSound(SND_SWIPE);
}

// Change screen orientation
void action_flip_screen(lv_event_t *e)
{
	bool flip = lv_obj_get_state(e->target) & LV_STATE_CHECKED ? true : false;

	setRotation(flip ? LV_DISP_ROT_270 : LV_DISP_ROT_90, false);

	esp_restart();
}

void action_restart_device(lv_event_t *e)
{
	esp_restart();
}

void action_reset_cancel(lv_event_t *e)
{
	lv_scr_load_anim(objects.config, LV_SCR_LOAD_ANIM_FADE_OUT, 500, 0, false);
}

void action_reset_confirm(lv_event_t *e)
{
	resetConfig();

	lv_scr_load_anim(objects.config, LV_SCR_LOAD_ANIM_FADE_OUT, 500, 0, false);
}

void action_intro_2_setup(lv_event_t *e)
{
	assignStratagems();

	lv_scr_load_anim(objects.setup, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 1000, 1000, false);
}

void action_setup_2_config(lv_event_t *e)
{
	lv_scr_load_anim(objects.config, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 1000, 0, false);
}

void action_config_2_about(lv_event_t *e)
{
	lv_scr_load_anim(objects.about, LV_SCR_LOAD_ANIM_MOVE_TOP, 1000, 0, false);
}

void action_about_2_config(lv_event_t *e)
{
	lv_scr_load_anim(objects.config, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 1000, 0, false);
}

void action_config_2_reset(lv_event_t *e)
{
	lv_scr_load_anim(objects.reset, LV_SCR_LOAD_ANIM_FADE_IN, 500, 0, false);
}

void action_config_2_setup(lv_event_t *e)
{
	lv_scr_load_anim(objects.setup, LV_SCR_LOAD_ANIM_MOVE_LEFT, 1000, 0, false);
}

void action_game_2_setup(lv_event_t *e)
{
	lv_scr_load_anim(objects.setup, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 1000, 0, false);
}

void action_game_2_mission(lv_event_t *e)
{
	lv_scr_load_anim(objects.mission, LV_SCR_LOAD_ANIM_NONE, 250, 0, false);
}

void action_mission_2_game(lv_event_t *e)
{
	lv_scr_load_anim(objects.game, LV_SCR_LOAD_ANIM_FADE_IN, 250, 0, false);
}
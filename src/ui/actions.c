#include "ui.h"
#include "ui_events.h"
#include "configration.h"

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
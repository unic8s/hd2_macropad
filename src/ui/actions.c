#include "main.h"
#include "ui.h"
#include "ui_events.h"
#include "configuration.h"
#include "screens.h"
#include "usb/usb_controller.h"

extern uint8_t connectionType;

// Change HID input delay
void action_change_delay(lv_event_t *e)
{
	int32_t delay = lv_slider_get_value(e->current_target);

	setDelay(delay * 10, false);
}

// Change display brightness
void action_change_brightness(lv_event_t *e)
{
	int32_t brightness = lv_slider_get_value(e->current_target);

	setBrightness(brightness * 10, false);
}

// Change sound mute (on/off)
void action_mute_sound(lv_event_t *e)
{
	bool muted = lv_obj_get_state(e->current_target) & LV_STATE_CHECKED ? true : false;

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
	bool flip = lv_obj_get_state(e->current_target) & LV_STATE_CHECKED ? true : false;

	setRotation(flip ? LV_DISP_ROT_270 : LV_DISP_ROT_90, false);

	esp_restart();
}

void action_restart_device(lv_event_t *e)
{
	switch (connectionType)
	{
	case CT_USB:
		usb_controller_deinit();
		break;
	default:
		break;
	}

	esp_restart();
}

void action_reset_confirm(lv_event_t *e)
{
	resetConfig();
}

void action_assign_stratagems(lv_event_t *e)
{
	assignStratagems();
}

void action_enable_image_mode(lv_event_t *e)
{
	enableImageMode();
}

void action_reset_presets(lv_event_t *e)
{
	resetPresets();
}

void action_disable_image_mode(lv_event_t *e)
{
	disableImageMode();
}

void action_finalize_manual_execution(lv_event_t *e)
{
	finalizeManualExecution();
}

void action_auto_complete(lv_event_t *e)
{
	bool autoComplete = lv_obj_get_state(e->current_target) & LV_STATE_CHECKED ? true : false;

	setAutoComplete(autoComplete, false);
}

void action_set_cooldown(lv_event_t *e)
{
	bool cooldown = lv_obj_get_state(e->current_target) & LV_STATE_CHECKED ? true : false;

	setCooldown(cooldown, false);

	if (!cooldown)
	{
		resetAllCooldowns();
	}
}

void action_set_ship_modules(lv_event_t *e)
{
	setShipModules(false);
}

void action_reset_all_cooldowns(lv_event_t *e)
{
	resetAllCooldowns();
}

void action_init_hid(lv_event_t *e)
{
	initConnection();
}
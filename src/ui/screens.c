#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static void event_handler_checked_cb_setup_tab_rifle(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_rifle(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_mg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_mg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_hmg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_hmg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_sw(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_sw(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_ac(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_ac(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_amr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_amr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_rg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_rg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_lc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_lc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_qc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_qc(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_at(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_at(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_e(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_e(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_sg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_sg(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_special(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_special(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_arl(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_arl(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_c(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_c(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_eat(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_eat(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_en(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_en(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_rr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_rr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_spr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_spr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_wsp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_wsp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_gl(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_gl(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_de(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_de(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_ste(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_ste(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_weapons_ft(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_weapons_ft(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_backpack(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_backpack(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_bsb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_bsb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_sgp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_sgp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_ds(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_ds(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_gd(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_gd(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_gdb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_gdb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_gdr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_gdr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_gdk(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_gdk(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_sup(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_sup(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_ph(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_ph(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_jp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_jp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_hp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_hp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_backpack_wp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_backpack_wp(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_supply(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_supply(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_supply_frv(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_supply_frv(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_supply_pe(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_supply_pe(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_supply_ee(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_supply_ee(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_supply_otf(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_supply_otf(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_supply_ss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_supply_ss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_sentry(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_sentry(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj0(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj0(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_mgs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_mgs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_gs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_gs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_acs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_acs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_hmge(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_hmge(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_ate(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_ate(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj1(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_fs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_fs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_ms(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_ms(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_rs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_rs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_ems(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_ems(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_sentry_ls(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_sentry_ls(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_ground(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_ground(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj2(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_gm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_gm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_tt(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_tt(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_sgr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_sgr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_apm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_apm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj3(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_atm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_atm(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_im(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_im(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_ground_gb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_ground_gb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_strike(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_strike(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike120(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike120(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike380(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike380(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_ors(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_ors(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_ogb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_ogb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_oas(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_oas(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_ol(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_ol(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_ops(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_ops(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_owb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_owb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_oes(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_oes(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_onb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_onb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_ogs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_ogs(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_strike_oss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_strike_oss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_tab_eagle(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_tab_eagle(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj4(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle110(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle110(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle500(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle500(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle_a(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle_a(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle_cb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle_cb(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_obj5(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_obj5(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle_sr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle_sr(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle_na(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle_na(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

static void event_handler_checked_cb_setup_eagle_ss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_select_stratagem(e);
    }
}

static void event_handler_unchecked_cb_setup_eagle_ss(lv_event_t *e) {
    lv_obj_t *ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        action_deselect_stratagem(e);
    }
}

void create_screen_intro() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.intro = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_add_event_cb(obj, action_intro_2_setup, LV_EVENT_SCREEN_LOADED, (void *)0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ImgSplash
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_splash = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_splash);
        }
    }
    
    tick_screen_intro();
}

void tick_screen_intro() {
}

void create_screen_setup() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.setup = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // TabViewSetup
            lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 38);
            objects.tab_view_setup = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), 280);
            lv_obj_add_event_cb(obj, action_tab_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // TabRifle
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Rifle");
                    objects.tab_rifle = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_rifle, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_rifle, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // WeaponsMG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_mg = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_mg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_mg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_mg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsHMG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_hmg = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_hmg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_hmg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hmg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSW
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_sw = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_sw, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_sw, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sw1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ac = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_ac, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_ac, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ac1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAMR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_amr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_amr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_amr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_amr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsRG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_rg = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_rg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_rg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsLC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_lc = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_lc, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_lc, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_lc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsQC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_qc = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_qc, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_qc, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_qc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_at = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_at, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_at, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_at1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_e = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_e, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_e, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_sg = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_sg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_sg, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSpecial
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Special");
                    objects.tab_special = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_special, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_special, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // WeaponsARL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_arl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_arl, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_arl, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_arl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_c = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_c, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_c, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_c1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsEAT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_eat = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_eat, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_eat, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_eat1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsEN
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_en = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_en, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_en, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_en1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsRR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_rr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_rr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_rr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSPR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_spr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_spr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_spr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_spr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsWSP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_wsp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_wsp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_wsp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_wsp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsGL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_gl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_gl, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_gl, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsDE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_de = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_de, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_de, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_de1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSTE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ste = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_ste, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_ste, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ste1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsFT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ft = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_weapons_ft, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_weapons_ft, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ft1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabBackpack
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Backpack");
                    objects.tab_backpack = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_backpack, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_backpack, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BackpackBSB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_bsb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_bsb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_bsb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_bsb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackSGP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_sgp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_sgp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_sgp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sgp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackDS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_ds = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_ds, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_ds, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ds1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gd = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_gd, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_gd, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_gdb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_gdb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_gdr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_gdr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDK
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdk = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_gdk, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_gdk, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdk1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackSUP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_sup = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_sup, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_sup, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sup1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackPH
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_ph = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_ph, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_ph, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ph1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackJP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_jp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_jp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_jp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_jp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackHP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_hp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_hp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_hp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackWP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_wp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_backpack_wp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_backpack_wp, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_wp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSupply
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Supply");
                    objects.tab_supply = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_supply, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_supply, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // SupplyFRV
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_frv = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_supply_frv, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_supply_frv, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_frv1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyPE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_pe = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_supply_pe, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_supply_pe, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_pe1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyEE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_ee = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_supply_ee, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_supply_ee, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ee1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyOTF
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_otf = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_supply_otf, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_supply_otf, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_otf1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplySS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_ss = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_supply_ss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_supply_ss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ss1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSentry
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Sentry");
                    objects.tab_sentry = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_sentry, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_sentry, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj0 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj0, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj0, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SentryMGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_mgs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_mgs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_mgs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_mgs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_gs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_gs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_gs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryACS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_acs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_acs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_acs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_acs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryHMGE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_hmge = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_hmge, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_hmge, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hmge1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryATE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ate = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_ate, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_ate, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ate1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj1, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj1, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SentryFS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_fs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_fs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_fs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_fs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryMS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ms = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_ms, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_ms, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ms1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryRS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_rs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_rs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_rs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryEMS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ems = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_ems, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_ems, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ems1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryLS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ls = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_sentry_ls, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_sentry_ls, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ls1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabGround
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Ground");
                    objects.tab_ground = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_ground, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_ground, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj2 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj2, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj2, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // GroundGM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_gm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_gm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_gm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundTT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_tt = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_tt, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_tt, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_tt1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundSGR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_sgr = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_sgr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_sgr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sgr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundAPM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_apm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_apm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_apm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_apm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj3 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj3, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj3, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // GroundATM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_atm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_atm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_atm, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_atm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundIM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_im = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_im, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_im, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_im1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundGB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_gb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_ground_gb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_ground_gb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabStrike
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Strike");
                    objects.tab_strike = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_strike, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_strike, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Strike120
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike120 = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike120, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike120, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_1201, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Strike380
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike380 = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike380, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike380, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_3801, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeORS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ors = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_ors, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_ors, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ors1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOGB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ogb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_ogb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_ogb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ogb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOAS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oas = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_oas, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_oas, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oas1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ol = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_ol, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_ol, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ol1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOPS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ops = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_ops, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_ops, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ops1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOWB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_owb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_owb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_owb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_owb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOES
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oes = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_oes, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_oes, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oes1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeONB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_onb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_onb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_onb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_onb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ogs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_ogs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_ogs, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ogs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOSS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oss = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_strike_oss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_strike_oss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oss1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabEagle
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Eagle");
                    objects.tab_eagle = obj;
                    lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_tab_eagle, LV_EVENT_VALUE_CHANGED, (void *)0);
                    lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_tab_eagle, LV_EVENT_VALUE_CHANGED, (void *)0);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj4, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj4, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // Eagle110
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle110 = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle110, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle110, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e1101, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Eagle500
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle500 = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle500, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle500, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e5001, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleA
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_a = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle_a, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle_a, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ea1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleCB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_cb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ecb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_obj5, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_obj5, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // EagleSR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_sr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle_sr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle_sr, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_esr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleNA
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_na = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle_na, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle_na, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ena1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleSS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_ss = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_checked_cb_setup_eagle_ss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, event_handler_unchecked_cb_setup_eagle_ss, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ess1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_tab_icons);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, LV_PCT(100), 38);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_setup_2_config, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_config, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_reset_stratagems, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_get_preset, LV_EVENT_SHORT_CLICKED, (void *)1);
                    lv_obj_add_event_cb(obj, action_set_preset, LV_EVENT_LONG_PRESSED, (void *)1);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset2
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_get_preset, LV_EVENT_SHORT_CLICKED, (void *)2);
                    lv_obj_add_event_cb(obj, action_set_preset, LV_EVENT_LONG_PRESSED, (void *)2);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BarAmount
                            lv_obj_t *obj = lv_bar_create(parent_obj);
                            objects.bar_amount = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), 8);
                            lv_bar_set_range(obj, 0, 6);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 63, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // LabelAmount
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_amount = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "0 / 6");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_setup_2_game, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_play, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // MsgBox
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.msg_box = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff282b30), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 223, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // MsgLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.msg_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Msg\nBox");
                }
            }
        }
    }
    
    tick_screen_setup();
}

void tick_screen_setup() {
}

void create_screen_config() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.config = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // TabViewConfig
            lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 38);
            objects.tab_view_config = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), 280);
            lv_obj_add_event_cb(obj, action_tab_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Display / Audio");
                    objects.obj6 = obj;
                    add_style_tab_config(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(50), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Screen brightness");
                                }
                                {
                                    // LblBrightness
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_brightness = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(50), LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "100 %");
                                }
                                {
                                    // SldBrightness
                                    lv_obj_t *obj = lv_slider_create(parent_obj);
                                    objects.sld_brightness = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 16);
                                    lv_slider_set_range(obj, 1, 10);
                                    lv_slider_set_value(obj, 5, LV_ANIM_OFF);
                                    lv_obj_add_event_cb(obj, action_change_brightness, LV_EVENT_VALUE_CHANGED, (void *)0);
                                    add_style_slider_config(obj);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Flip screen 180°");
                                }
                                {
                                    // ChbFlip
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    objects.chb_flip = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 64, 32);
                                    lv_obj_add_event_cb(obj, action_flip_screen, LV_EVENT_VALUE_CHANGED, (void *)0);
                                    add_style_checkbox_config(obj);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Sound mute");
                                }
                                {
                                    // ChbMute
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    objects.chb_mute = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 64, 32);
                                    lv_obj_add_event_cb(obj, action_mute_sound, LV_EVENT_VALUE_CHANGED, (void *)0);
                                    add_style_checkbox_config(obj);
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Input");
                    add_style_tab_config(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(50), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Delay");
                                }
                                {
                                    // LblDelay
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl_delay = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(50), LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "100 ms");
                                }
                                {
                                    // SldDelay
                                    lv_obj_t *obj = lv_slider_create(parent_obj);
                                    objects.sld_delay = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 16);
                                    lv_slider_set_range(obj, 2, 20);
                                    lv_slider_set_value(obj, 10, LV_ANIM_OFF);
                                    lv_obj_add_event_cb(obj, action_change_delay, LV_EVENT_VALUE_CHANGED, (void *)0);
                                    add_style_slider_config(obj);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Connectivity");
                                }
                                {
                                    // DdConnectivity
                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                    objects.dd_connectivity = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 38);
                                    lv_dropdown_set_options(obj, "Bluetooth\nUSB");
                                    lv_dropdown_set_selected(obj, 0);
                                    lv_obj_add_event_cb(obj, action_change_connectivity, LV_EVENT_VALUE_CHANGED, (void *)0);
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 38);
                                    lv_obj_add_event_cb(obj, action_keyboard_demo, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_std(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text(obj, "Send \"hello\"");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Keymap");
                                }
                                {
                                    // DdKeymap
                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                    objects.dd_keymap = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 38);
                                    lv_dropdown_set_options(obj, "WASD\nArrows");
                                    lv_dropdown_set_selected(obj, 0);
                                    lv_obj_add_event_cb(obj, action_change_keymap, LV_EVENT_VALUE_CHANGED, (void *)0);
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 38);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_config_2_setup, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_config_2_about, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_info, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 38);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_config_2_reset, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_reset, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, action_restart_device, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_restart, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_config();
}

void tick_screen_config() {
}

void create_screen_game() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.game = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BtnReinforce
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_reinforce = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_rf2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnResupply
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_resupply = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_res2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnSOS
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_sos = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_sos2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnRearm
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_rearm = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_er2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // CustomStratagem1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
                {
                    // CustomStratagem2
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
                {
                    // CustomStratagem3
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
                {
                    // CustomStratagem4
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(67), LV_SIZE_CONTENT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // CustomStratagem5
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
                {
                    // CustomStratagem6
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_user, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                }
                {
                    // BtnSEAF
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_seaf = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_seaf1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnHellbomb
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_hellbomb = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, action_trigger_stratagem_std, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_hb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, action_game_2_setup, LV_EVENT_CLICKED, (void *)0);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, 76, 76);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ImgBTdis
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.img_btdis = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 36, 36);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_btdis, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ImgBTcon
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.img_btcon = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 36, 36);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_btcon, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ImgUSBdis
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.img_us_bdis = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 36, 36);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_us_bdis, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ImgUSBcon
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.img_us_bcon = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 36, 36);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_us_bcon, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_game();
}

void tick_screen_game() {
}

void create_screen_about() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.about = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(obj, 31, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj7 = obj;
                    lv_obj_set_pos(obj, 8, 8);
                    lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffdf00), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "HD2 Macropad");
                }
                {
                    // LblVersion
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_version = obj;
                    lv_obj_set_pos(obj, -8, 8);
                    lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffdf00), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "vX.X.X");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Copyright (C) 2024 All rights reserved.\nThis software is released under the Creative Commons Attribution-NonCommercial 4.0 International Public License.");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "For more information please visit:\ngithub.com/unic8s/hd2_macropad");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "A project by\nOliver G.\t@Gore66\nErik L.\t\t\t@unic8s");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, action_about_2_config, LV_EVENT_CLICKED, (void *)0);
            add_style_button_std(obj);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_qrcode_create(parent_obj, 160, lv_color_hex(0xff000000), lv_color_hex(0xffe2f5fe));
            lv_obj_set_pos(obj, -8, -8);
            lv_obj_set_size(obj, 160, 160);
            lv_qrcode_update(obj, "github.com/unic8s/hd2_macropad", 30);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_about();
}

void tick_screen_about() {
}

void create_screen_reset() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.reset = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 200, LV_PCT(38));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -15, -45);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Reset device to\ndefault settings?");
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, action_reset_confirm, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_yes, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, action_reset_cancel, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_no, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_reset();
}

void tick_screen_reset() {
}

void change_color_theme(uint32_t theme_index) {
    active_theme_index = theme_index;
    
    lv_style_set_border_color(get_style_button_std_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_slider_config_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_slider_config_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_slider_config_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_checkbox_config_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_checkbox_config_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_checkbox_config_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_checkbox_config_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_obj_set_style_border_color(objects.weapons_mg, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_hmg, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_sw, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_ac, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_amr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_rg, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_lc, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_qc, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_at, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_e, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_sg, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_arl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_c, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_eat, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_en, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_rr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_spr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_wsp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_gl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_de, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_ste, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_ft, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_bsb, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_sgp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_ds, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gd, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdb, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdk, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_sup, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_ph, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_jp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_hp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_wp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_frv, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_pe, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_ee, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_otf, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_ss, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_mgs, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_gs, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_acs, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_hmge, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_ate, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_fs, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_ms, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_rs, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_ems, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.sentry_ls, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_gm, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_tt, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_sgr, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_apm, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_atm, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_im, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.ground_gb, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike120, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike380, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_ors, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_ogb, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_oas, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_ol, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_ops, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_owb, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_oes, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_onb, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_ogs, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.strike_oss, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle110, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle500, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle_a, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle_cb, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle_sr, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle_na, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.eagle_ss, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset2, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.msg_label, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.lbl_brightness, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.lbl_delay, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_reinforce, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_resupply, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_sos, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_rearm, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_seaf, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_hellbomb, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj8, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj9, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_invalidate(objects.intro);
    lv_obj_invalidate(objects.setup);
    lv_obj_invalidate(objects.config);
    lv_obj_invalidate(objects.game);
    lv_obj_invalidate(objects.about);
    lv_obj_invalidate(objects.reset);
}

uint32_t theme_colors[1][6] = {
    { 0xffffffff, 0xffffdf00, 0xff679552, 0xff49adc9, 0xffde7b6c, 0xffc9b269 },
};


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_intro,
    tick_screen_setup,
    tick_screen_config,
    tick_screen_game,
    tick_screen_about,
    tick_screen_reset,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_intro();
    create_screen_setup();
    create_screen_config();
    create_screen_game();
    create_screen_about();
    create_screen_reset();
}

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

static void event_handler_cb_intro_intro(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_intro_img_splash(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_setup_tab_view_setup(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_tab_changed(e);
    }
}

static void event_handler_cb_setup_tab_rifle(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_mg(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_hmg(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_sw(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_ac(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_amr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_rg(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_lc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_qc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_at(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_e(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_sg(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_mxg(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_special(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_arl(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_c(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_eat(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_en(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_rr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_eatl(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_spr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_wsp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_gl(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_bfgl(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_de(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_ste(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_ft(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_weapons_dt(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_backpack(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_bsb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_sgp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_ds(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_gd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_gdb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_gdr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_gdk(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_gdhd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_sup(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_ph(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_c4_p(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_jp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_hp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_backpack_wp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_supply(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_frv(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_bmk(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_pe(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_ee(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_otf(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_cqc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_supply_ss(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_sentry(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_mgs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_gs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_acs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_hmge(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_ate(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_fs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_ms(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_rs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_ems(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_sentry_ls(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_ground(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_gm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_tt(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_sgr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_apm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_atm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_im(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_ground_gb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_strike(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike120(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike380(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_ors(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_ogb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_oas(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_ol(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_ops(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_owb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_oes(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_onb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_ogs(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_strike_oss(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_tab_eagle(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle110(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle500(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle_a(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle_cb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle_sr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle_na(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_eagle_ss(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_select_stratagem(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        action_deselect_stratagem(e);
    }
}

static void event_handler_cb_setup_obj16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 111, 0, e);
    }
}

static void event_handler_cb_setup_obj17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 112, 0, e);
    }
}

static void event_handler_cb_setup_obj18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_reset_stratagems(e);
    }
}

static void event_handler_cb_setup_obj19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 114, 0, e);
    }
}

static void event_handler_cb_setup_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 118, 0, e);
    }
}

static void event_handler_cb_preset_btn_preset1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)1;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)1;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_btn_preset2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)2;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)2;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_btn_preset3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)3;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)3;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_btn_preset4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)4;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)4;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_btn_preset5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)5;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)5;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_btn_preset6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SHORT_CLICKED) {
        e->user_data = (void *)6;
        action_get_preset(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        e->user_data = (void *)6;
        action_set_preset(e);
    }
}

static void event_handler_cb_preset_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_preset_btn_preset_image(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 1, e);
    }
}

static void event_handler_cb_preset_obj22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_reset_preset_obj23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_reset_preset_obj24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_image_obj25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_image_obj26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)1;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj27(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)2;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj28(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)3;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj29(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)4;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj30(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)5;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj31(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)6;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj32(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)7;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj33(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)8;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj34(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)9;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj35(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)10;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj36(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)11;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj37(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)12;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj38(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)13;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj39(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)14;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)15;
        action_assign_preset_image(e);
    }
}

static void event_handler_cb_image_obj41(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_game_btn_reinforce(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_btn_resupply(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)1;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_btn_sos(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)2;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_btn_rearm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)3;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_custom_stratagem1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_custom_stratagem2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)1;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_custom_stratagem3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)2;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_custom_stratagem4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)3;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_custom_stratagem5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)4;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_custom_stratagem6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)5;
        action_trigger_stratagem_user(e);
    }
}

static void event_handler_cb_game_btn_seaf(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)5;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_btn_hellbomb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)4;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_game_obj42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_game_obj43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_mission_btn_sssd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)6;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_ud(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)7;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_hbd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)9;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_pd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)11;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_sef(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)8;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_td(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)10;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_sp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)12;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_oif(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)13;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_dfv(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)14;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_cc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)15;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_btn_csd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)16;
        action_trigger_stratagem_base(e);
    }
}

static void event_handler_cb_mission_obj44(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 34, 0, e);
    }
}

static void event_handler_cb_config_tab_view_config(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_tab_changed(e);
    }
}

static void event_handler_cb_config_sld_brightness(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_change_brightness(e);
    }
}

static void event_handler_cb_config_chb_flip(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_flip_screen(e);
    }
}

static void event_handler_cb_config_chb_mute(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_mute_sound(e);
    }
}

static void event_handler_cb_config_sld_delay(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_change_delay(e);
    }
}

static void event_handler_cb_config_dd_connectivity(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_change_connectivity(e);
    }
}

static void event_handler_cb_config_obj45(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_demo(e);
    }
}

static void event_handler_cb_config_dd_keymap(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_change_keymap(e);
    }
}

static void event_handler_cb_config_chb_cooldowns(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_cooldown(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_srp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_ma(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_hc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_zbl(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_lvc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_ss(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_act(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_tsu(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_rls(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_ship_mod_dt(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_set_ship_modules(e);
    }
}

static void event_handler_cb_config_chb_auto_complete(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_auto_complete(e);
    }
}

static void event_handler_cb_config_obj46(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 49, 0, e);
    }
}

static void event_handler_cb_config_obj47(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 50, 0, e);
    }
}

static void event_handler_cb_config_obj48(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 52, 0, e);
    }
}

static void event_handler_cb_config_obj49(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_restart_device(e);
    }
}

static void event_handler_cb_reset_config_obj50(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_reset_config_obj51(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_about_obj52(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_manual_manual_arrow_up(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)1;
        action_manual_execute(e);
    }
}

static void event_handler_cb_manual_manual_arrow_left(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)3;
        action_manual_execute(e);
    }
}

static void event_handler_cb_manual_manual_arrow_right(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)4;
        action_manual_execute(e);
    }
}

static void event_handler_cb_manual_manual_arrow_down(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)2;
        action_manual_execute(e);
    }
}

static void event_handler_cb_manual_obj53(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

void create_screen_intro() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.intro = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_add_event_cb(obj, event_handler_cb_intro_intro, LV_EVENT_ALL, flowState);
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
            lv_obj_add_event_cb(obj, event_handler_cb_intro_img_splash, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE);
        }
        {
            // cntProgress
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.cnt_progress = obj;
            lv_obj_set_pos(obj, 49, 256);
            lv_obj_set_size(obj, 0, 10);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff8eb2b8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_intro();
}

void tick_screen_intro() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_setup() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
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
            lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_view_setup, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // TabRifle
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Rifle");
                    objects.tab_rifle = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_rifle, LV_EVENT_ALL, flowState);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_mg, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_mg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsHMG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_hmg = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_hmg, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hmg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSW
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_sw = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_sw, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sw1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ac = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_ac, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ac1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAMR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_amr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_amr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_amr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsRG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_rg = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_rg, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsLC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_lc = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_lc, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_lc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsQC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_qc = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_qc, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_qc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsAT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_at = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_at, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_at1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_e = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_e, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_sg = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_sg, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsMXG
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_mxg = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_mxg, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_mxg1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSpecial
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Special");
                    objects.tab_special = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_special, LV_EVENT_ALL, flowState);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj0, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // WeaponsARL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_arl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_arl, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_arl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_c = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_c, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_c1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsEAT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_eat = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_eat, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_eat1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsEN
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_en = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_en, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_en1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsRR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_rr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_rr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rr1, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj1, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj2 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 64, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj2, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // WeaponsEATL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_eatl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_eatl, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_eatl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSPR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_spr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_spr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_spr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsWSP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_wsp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_wsp, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_wsp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsGL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_gl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_gl, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj3 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 64, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj3, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // WeaponsBFGL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_bfgl = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_bfgl, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_bfgl1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsDE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_de = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_de, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_de1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsSTE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ste = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_ste, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ste1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsFT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_ft = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_ft, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ft1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // WeaponsDT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.weapons_dt = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_weapons_dt, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_dt1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabBackpack
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Backpack");
                    objects.tab_backpack = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_backpack, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj4, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // BackpackBSB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_bsb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_bsb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_bsb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackSGP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_sgp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_sgp, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sgp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackDS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_ds = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_ds, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ds1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gd = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_gd, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_gdb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj5, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj6 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj6, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // BackpackGDR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_gdr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDK
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdk = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_gdk, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdk1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackGDHD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_gdhd = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_gdhd, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gdhd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackSUP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_sup = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_sup, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sup1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj7 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj7, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // BackpackPH
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_ph = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_ph, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ph1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackC4P
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_c4_p = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_c4_p, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_c4p1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackJP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_jp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_jp, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_jp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackHP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_hp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_hp, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // BackpackWP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.backpack_wp = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_backpack_wp, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_wp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSupply
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Supply");
                    objects.tab_supply = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_supply, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj8 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj8, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SupplyFRV
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_frv = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_frv, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_frv1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyBMK
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_bmk = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_bmk, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_bmk1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyPE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_pe = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_pe, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_pe1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyEE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_ee = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_ee, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ee1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj9 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj9, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SupplyOTF
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_otf = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_otf, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_otf1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplyCQC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_cqc = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_cqc, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_cqc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SupplySS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.supply_ss = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_supply_ss, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ss1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabSentry
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Sentry");
                    objects.tab_sentry = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_sentry, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj10 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj10, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SentryMGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_mgs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_mgs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_mgs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_gs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_gs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryACS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_acs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_acs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_acs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryHMGE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_hmge = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_hmge, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_hmge1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryATE
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ate = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_ate, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ate1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj11 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 19, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj11, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // SentryFS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_fs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_fs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_fs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryMS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ms = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_ms, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ms1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryRS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_rs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_rs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_rs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryEMS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ems = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_ems, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ems1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // SentryLS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.sentry_ls = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_sentry_ls, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ls1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabGround
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Ground");
                    objects.tab_ground = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_ground, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj12 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj12, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // GroundGM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_gm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_gm, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundTT
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_tt = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_tt, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_tt1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundSGR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_sgr = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_sgr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_sgr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundAPM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_apm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_apm, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_apm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj13 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj13, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // GroundATM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_atm = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_atm, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_atm1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundIM
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_im = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_im, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_im1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // GroundGB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ground_gb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_ground_gb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_gb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabStrike
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Strike");
                    objects.tab_strike = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_strike, LV_EVENT_ALL, flowState);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike120, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_1201, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Strike380
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike380 = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike380, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_3801, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeORS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ors = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_ors, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ors1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOGB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ogb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_ogb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ogb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOAS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oas = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_oas, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oas1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOL
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ol = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_ol, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ol1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOPS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ops = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_ops, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ops1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOWB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_owb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_owb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_owb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOES
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oes = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_oes, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oes1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeONB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_onb = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_onb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_onb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOGS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_ogs = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_ogs, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ogs1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // StrikeOSS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.strike_oss = obj;
                            lv_obj_set_pos(obj, -78, -19);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_strike_oss, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_oss1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // TabEagle
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Eagle");
                    objects.tab_eagle = obj;
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_tab_eagle, LV_EVENT_ALL, flowState);
                    add_style_tab_stratagem(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj14 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj14, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // Eagle110
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle110 = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle110, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e1101, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // Eagle500
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle500 = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle500, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_e5001, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleA
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_a = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle_a, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ea1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleCB
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_cb = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle_cb, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ecb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.obj15 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_obj15, LV_EVENT_ALL, flowState);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                        }
                        {
                            // EagleSR
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_sr = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle_sr, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_esr1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleNA
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_na = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle_na, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_ena1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // EagleSS
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.eagle_ss = obj;
                            lv_obj_set_pos(obj, 203, 122);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_setup_eagle_ss, LV_EVENT_ALL, flowState);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                            add_style_button_std(obj);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    objects.obj16 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_obj16, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_config, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, 41, -138);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_obj17, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_arrow_keys, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj18 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_obj18, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj19 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_obj19, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_selection, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    objects.obj20 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_setup_obj20, LV_EVENT_ALL, flowState);
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
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Msg\nBox");
                }
            }
        }
    }
    
    tick_screen_setup();
}

void tick_screen_setup() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_preset() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.preset = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(50), 282);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // BtnPreset1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset1 = obj;
                    lv_obj_set_pos(obj, 110, -136);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset1, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset2
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset2 = obj;
                    lv_obj_set_pos(obj, 70, -117);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset2, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset3
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset3 = obj;
                    lv_obj_set_pos(obj, 30, -117);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset3, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset4
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset4 = obj;
                    lv_obj_set_pos(obj, -10, -117);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset4, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset5
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset5 = obj;
                    lv_obj_set_pos(obj, -50, -117);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset5, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnPreset6
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset6 = obj;
                    lv_obj_set_pos(obj, -90, -117);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset6, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon6, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_preset_obj21, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    // BtnPresetImage
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_preset_image = obj;
                    lv_obj_set_pos(obj, 2, -2);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_btn_preset_image, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
                    add_style_button_std(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_image, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj22 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_preset_obj22, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_preset();
}

void tick_screen_preset() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_reset_preset() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.reset_preset = obj;
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
                    lv_label_set_text(obj, "Delete all presets?");
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj23 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_reset_preset_obj23, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_yes, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj24 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_reset_preset_obj24, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_no, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_reset_preset();
}

void tick_screen_reset_preset() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
}

void create_screen_image() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.image = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_image_obj25, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(90), 282);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj26 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj26, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_conduct_geological_survey, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj27 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj27, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_emergency_evacuation, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj28 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj28, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_enable_e_710_extraction, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj29 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj29, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_eradicate_automaton_forces, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj30 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj30, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_eradicate_terminid_swarm, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj31 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj31, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_evacuate_high_value_assets, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj32 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj32, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_launch_icbm, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj33 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj33, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_retrieve_essential_personnel, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj34 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj34, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_retrieve_valuable_data, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj35 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj35, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_spread_democracy, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj36 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj36, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_terminate_illegal_broadcast, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj37 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj37, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_mission_upload_escape_pod_data, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj38 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj38, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_faction_terminid, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj39 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj39, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_faction_automaton, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj40 = obj;
                    lv_obj_set_pos(obj, -169, -97);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_image_obj40, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_faction_illuminate, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_image_obj41, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_bg_img_src(obj, &img_icon_clear, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_image();
}

void tick_screen_image() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
}

void create_screen_game() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
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
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_reinforce, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_rf2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnResupply
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_resupply = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_resupply, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_res2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnSOS
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_sos = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_sos, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_sos2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnRearm
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_rearm = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_rearm, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_er2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // CustomStratagem1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem1, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
                }
                {
                    // CustomStratagem2
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem2, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown2 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
                }
                {
                    // CustomStratagem3
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem3, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown3 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
                }
                {
                    // CustomStratagem4
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 116, 116);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem4, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
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
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem5, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
                }
                {
                    // CustomStratagem6
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.custom_stratagem6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_custom_stratagem6, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelCooldown6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label_cooldown6 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label_cooldown(obj);
                            lv_label_set_text(obj, "0:00");
                        }
                    }
                }
                {
                    // BtnSEAF
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_seaf = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_seaf, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_seaf1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // BtnHellbomb
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_hellbomb = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_btn_hellbomb, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_hb1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_game_obj42, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_flag, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_game_obj43, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ImgConnection2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.img_connection2 = obj;
            lv_obj_set_pos(obj, -2, -43);
            lv_obj_set_size(obj, 36, 36);
            lv_obj_set_style_bg_img_src(obj, &img_btdis, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_game();
}

void tick_screen_game() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
}

void create_screen_mission() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.mission = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(70), 282);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnSSSD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_sssd = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_sssd, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_ud1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj54 = obj;
                                    lv_obj_set_pos(obj, 201, 20);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "SSSD");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj55 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Delivery");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnUD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_ud = obj;
                            lv_obj_set_pos(obj, 223, -29);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_ud, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_ud1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj56 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Upload");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj57 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Data");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnHBD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_hbd = obj;
                            lv_obj_set_pos(obj, 110, -136);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_hbd, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_hbd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj58 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Hive Br.");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj59 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Drill");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnPD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_pd = obj;
                            lv_obj_set_pos(obj, 186, -14);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_pd, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_hbd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj60 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Prosp.");
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj61 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 191, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Drill");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 38, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnSEF
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_sef = obj;
                            lv_obj_set_pos(obj, 223, -29);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_sef, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_sef1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnTD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_td = obj;
                            lv_obj_set_pos(obj, 223, -29);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_td, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_td1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnSP
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_sp = obj;
                            lv_obj_set_pos(obj, 223, -29);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_sp, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_sp1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 38, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnOIF
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_oif = obj;
                            lv_obj_set_pos(obj, 110, -136);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_oif, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_oif1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnDFV
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_dfv = obj;
                            lv_obj_set_pos(obj, 110, -136);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_dfv, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_dfv1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnCC
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_cc = obj;
                            lv_obj_set_pos(obj, 110, -136);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_cc, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_cc1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // BtnCSD
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.btn_csd = obj;
                            lv_obj_set_pos(obj, 110, -136);
                            lv_obj_set_size(obj, 76, 76);
                            lv_obj_add_event_cb(obj, event_handler_cb_mission_btn_csd, LV_EVENT_ALL, flowState);
                            add_style_button_std(obj);
                            lv_obj_set_style_bg_img_src(obj, &img_csd1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, -2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_mission_obj44, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_mission();
}

void tick_screen_mission() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
}

void create_screen_config() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
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
            lv_obj_add_event_cb(obj, event_handler_cb_config_tab_view_config, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Display / Audio");
                    objects.obj62 = obj;
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
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_sld_brightness, LV_EVENT_ALL, flowState);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_chb_flip, LV_EVENT_ALL, flowState);
                                    add_style_switch_config(obj);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_chb_mute, LV_EVENT_ALL, flowState);
                                    add_style_switch_config(obj);
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
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffdf00), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_sld_delay, LV_EVENT_ALL, flowState);
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
                            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_dd_connectivity, LV_EVENT_ALL, flowState);
                                }
                                {
                                    // ImgConnection1
                                    lv_obj_t *obj = lv_img_create(parent_obj);
                                    objects.img_connection1 = obj;
                                    lv_obj_set_pos(obj, -2, -42);
                                    lv_obj_set_size(obj, 36, 36);
                                    lv_obj_set_style_bg_img_src(obj, &img_btdis, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.obj45 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 38);
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_obj45, LV_EVENT_ALL, flowState);
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
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_dd_keymap, LV_EVENT_ALL, flowState);
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Cooldowns");
                    add_style_tab_config(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(47), LV_SIZE_CONTENT);
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
                                    lv_obj_set_size(obj, LV_PCT(92), LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Show timers");
                                }
                                {
                                    // ChbCooldowns
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    objects.chb_cooldowns = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 64, 32);
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_chb_cooldowns, LV_EVENT_ALL, flowState);
                                    add_style_switch_config(obj);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(49), LV_PCT(100));
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Ship modules");
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 184);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // ChbShipMod_SRP
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_srp = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Streaml. Req. Process");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_srp, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_MA
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_ma = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Morale Augmentation");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_ma, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_HC
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_hc = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Hand Carts");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_hc, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_ZBL
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_zbl = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Zero-G Breech Load.");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_zbl, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_LVC
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_lvc = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Liquid-Vent. Cockpit");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_lvc, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_SS
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_ss = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Synthetic Suppl.");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_ss, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_ACT
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_act = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Adv. Crew Train.");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_act, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_TSU
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_tsu = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Hand Carts");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_tsu, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_RLS
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_rls = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Synthetic Suppl.");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_rls, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                        {
                                            // ChbShipMod_DT
                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                            objects.chb_ship_mod_dt = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_checkbox_set_text(obj, "Dyn. Tracking");
                                            lv_obj_add_event_cb(obj, event_handler_cb_config_chb_ship_mod_dt, LV_EVENT_ALL, flowState);
                                            add_style_checkbox_config(obj);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Misc.");
                    add_style_tab_config(obj);
                    {
                        lv_obj_t *parent_obj = obj;
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
                                    lv_label_set_text(obj, "Auto-complete for manual");
                                }
                                {
                                    // ChbAutoComplete
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    objects.chb_auto_complete = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 64, 32);
                                    lv_obj_add_event_cb(obj, event_handler_cb_config_chb_auto_complete, LV_EVENT_ALL, flowState);
                                    add_style_switch_config(obj);
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
                    objects.obj46 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_config_obj46, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj47 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_config_obj47, LV_EVENT_ALL, flowState);
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
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj48 = obj;
                    lv_obj_set_pos(obj, 3, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_config_obj48, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_reset, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj49 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, LV_PCT(100));
                    lv_obj_add_event_cb(obj, event_handler_cb_config_obj49, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_restart, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_config();
}

void tick_screen_config() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
}

void create_screen_reset_config() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.reset_config = obj;
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
                    objects.obj50 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_reset_config_obj50, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_yes, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj51 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_reset_config_obj51, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, &img_icon_no, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_reset_config();
}

void tick_screen_reset_config() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
}

void create_screen_about() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
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
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj63 = obj;
                    lv_obj_set_pos(obj, 8, 8);
                    lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "HD2 Macropad");
                }
                {
                    // LblVersion
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lbl_version = obj;
                    lv_obj_set_pos(obj, -8, 8);
                    lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff666666), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "vX.X.X");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 24);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj64 = obj;
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff999999), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Copyright (C) 2024 - 2026 All rights reserved.");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 16);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "This software is released under the Creative Commons Attribution-NonCommercial 4.0 International Public License.");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 24);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "For more information please visit:");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj65 = obj;
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "github.com/unic8s/hd2_macropad");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 24);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "A project by");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj66 = obj;
                    lv_obj_set_pos(obj, 54, 113);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Oliver G.\t@Gore66\nErik L.\t\t\t@unic8s");
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_about_obj52, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_qrcode_create(parent_obj, 152, lv_color_hex(0xff000000), lv_color_hex(0xffe2f5fe));
            lv_obj_set_pos(obj, -12, -12);
            lv_obj_set_size(obj, 152, 152);
            lv_qrcode_update(obj, "https://s.click.aliexpress.com/e/_DneMCLR", 41);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_about();
}

void tick_screen_about() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
}

void create_screen_manual() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.manual = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // manualPreviewItem
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.manual_preview_item = obj;
            lv_obj_set_pos(obj, -4, 4);
            lv_obj_set_size(obj, 116, 116);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 220, LV_SIZE_CONTENT);
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
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, -4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, -4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -74, -4);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
                {
                    // ManualArrowUp
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.manual_arrow_up = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_manual_manual_arrow_up, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_stratagem_arrow_up2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -74, -4);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
                {
                    // ManualArrowLeft
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.manual_arrow_left = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_manual_manual_arrow_left, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_stratagem_arrow_left2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -74, -4);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
                {
                    // ManualArrowRight
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.manual_arrow_right = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_manual_manual_arrow_right, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_stratagem_arrow_right2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -90, -119);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
                {
                    // ManualArrowDown
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.manual_arrow_down = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 76, 76);
                    lv_obj_add_event_cb(obj, event_handler_cb_manual_manual_arrow_down, LV_EVENT_ALL, flowState);
                    add_style_button_std(obj);
                    lv_obj_set_style_bg_img_src(obj, &img_stratagem_arrow_down2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 8, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 32);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ManualCmd1
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd2
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd3
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd4
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd5
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd6
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd7
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                }
                {
                    // ManualCmd8
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ManualCmd9
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.manual_cmd9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_stratagem_arrow_up1);
                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj53 = obj;
            lv_obj_set_pos(obj, 2, -2);
            lv_obj_set_size(obj, 76, 38);
            lv_obj_add_event_cb(obj, event_handler_cb_manual_obj53, LV_EVENT_ALL, flowState);
            add_style_button_std(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_img_src(obj, &img_icon_back, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_manual();
}

void tick_screen_manual() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
}

void change_color_theme(uint32_t theme_index) {
    lv_style_set_border_color(get_style_button_std_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_slider_config_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_slider_config_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_slider_config_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_switch_config_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_switch_config_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_border_color(get_style_switch_config_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    
    lv_style_set_border_color(get_style_switch_config_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_text_color(get_style_checkbox_config_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    
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
    
    lv_obj_set_style_border_color(objects.weapons_mxg, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_arl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_c, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_eat, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_en, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_rr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_eatl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_spr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_wsp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_gl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_bfgl, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_de, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_ste, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_ft, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.weapons_dt, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_bsb, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_sgp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_ds, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gd, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdb, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdr, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdk, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_gdhd, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_sup, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_ph, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_c4_p, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_jp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_hp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.backpack_wp, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_frv, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_bmk, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_pe, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_ee, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_otf, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.supply_cqc, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
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
    
    lv_obj_set_style_text_color(objects.msg_label, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset2, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset3, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset4, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset5, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_preset6, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj23, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj24, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_reinforce, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_resupply, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_sos, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_rearm, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_seaf, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_hellbomb, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_sssd, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_ud, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_hbd, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_pd, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_sef, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_td, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_sp, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_oif, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_dfv, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_cc, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.btn_csd, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.lbl_brightness, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.lbl_delay, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj50, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_border_color(objects.obj51, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.obj63, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.obj65, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_text_color(objects.obj66, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_invalidate(objects.intro);
    lv_obj_invalidate(objects.setup);
    lv_obj_invalidate(objects.preset);
    lv_obj_invalidate(objects.reset_preset);
    lv_obj_invalidate(objects.image);
    lv_obj_invalidate(objects.game);
    lv_obj_invalidate(objects.mission);
    lv_obj_invalidate(objects.config);
    lv_obj_invalidate(objects.reset_config);
    lv_obj_invalidate(objects.about);
    lv_obj_invalidate(objects.manual);
}

extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Intro", "Setup", "Preset", "ResetPreset", "Image", "Game", "Mission", "Config", "ResetConfig", "About", "Manual" };
static const char *object_names[] = { "intro", "setup", "preset", "reset_preset", "image", "game", "mission", "config", "reset_config", "about", "manual", "img_splash", "tab_view_setup", "tab_rifle", "weapons_mg", "weapons_hmg", "weapons_sw", "weapons_ac", "weapons_amr", "weapons_rg", "weapons_lc", "weapons_qc", "weapons_at", "weapons_e", "weapons_sg", "weapons_mxg", "tab_special", "obj0", "weapons_arl", "weapons_c", "weapons_eat", "weapons_en", "weapons_rr", "obj1", "obj2", "weapons_eatl", "weapons_spr", "weapons_wsp", "weapons_gl", "obj3", "weapons_bfgl", "weapons_de", "weapons_ste", "weapons_ft", "weapons_dt", "tab_backpack", "obj4", "backpack_bsb", "backpack_sgp", "backpack_ds", "backpack_gd", "backpack_gdb", "obj5", "obj6", "backpack_gdr", "backpack_gdk", "backpack_gdhd", "backpack_sup", "obj7", "backpack_ph", "backpack_c4_p", "backpack_jp", "backpack_hp", "backpack_wp", "tab_supply", "obj8", "supply_frv", "supply_bmk", "supply_pe", "supply_ee", "obj9", "supply_otf", "supply_cqc", "supply_ss", "tab_sentry", "obj10", "sentry_mgs", "sentry_gs", "sentry_acs", "sentry_hmge", "sentry_ate", "obj11", "sentry_fs", "sentry_ms", "sentry_rs", "sentry_ems", "sentry_ls", "tab_ground", "obj12", "ground_gm", "ground_tt", "ground_sgr", "ground_apm", "obj13", "ground_atm", "ground_im", "ground_gb", "tab_strike", "strike120", "strike380", "strike_ors", "strike_ogb", "strike_oas", "strike_ol", "strike_ops", "strike_owb", "strike_oes", "strike_onb", "strike_ogs", "strike_oss", "tab_eagle", "obj14", "eagle110", "eagle500", "eagle_a", "eagle_cb", "obj15", "eagle_sr", "eagle_na", "eagle_ss", "obj16", "obj17", "obj18", "obj19", "obj20", "btn_preset1", "btn_preset2", "btn_preset3", "btn_preset4", "btn_preset5", "btn_preset6", "obj21", "btn_preset_image", "obj22", "obj23", "obj24", "obj25", "obj26", "obj27", "obj28", "obj29", "obj30", "obj31", "obj32", "obj33", "obj34", "obj35", "obj36", "obj37", "obj38", "obj39", "obj40", "obj41", "btn_reinforce", "btn_resupply", "btn_sos", "btn_rearm", "custom_stratagem1", "custom_stratagem2", "custom_stratagem3", "custom_stratagem4", "custom_stratagem5", "custom_stratagem6", "btn_seaf", "btn_hellbomb", "obj42", "obj43", "btn_sssd", "btn_ud", "btn_hbd", "btn_pd", "btn_sef", "btn_td", "btn_sp", "btn_oif", "btn_dfv", "btn_cc", "btn_csd", "obj44", "tab_view_config", "sld_brightness", "chb_flip", "chb_mute", "sld_delay", "dd_connectivity", "obj45", "dd_keymap", "chb_cooldowns", "chb_ship_mod_srp", "chb_ship_mod_ma", "chb_ship_mod_hc", "chb_ship_mod_zbl", "chb_ship_mod_lvc", "chb_ship_mod_ss", "chb_ship_mod_act", "chb_ship_mod_tsu", "chb_ship_mod_rls", "chb_ship_mod_dt", "chb_auto_complete", "obj46", "obj47", "obj48", "obj49", "obj50", "obj51", "obj52", "manual_arrow_up", "manual_arrow_left", "manual_arrow_right", "manual_arrow_down", "obj53", "cnt_progress", "bar_amount", "label_amount", "msg_box", "msg_label", "label_cooldown1", "label_cooldown2", "label_cooldown3", "label_cooldown4", "label_cooldown5", "label_cooldown6", "img_connection2", "obj54", "obj55", "obj56", "obj57", "obj58", "obj59", "obj60", "obj61", "obj62", "lbl_brightness", "lbl_delay", "img_connection1", "obj63", "lbl_version", "obj64", "obj65", "obj66", "manual_preview_item", "manual_cmd1", "manual_cmd2", "manual_cmd3", "manual_cmd4", "manual_cmd5", "manual_cmd6", "manual_cmd7", "manual_cmd8", "manual_cmd9" };
static const char *style_names[] = { "ButtonStd", "TabStratagem", "TabConfig", "SliderConfig", "SwitchConfig", "LabelCooldown", "CheckboxConfig" };
static const char *theme_names[] = { "Default" };

uint32_t theme_colors[1][6] = {
    { 0xffffffff, 0xffffdf00, 0xff679552, 0xff49adc9, 0xffde7b6c, 0xffc9b269 },
};


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_intro,
    tick_screen_setup,
    tick_screen_preset,
    tick_screen_reset_preset,
    tick_screen_image,
    tick_screen_game,
    tick_screen_mission,
    tick_screen_config,
    tick_screen_reset_config,
    tick_screen_about,
    tick_screen_manual,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    eez_flow_init_themes(theme_names, sizeof(theme_names) / sizeof(const char *), change_color_theme);
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_intro();
    create_screen_setup();
    create_screen_preset();
    create_screen_reset_preset();
    create_screen_image();
    create_screen_game();
    create_screen_mission();
    create_screen_config();
    create_screen_reset_config();
    create_screen_about();
    create_screen_manual();
}

#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *intro;
    lv_obj_t *setup;
    lv_obj_t *config;
    lv_obj_t *game;
    lv_obj_t *about;
    lv_obj_t *reset;
    lv_obj_t *tab_rifle;
    lv_obj_t *weapons_mg;
    lv_obj_t *weapons_hmg;
    lv_obj_t *weapons_sw;
    lv_obj_t *weapons_ac;
    lv_obj_t *weapons_amr;
    lv_obj_t *weapons_rg;
    lv_obj_t *weapons_lc;
    lv_obj_t *weapons_qc;
    lv_obj_t *weapons_at;
    lv_obj_t *weapons_e;
    lv_obj_t *weapons_sg;
    lv_obj_t *tab_special;
    lv_obj_t *weapons_arl;
    lv_obj_t *weapons_c;
    lv_obj_t *weapons_eat;
    lv_obj_t *weapons_en;
    lv_obj_t *weapons_rr;
    lv_obj_t *weapons_spr;
    lv_obj_t *weapons_wsp;
    lv_obj_t *weapons_gl;
    lv_obj_t *weapons_de;
    lv_obj_t *weapons_ste;
    lv_obj_t *weapons_ft;
    lv_obj_t *tab_backpack;
    lv_obj_t *backpack_bsb;
    lv_obj_t *backpack_sgp;
    lv_obj_t *backpack_ds;
    lv_obj_t *backpack_gd;
    lv_obj_t *backpack_gdb;
    lv_obj_t *backpack_gdr;
    lv_obj_t *backpack_gdk;
    lv_obj_t *backpack_sup;
    lv_obj_t *backpack_ph;
    lv_obj_t *backpack_jp;
    lv_obj_t *backpack_hp;
    lv_obj_t *backpack_wp;
    lv_obj_t *tab_supply;
    lv_obj_t *supply_frv;
    lv_obj_t *supply_pe;
    lv_obj_t *supply_ee;
    lv_obj_t *supply_otf;
    lv_obj_t *supply_ss;
    lv_obj_t *tab_sentry;
    lv_obj_t *obj0;
    lv_obj_t *sentry_mgs;
    lv_obj_t *sentry_gs;
    lv_obj_t *sentry_acs;
    lv_obj_t *sentry_hmge;
    lv_obj_t *sentry_ate;
    lv_obj_t *obj1;
    lv_obj_t *sentry_fs;
    lv_obj_t *sentry_ms;
    lv_obj_t *sentry_rs;
    lv_obj_t *sentry_ems;
    lv_obj_t *sentry_ls;
    lv_obj_t *tab_ground;
    lv_obj_t *obj2;
    lv_obj_t *ground_gm;
    lv_obj_t *ground_tt;
    lv_obj_t *ground_sgr;
    lv_obj_t *ground_apm;
    lv_obj_t *obj3;
    lv_obj_t *ground_atm;
    lv_obj_t *ground_im;
    lv_obj_t *ground_gb;
    lv_obj_t *tab_strike;
    lv_obj_t *strike120;
    lv_obj_t *strike380;
    lv_obj_t *strike_ors;
    lv_obj_t *strike_ogb;
    lv_obj_t *strike_oas;
    lv_obj_t *strike_ol;
    lv_obj_t *strike_ops;
    lv_obj_t *strike_owb;
    lv_obj_t *strike_oes;
    lv_obj_t *strike_onb;
    lv_obj_t *strike_ogs;
    lv_obj_t *strike_oss;
    lv_obj_t *tab_eagle;
    lv_obj_t *obj4;
    lv_obj_t *eagle110;
    lv_obj_t *eagle500;
    lv_obj_t *eagle_a;
    lv_obj_t *eagle_cb;
    lv_obj_t *obj5;
    lv_obj_t *eagle_sr;
    lv_obj_t *eagle_na;
    lv_obj_t *eagle_ss;
    lv_obj_t *img_splash;
    lv_obj_t *tab_view_setup;
    lv_obj_t *btn_preset1;
    lv_obj_t *btn_preset2;
    lv_obj_t *bar_amount;
    lv_obj_t *label_amount;
    lv_obj_t *msg_box;
    lv_obj_t *msg_label;
    lv_obj_t *tab_view_config;
    lv_obj_t *obj6;
    lv_obj_t *lbl_brightness;
    lv_obj_t *sld_brightness;
    lv_obj_t *chb_flip;
    lv_obj_t *chb_mute;
    lv_obj_t *lbl_delay;
    lv_obj_t *sld_delay;
    lv_obj_t *dd_connectivity;
    lv_obj_t *dd_keymap;
    lv_obj_t *btn_reinforce;
    lv_obj_t *btn_resupply;
    lv_obj_t *btn_sos;
    lv_obj_t *btn_rearm;
    lv_obj_t *custom_stratagem1;
    lv_obj_t *custom_stratagem2;
    lv_obj_t *custom_stratagem3;
    lv_obj_t *custom_stratagem4;
    lv_obj_t *custom_stratagem5;
    lv_obj_t *custom_stratagem6;
    lv_obj_t *btn_seaf;
    lv_obj_t *btn_hellbomb;
    lv_obj_t *img_connection;
    lv_obj_t *obj7;
    lv_obj_t *lbl_version;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_INTRO = 1,
    SCREEN_ID_SETUP = 2,
    SCREEN_ID_CONFIG = 3,
    SCREEN_ID_GAME = 4,
    SCREEN_ID_ABOUT = 5,
    SCREEN_ID_RESET = 6,
};

void create_screen_intro();
void tick_screen_intro();

void create_screen_setup();
void tick_screen_setup();

void create_screen_config();
void tick_screen_config();

void create_screen_game();
void tick_screen_game();

void create_screen_about();
void tick_screen_about();

void create_screen_reset();
void tick_screen_reset();

enum Themes {
    THEME_ID_DEFAULT,
};
enum Colors {
    COLOR_ID_COLOR_THEME,
    COLOR_ID_COLOR_ACTIVE,
    COLOR_ID_SG_GREEN,
    COLOR_ID_SG_BLUE,
    COLOR_ID_SG_RED,
    COLOR_ID_SG_BROWN,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[1][6];
extern uint32_t active_theme_index;

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/
#ifndef STRATATGEMS
#define STRATATGEMS

#include <esp_system.h>

// Identifiers for inputs (UP/DOWN/LEFT/RIGHT)
// DO NOT EDIT - If you want to change assignments please have a look into "keymaps.c"
#define INPUT_UP 1
#define INPUT_DOWN 2
#define INPUT_LEFT 3
#define INPUT_RIGHT 4

// Map for strategem types to specific sound files
#define SOUND_BACKPACK 0
#define SOUND_BOT 1
#define SOUND_EAGLE 2
#define SOUND_MINES 3
#define SOUND_MORTAR 4
#define SOUND_ORBITAL 5
#define SOUND_SHIELD 6
#define SOUND_SENTRY 7
#define SOUND_WEAPON 8

// Available sound file list on SD card
char *soundFiles[] = {
    "S:assets/sound/bkpk.wav",   // 0 backpack
    "S:assets/sound/bot.wav",    // 1 bot
    "S:assets/sound/eagstk.wav", // 2 eagle strike
    "S:assets/sound/min.wav",    // 3 mines
    "S:assets/sound/mrt.wav",    // 4 mortar
    "S:assets/sound/orbstk.wav", // 5 orbital strike
    "S:assets/sound/shd.wav",    // 6 shield
    "S:assets/sound/snt.wav",    // 7 sentry
    "S:assets/sound/weap.wav",   // 8 advanced weapon
};

struct stratagem
{
    uint8_t sequence[8];
    uint8_t sound;
    const ui_theme_variable_t *color;
    const lv_img_dsc_t *imgHiRes;
};

struct stratagem strategems[] = {
    // 0
    // MG-43 Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_mg2_png},
    // 1
    // APW-1 Anti-Materiel Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_amr2_png},

    // 2
    // M-105 Stalwart
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_sw2_png},

    // 3
    // EAT-17 Expendable Anti-tank
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_eat2_png},

    // 4
    // MLS-4X Commando
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_c2_png},

    // 5
    // GR-8 Recoilless Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_rr2_png},

    // 6
    // FLAM-40 Flamethrower
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ft2_png},

    // 7
    // AC-8 Autocannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_RIGHT, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ac2_png},

    // 8
    // MG-206 Heavy Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_hmg2_png},

    // 9
    // RS-422 Railgun
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_rg2_png},

    // 10
    // FAF-14 Spear Launcher
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_spr2_png},

    // 11
    // GL-21 Grenade Launcher
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_gl2_png},

    // 12
    // LAS-98 Laser Cannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_lc2_png},

    // 13
    // ARC-3 Arc Thrower
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_LEFT, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_at2_png},

    // 14
    // LAS-99 Quasar Cannon
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_qc2_png},

    // 15
    // RL-77 Airburst Rocket Launcher
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_arl2_png},

    // 16
    // TX-41 Sterilizer
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_LEFT, 0, 0, 0},
        SOUND_WEAPON,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ste2_png},

    // 17
    // LIFT-850 Jump Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_jp2_png},

    // 18
    // B-1 Supply Pack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_sp2_png},

    // 19
    // SH-20 Ballistic Shield Backpack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_bsb2_png},

    // 20
    // SH-32 Shield Generator Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_sgp2_png},

    // 21
    // AX/AR-23 "Guard Dog"
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_gd2_png},

    // 22
    // AX/LAS-5 "Guard Dog" Rover
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_gdr2_png},

    // 23
    // AX/TX-13 "Guard Dog" Dog Breath
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_UP, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_gdb2_png},

    // 24
    // EXO-45 Patriot Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0},
        SOUND_BOT,
        _ui_theme_color_sgBlue,
        &ui_img_sg_pe2_png},

    // 25
    // EXO-49 Emancipator Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_UP, 0},
        SOUND_BOT,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ee2_png},

    // 26
    // E/MG-101 HMG Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_hmge2_png},

    // 27
    // FX-12 Shield Generator Relay
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SOUND_SHIELD,
        _ui_theme_color_sgGreen,
        &ui_img_sg_sgr2_png},

    // 28
    // A/ARC-3 Tesla Tower
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SOUND_SHIELD,
        _ui_theme_color_sgGreen,
        &ui_img_sg_tt2_png},

    // 29
    // MD-6 Anti-Personnel Minefield
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        SOUND_MINES,
        _ui_theme_color_sgGreen,
        &ui_img_sg_apm2_png},

    // 30
    // MD-I4 Incendiary Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0},
        SOUND_MINES,
        _ui_theme_color_sgGreen,
        &ui_img_sg_im2_png},

    // 31
    // MD-17 Anti-Tank Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        SOUND_MINES,
        _ui_theme_color_sgGreen,
        &ui_img_sg_atm2_png},

    // 32
    // A/MG-43 Machine Gun Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_mgs2_png},

    // 33
    // A/G-16 Gatling Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_gs2_png},

    // 34
    // A/M-12 Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        SOUND_MORTAR,
        _ui_theme_color_sgGreen,
        &ui_img_sg_ms2_png},

    // 35
    // A/AC-8 Autocannon Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_UP, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_acs2_png},

    // 36
    // A/MLS-4X Rocket Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_rs2_png},

    // 37
    // A/M-23 EMS Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SOUND_MORTAR,
        _ui_theme_color_sgGreen,
        &ui_img_sg_ems2_png},

    // 38
    // Orbital Gatling Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_ogb2_png},

    // 39
    // Orbital Airburst Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_oas2_png},

    // 40
    // Orbital 120MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_1202_png},

    // 41
    // Orbital 380MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_3802_png},

    // 42
    // Orbital Walking Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_owb2_png},

    // 43
    // Orbital Laser
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_ol2_png},

    // 44
    // Orbital Railcannon Strike
    {
        {INPUT_RIGHT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_ors2_png},

    // 45
    // Orbital Precision Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_ops2_png},

    // 46
    // Orbital Gas Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_ogs2_png},

    // 47
    // Orbital EMS Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_oes2_png},

    // 48
    // Orbital Smoke Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_oss2_png},

    // 49
    // Orbital Napalm Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, 0, 0},
        SOUND_ORBITAL,
        _ui_theme_color_sgRed,
        &ui_img_sg_onb2_png},

    // 50
    // Eagle Strafing Run
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_esr2_png},

    // 51
    // Eagle Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_ea2_png},

    // 52
    // Eagle Cluster Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_ecb2_png},

    // 53
    // Eagle Napalm Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_ena2_png},

    // 54
    // Eagle Smoke Strike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_ess2_png},

    // 55
    // Eagle 110MM Rocket Pods
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, 0, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_e1102_png},

    // 56
    // Eagle 500kg Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SOUND_EAGLE,
        _ui_theme_color_sgRed,
        &ui_img_sg_e5002_png},

    // 57
    // Directional Shield
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_UP, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ds2_png},

    // 58
    // Anti-Tank Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0},
        SOUND_MINES,
        _ui_theme_color_sgGreen,
        &ui_img_sg_ate2_png},

    // 59
    // Flame Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0},
        SOUND_SENTRY,
        _ui_theme_color_sgGreen,
        &ui_img_sg_fs2_png},

    // 60
    // Fast Recon Vehicle
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_frv2_png},

    // 61
    // Portable Hellbomb
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_UP, 0, 0, 0},
        SOUND_BACKPACK,
        _ui_theme_color_sgBlue,
        &ui_img_sg_ph2_png},

    // 62
    // Gas Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        SOUND_MINES,
        _ui_theme_color_sgGreen,
        &ui_img_sg_gm2_png}};

#endif

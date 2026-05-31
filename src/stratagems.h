#ifndef _STRATATGEMS
#define _STRATATGEMS

#include <esp_system.h>
#include "ui/ui_assignment.h"
#include "ui/images.h"
#include "main.h"
#include "configuration.h"

// Identifiers for inputs (UP/DOWN/LEFT/RIGHT)
// DO NOT EDIT - If you want to change assignments please have a look into "keymaps.c"
#define INPUT_UP 1
#define INPUT_DOWN 2
#define INPUT_LEFT 3
#define INPUT_RIGHT 4

// Struct for stratagem data (command sequence, sound id, button color, hires icon)
typedef struct
{
    uint8_t sequence[MAX_CMD_LENGTH];
    uint16_t cooldown;
    double callIn;
    uint16_t shipModules;
    char *soundPath;
    const int color;
    const lv_img_dsc_t *imgLoRes;
    const lv_img_dsc_t *imgMeRes;
    const lv_img_dsc_t *imgHiRes;
    enum stratagemType type;
} stratagemItem;

typedef struct
{
    uint8_t sequence[9];
    char *soundPath;
    const lv_img_dsc_t *imgHiRes;
} stratagemBase;

// List of all available stratagems and corresponding data
const stratagemItem strategemItemList[SG_ITEM_AMOUNT] = {
    // 0
    // MG-43 Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_mg3,
        &img_mg1,
        &img_mg2,
        SG_MG},
    // 1
    // APW-1 Anti-Materiel Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_amr3,
        &img_amr1,
        &img_amr2,
        SG_AMR},

    // 2
    // M-105 Stalwart
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_sw3,
        &img_sw1,
        &img_sw2,
        SG_SW},

    // 3
    // EAT-17 Expendable Anti-tank
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        70,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_eat3,
        &img_eat1,
        &img_eat2,
        SG_EAT},

    // 4
    // MLS-4X Commando
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_c3,
        &img_c1,
        &img_c2,
        SG_C},

    // 5
    // GR-8 Recoilless Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_rr3,
        &img_rr1,
        &img_rr2,
        SG_RR},

    // 6
    // FLAM-40 Flamethrower
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_ft3,
        &img_ft1,
        &img_ft2,
        SG_FT},

    // 7
    // AC-8 Autocannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_ac3,
        &img_ac1,
        &img_ac2,
        SG_AC},

    // 8
    // MG-206 Heavy Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_hmg3,
        &img_hmg1,
        &img_hmg2,
        SG_HMG},

    // 9
    // RS-422 Railgun
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_rg3,
        &img_rg1,
        &img_rg2,
        SG_RG},

    // 10
    // FAF-14 Spear Launcher
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_spr3,
        &img_spr1,
        &img_spr2,
        SG_SPR},

    // 11
    // GL-21 Grenade Launcher
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_gl3,
        &img_gl1,
        &img_gl2,
        SG_GL},

    // 12
    // LAS-98 Laser Cannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_lc3,
        &img_lc1,
        &img_lc2,
        SG_LC},

    // 13
    // ARC-3 Arc Thrower
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_LEFT, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_at3,
        &img_at1,
        &img_at2,
        SG_AT},

    // 14
    // LAS-99 Quasar Cannon
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_qc3,
        &img_qc1,
        &img_qc2,
        SG_QC},

    // 15
    // RL-77 Airburst Rocket Launcher
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_arl3,
        &img_arl1,
        &img_arl2,
        SG_ARL},

    // 16
    // TX-41 Sterilizer
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_LEFT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_ste3,
        &img_ste1,
        &img_ste2,
        SG_STE},

    // 17
    // LIFT-850 Jump Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_jp3,
        &img_jp1,
        &img_jp2,
        SG_JP},

    // 18
    // B-1 Supply Pack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_sup3,
        &img_sup1,
        &img_sup2,
        SG_SUP},

    // 19
    // SH-20 Ballistic Shield Backpack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        300,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_bsb3,
        &img_bsb1,
        &img_bsb2,
        SG_BSB},

    // 20
    // SH-32 Shield Generator Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_sgp3,
        &img_sgp1,
        &img_sgp2,
        SG_SGP},

    // 21
    // AX/AR-23 "Guard Dog"
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_gd3,
        &img_gd1,
        &img_gd2,
        SG_GD},

    // 22
    // AX/LAS-5 "Guard Dog" Rover
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_gdr3,
        &img_gdr1,
        &img_gdr2,
        SG_GDR},

    // 23
    // AX/TX-13 "Guard Dog" Dog Breath
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_gdb3,
        &img_gdb1,
        &img_gdb2,
        SG_GDB},

    // 24
    // EXO-45 Patriot Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0, 0},
        600,
        10.5,
        SHIP_MA,
        SND_BOT,
        sgBlue,
        &img_pe3,
        &img_pe1,
        &img_pe2,
        SG_PE},

    // 25
    // EXO-49 Emancipator Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_UP, 0, 0},
        600,
        10.5,
        SHIP_MA,
        SND_BOT,
        sgBlue,
        &img_ee3,
        &img_ee1,
        &img_ee2,
        SG_EE},

    // 26
    // E/MG-101 HMG Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        180,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_SENTRY,
        sgGreen,
        &img_hmge3,
        &img_hmge1,
        &img_hmge2,
        SG_HMGE},

    // 27
    // FX-12 Shield Generator Relay
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        90,
        9.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_SHIELD,
        sgGreen,
        &img_sgr3,
        &img_sgr1,
        &img_sgr2,
        SG_SGR},

    // 28
    // A/ARC-3 Tesla Tower
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        120,
        9.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_SHIELD,
        sgGreen,
        &img_tt3,
        &img_tt1,
        &img_tt2,
        SG_TT},

    // 29
    // MD-6 Anti-Personnel Minefield
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_MINES,
        sgGreen,
        &img_apm3,
        &img_apm1,
        &img_apm2,
        SG_APM},

    // 30
    // MD-I4 Incendiary Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_MINES,
        sgGreen,
        &img_im3,
        &img_im1,
        &img_im2,
        SG_IM},

    // 31
    // MD-17 Anti-Tank Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_MINES,
        sgGreen,
        &img_atm3,
        &img_atm1,
        &img_atm2,
        SG_ATM},

    // 32
    // A/MG-43 Machine Gun Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0},
        90,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_SENTRY,
        sgGreen,
        &img_mgs3,
        &img_mgs1,
        &img_mgs2,
        SG_MGS},

    // 33
    // A/G-16 Gatling Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0, 0, 0},
        150,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_SENTRY,
        sgGreen,
        &img_gs3,
        &img_gs1,
        &img_gs2,
        SG_GS},

    // 34
    // A/M-12 Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0, 0},
        180,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_MORTAR,
        sgGreen,
        &img_ms3,
        &img_ms1,
        &img_ms2,
        SG_MS},

    // 35
    // A/AC-8 Autocannon Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_UP, 0, 0, 0},
        150,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_SENTRY,
        sgGreen,
        &img_acs3,
        &img_acs1,
        &img_acs2,
        SG_ACS},

    // 36
    // A/MLS-4X Rocket Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0, 0},
        150,
        7.75,
        SHIP_MA,
        SND_SENTRY,
        sgGreen,
        &img_rs3,
        &img_rs1,
        &img_rs2,
        SG_RS},

    // 37
    // A/M-23 EMS Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        180,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_MORTAR,
        sgGreen,
        &img_ems3,
        &img_ems1,
        &img_ems2,
        SG_EMS},

    // 38
    // Orbital Gatling Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        70,
        4.75,
        SHIP_MA | SHIP_ZBL | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_ogb3,
        &img_ogb1,
        &img_ogb2,
        SG_OGB},

    // 39
    // Orbital Airburst Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0, 0},
        100,
        4.75,
        SHIP_MA | SHIP_ZBL | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_oas3,
        &img_oas1,
        &img_oas2,
        SG_OAS},

    // 40
    // Orbital 120MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        180,
        4.75,
        SHIP_MA | SHIP_ZBL | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_1203,
        &img_1201,
        &img_1202,
        SG_120},

    // 41
    // Orbital 380MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0, 0},
        240,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_3803,
        &img_3801,
        &img_3802,
        SG_380},

    // 42
    // Orbital Walking Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        240,
        4.75,
        SHIP_MA | SHIP_ZBL | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_owb3,
        &img_owb1,
        &img_owb2,
        SG_OWB},

    // 43
    // Orbital Laser
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0, 0},
        300,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_ol3,
        &img_ol1,
        &img_ol2,
        SG_OL},

    // 44
    // Orbital Railcannon Strike
    {
        {INPUT_RIGHT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        210,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_ors3,
        &img_ors1,
        &img_ors2,
        SG_ORS},

    // 45
    // Orbital Precision Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0, 0, 0},
        90,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_ops3,
        &img_ops1,
        &img_ops2,
        SG_OPS},

    // 46
    // Orbital Gas Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0, 0},
        75,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_ogs3,
        &img_ogs1,
        &img_ogs2,
        SG_OGS},

    // 47
    // Orbital EMS Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0, 0},
        75,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_oes3,
        &img_oes1,
        &img_oes2,
        SG_OES},

    // 48
    // Orbital Smoke Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0, 0},
        100,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_oss3,
        &img_oss1,
        &img_oss2,
        SG_OSS},

    // 49
    // Orbital Napalm Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        240,
        4.75,
        SHIP_MA | SHIP_TSU,
        SND_ORBITAL,
        sgRed,
        &img_onb3,
        &img_onb1,
        &img_onb2,
        SG_ONB},

    // 50
    // Eagle Strafing Run
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_esr3,
        &img_esr1,
        &img_esr2,
        SG_SR},

    // 51
    // Eagle Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_ea3,
        &img_ea1,
        &img_ea2,
        SG_A},

    // 52
    // Eagle Cluster Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_ecb3,
        &img_ecb1,
        &img_ecb2,
        SG_CB},

    // 53
    // Eagle Napalm Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_ena3,
        &img_ena1,
        &img_ena2,
        SG_NA},

    // 54
    // Eagle Smoke Strike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_ess3,
        &img_ess1,
        &img_ess2,
        SG_ESS},

    // 55
    // Eagle 110MM Rocket Pods
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, 0, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_e1103,
        &img_e1101,
        &img_e1102,
        SG_110},

    // 56
    // Eagle 500kg Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_DOWN, 0, 0, 0, 0},
        8,
        4.1,
        SHIP_MA | SHIP_LVC,
        SND_EAGLE,
        sgRed,
        &img_e5003,
        &img_e5001,
        &img_e5002,
        SG_500},

    // 57
    // Directional Shield
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_UP, 0, 0, 0},
        300,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_ds3,
        &img_ds1,
        &img_ds2,
        SG_DS},

    // 58
    // Anti-Tank Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0},
        180,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_MINES,
        sgGreen,
        &img_ate3,
        &img_ate1,
        &img_ate2,
        SG_ATE},

    // 59
    // Flame Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0},
        100,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_SENTRY,
        sgGreen,
        &img_fs3,
        &img_fs1,
        &img_fs2,
        SG_FS},

    // 60
    // Fast Recon Vehicle
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_frv3,
        &img_frv1,
        &img_frv2,
        SG_FRV},

    // 61
    // Portable Hellbomb
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        300,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_ph3,
        &img_ph1,
        &img_ph2,
        SG_PH},

    // 62
    // Gas Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_MINES,
        sgGreen,
        &img_gm3,
        &img_gm1,
        &img_gm2,
        SG_GM},

    // 63
    // StA-X3 W.A.S.P. Launcher
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_wsp3,
        &img_wsp1,
        &img_wsp2,
        SG_WSP},

    // 64
    // E/GL-21 Grenadier Battlement
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        120,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_RLS,
        SND_SENTRY,
        sgGreen,
        &img_gb3,
        &img_gb1,
        &img_gb2,
        SG_GB},

    // 65
    // LIFT-860 Hover Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_hp3,
        &img_hp1,
        &img_hp2,
        SG_HP},

    // 66
    // One True Flag
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0},
        480,
        9.75,
        SHIP_MA,
        SND_BACKPACK,
        sgBlue,
        &img_otf3,
        &img_otf1,
        &img_otf2,
        SG_OTF},

    // 67
    // De-escalator
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_de3,
        &img_de1,
        &img_de2,
        SG_DE},

    // 68
    // Guard Dog K-9
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_gdk3,
        &img_gdk1,
        &img_gdk2,
        SG_GDK},

    // 69
    // PLAS-45 Epoch
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_e3,
        &img_e1,
        &img_e2,
        SG_E},

    // 70
    // A/LAS-98 Laser Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        150,
        7.75,
        SHIP_MA | SHIP_SS | SHIP_DT,
        SND_SENTRY,
        sgGreen,
        &img_ls3,
        &img_ls1,
        &img_ls2,
        SG_LS},

    // 71
    // LIFT-182 Warp Pack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_wp3,
        &img_wp1,
        &img_wp2,
        SG_WP},

    // 72
    // Exandable Napalm
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, 0, 0, 0, 0},
        140,
        9.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_en3,
        &img_en1,
        &img_en2,
        SG_EN},

    // 73
    // Solo Silo
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0, 0, 0},
        180,
        9.75,
        SHIP_MA,
        SND_SUPPLY,
        sgBlue,
        &img_ss3,
        &img_ss1,
        &img_ss2,
        SG_SS},

    // 74
    // Speargun
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0},
        480,
        9.75,
        SHIP_MA,
        SND_BACKPACK,
        sgBlue,
        &img_sg3,
        &img_sg1,
        &img_sg2,
        SG_SG},

    // 75
    // CQC-9 Defoliation Tool
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_dt3,
        &img_dt1,
        &img_dt2,
        SG_DT},

    // 76
    // M-1000 Maxigun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_mxg3,
        &img_mxg1,
        &img_mxg2,
        SG_MXG},

    // 77
    // AX/FLAM-75 "Guard Dog" Hot Dog
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_LEFT, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_gdhd3,
        &img_gdhd1,
        &img_gdhd2,
        SG_GDHD},

    // 78
    // B/MD C4 Pack
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        480,
        9.75,
        SHIP_MA | SHIP_HC,
        SND_BACKPACK,
        sgBlue,
        &img_c4p3,
        &img_c4p1,
        &img_c4p2,
        SG_C4P},

    // 79
    // TD-220 Bastion MK XVI
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_UP},
        780,
        10.5,
        SHIP_MA,
        SND_SUPPLY,
        sgBlue,
        &img_bmk3,
        &img_bmk1,
        &img_bmk2,
        SG_BMK},

    // 80
    // CQC-20 Breaching Hammer
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_UP, 0, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_cqc3,
        &img_cqc1,
        &img_cqc2,
        SG_CQC},

    // 81
    // EAT-411 Leveller
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0},
        140,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_eatl3,
        &img_eatl1,
        &img_eatl2,
        SG_EATL},

    // 82
    // GL-28 Belt-Fed Grenade Launcher
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0},
        480,
        7.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_bfgl3,
        &img_bfgl1,
        &img_bfgl2,
        SG_BFGL},

    // 83
    // B/FLAM-80 Cremator
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0},
        480,
        7.75,
        SHIP_MA | SHIP_SRP,
        SND_WEAPON,
        sgBlue,
        &img_cre3,
        &img_cre1,
        &img_cre2,
        SG_CRE},

    // 84
    // A/GM-17 Gas Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, 0, 0, 0, 0},
        180,
        7.75,
        SHIP_MA | SHIP_SS,
        SND_SENTRY,
        sgGreen,
        &img_gms3,
        &img_gms1,
        &img_gms2,
        SG_GMS},

    // 85
    // MGX-42 Bullet Storm
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        70,
        6.75,
        SHIP_MA,
        SND_WEAPON,
        sgBlue,
        &img_bs3,
        &img_bs1,
        &img_bs2,
        SG_BS},

    // 86
    // EXO-51 Lumberer Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, INPUT_UP, 0, 0},
        600,
        10.5,
        SHIP_MA,
        SND_SUPPLY,
        sgBlue,
        &img_les3,
        &img_les1,
        &img_les2,
        SG_LES},

    // 87
    // EXO-55 Breakthrough Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0},
        600,
        10.5,
        SHIP_MA,
        SND_SUPPLY,
        sgBlue,
        &img_btes3,
        &img_btes1,
        &img_btes2,
        SG_BTES}};

const stratagemBase strategemBaseList[SG_BASE_AMOUNT] = {
    // 0
    // Reinforce
    {
        {INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_LEFT, INPUT_UP, 0, 0, 0, 0},
        SND_REINFORCE,
        &img_rf2},

    // 1
    // Resupply
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0, 0},
        SND_SUPPLY,
        &img_res2},

    // 2
    // SOS
    {
        {INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0, 0},
        SND_SOS,
        &img_sos2},

    // 3
    // Eagle rearm
    {
        {INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        SND_EAGLE_RELOAD,
        &img_er2},

    // 4
    // Hellbomb
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0},
        SND_BACKPACK,
        &img_hb2},

    // 5
    // S.E.A.F.
    {
        {INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0, 0},
        NULL,
        &img_seaf2},

    // 6
    // SSSD Delivery
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        NULL,
        NULL},

    // 7
    // Upload data
    {
        {INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        NULL,
        NULL},

    // 8
    // Super Earth Flag
    {
        {INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0, 0},
        NULL,
        NULL},

    // 9
    // Hive breaker drill
    {
        {INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        NULL,
        NULL},

    // 10
    // Tectonic drill
    {
        {INPUT_UP, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_UP, INPUT_DOWN, 0, 0, 0},
        NULL,
        NULL},

    // 11
    // Prospection drill
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        NULL,
        NULL},

    // 12
    // Seismic probe
    {
        {INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        NULL,
        NULL},

    // 13
    // Orbital illumination flare
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, INPUT_LEFT, 0, 0, 0, 0, 0},
        NULL,
        NULL},

    // 14
    // Dark fluid vessel
    {
        {INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0},
        NULL,
        NULL},

    // 15
    // Cargo container
    {
        {INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        NULL,
        NULL},

    // 16
    // Call in Super Destroyer
    {
        {INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0},
        NULL,
        NULL}};

#endif

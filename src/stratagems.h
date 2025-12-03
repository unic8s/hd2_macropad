#ifndef _STRATATGEMS
#define _STRATATGEMS

#include <esp_system.h>
#include "ui/ui_assignment.h"
#include "ui/images.h"
#include "main.h"

// Identifiers for inputs (UP/DOWN/LEFT/RIGHT)
// DO NOT EDIT - If you want to change assignments please have a look into "keymaps.c"
#define INPUT_UP 1
#define INPUT_DOWN 2
#define INPUT_LEFT 3
#define INPUT_RIGHT 4

// Struct for stratagem data (command sequence, sound id, button color, hires icon)
typedef struct
{
    uint8_t sequence[8];
    char *soundPath;
    const int color;
    const lv_img_dsc_t *imgHiRes;
    enum stratagemType type;
} stratagemItem;

typedef struct
{
    uint8_t sequence[8];
    char *soundPath;
} stratagemBase;

// List of all available stratagems and corresponding data
const stratagemItem strategemItemList[] = {
    // 0
    // MG-43 Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_mg2,
        SG_MG},
    // 1
    // APW-1 Anti-Materiel Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_amr2,
        SG_AMR},

    // 2
    // M-105 Stalwart
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_sw2,
        SG_SW},

    // 3
    // EAT-17 Expendable Anti-tank
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_eat2,
        SG_EAT},

    // 4
    // MLS-4X Commando
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_c2,
        SG_C},

    // 5
    // GR-8 Recoilless Rifle
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_rr2,
        SG_RR},

    // 6
    // FLAM-40 Flamethrower
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_ft2,
        SG_FT},

    // 7
    // AC-8 Autocannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_RIGHT, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_ac2,
        SG_AC},

    // 8
    // MG-206 Heavy Machine Gun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_hmg2,
        SG_HMG},

    // 9
    // RS-422 Railgun
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_rg2,
        SG_RG},

    // 10
    // FAF-14 Spear Launcher
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_spr2,
        SG_SPR},

    // 11
    // GL-21 Grenade Launcher
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_gl2,
        SG_GL},

    // 12
    // LAS-98 Laser Cannon
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_lc2,
        SG_LC},

    // 13
    // ARC-3 Arc Thrower
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_LEFT, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_at2,
        SG_AT},

    // 14
    // LAS-99 Quasar Cannon
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_qc2,
        SG_QC},

    // 15
    // RL-77 Airburst Rocket Launcher
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_arl2,
        SG_ARL},

    // 16
    // TX-41 Sterilizer
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_LEFT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_ste2,
        SG_STE},

    // 17
    // LIFT-850 Jump Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_jp2,
        SG_JP},

    // 18
    // B-1 Supply Pack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_sup2,
        SG_SUP},

    // 19
    // SH-20 Ballistic Shield Backpack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_LEFT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_bsb2,
        SG_BSB},

    // 20
    // SH-32 Shield Generator Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_sgp2,
        SG_SGP},

    // 21
    // AX/AR-23 "Guard Dog"
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_gd2,
        SG_GD},

    // 22
    // AX/LAS-5 "Guard Dog" Rover
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_gdr2,
        SG_GDR},

    // 23
    // AX/TX-13 "Guard Dog" Dog Breath
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_UP, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_gdb2,
        SG_GDB},

    // 24
    // EXO-45 Patriot Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0},
        SND_BOT,
        sgBlue,
        &img_pe2,
        SG_PE},

    // 25
    // EXO-49 Emancipator Exosuit
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_UP, 0},
        SND_BOT,
        sgBlue,
        &img_ee2,
        SG_EE},

    // 26
    // E/MG-101 HMG Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_hmge2,
        SG_HMGE},

    // 27
    // FX-12 Shield Generator Relay
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_SHIELD,
        sgGreen,
        &img_sgr2,
        SG_SGR},

    // 28
    // A/ARC-3 Tesla Tower
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_SHIELD,
        sgGreen,
        &img_tt2,
        SG_TT},

    // 29
    // MD-6 Anti-Personnel Minefield
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        SND_MINES,
        sgGreen,
        &img_apm2,
        SG_APM},

    // 30
    // MD-I4 Incendiary Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0},
        SND_MINES,
        sgGreen,
        &img_im2,
        SG_IM},

    // 31
    // MD-17 Anti-Tank Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0, 0},
        SND_MINES,
        sgGreen,
        &img_atm2,
        SG_ATM},

    // 32
    // A/MG-43 Machine Gun Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_mgs2,
        SG_MGS},

    // 33
    // A/G-16 Gatling Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_gs2,
        SG_GS},

    // 34
    // A/M-12 Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        SND_MORTAR,
        sgGreen,
        &img_ms2,
        SG_MS},

    // 35
    // A/AC-8 Autocannon Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_UP, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_acs2,
        SG_ACS},

    // 36
    // A/MLS-4X Rocket Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, 0, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_rs2,
        SG_RS},

    // 37
    // A/M-23 EMS Mortar Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SND_MORTAR,
        sgGreen,
        &img_ems2,
        SG_EMS},

    // 38
    // Orbital Gatling Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_UP, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_ogb2,
        SG_OGB},

    // 39
    // Orbital Airburst Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_oas2,
        SG_OAS},

    // 40
    // Orbital 120MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_1202,
        SG_120},

    // 41
    // Orbital 380MM HE Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_DOWN, 0},
        SND_ORBITAL,
        sgRed,
        &img_3802,
        SG_380},

    // 42
    // Orbital Walking Barrage
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_owb2,
        SG_OWB},

    // 43
    // Orbital Laser
    {
        {INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_ol2,
        SG_OL},

    // 44
    // Orbital Railcannon Strike
    {
        {INPUT_RIGHT, INPUT_UP, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_ors2,
        SG_ORS},

    // 45
    // Orbital Precision Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_ops2,
        SG_OPS},

    // 46
    // Orbital Gas Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_ogs2,
        SG_OGS},

    // 47
    // Orbital EMS Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, INPUT_DOWN, 0, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_oes2,
        SG_OES},

    // 48
    // Orbital Smoke Strike
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_oss2,
        SG_OSS},

    // 49
    // Orbital Napalm Barrage
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, 0, 0},
        SND_ORBITAL,
        sgRed,
        &img_onb2,
        SG_ONB},

    // 50
    // Eagle Strafing Run
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_RIGHT, 0, 0, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_esr2,
        SG_SR},

    // 51
    // Eagle Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_ea2,
        SG_A},

    // 52
    // Eagle Cluster Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_ecb2,
        SG_CB},

    // 53
    // Eagle Napalm Airstrike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_ena2,
        SG_NA},

    // 54
    // Eagle Smoke Strike
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_ess2,
        SG_ESS},

    // 55
    // Eagle 110MM Rocket Pods
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, 0, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_e1102,
        SG_110},

    // 56
    // Eagle 500kg Bomb
    {
        {INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SND_EAGLE,
        sgRed,
        &img_e5002,
        SG_500},

    // 57
    // Directional Shield
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_UP, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_ds2,
        SG_DS},

    // 58
    // Anti-Tank Emplacement
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_RIGHT, 0, 0},
        SND_MINES,
        sgGreen,
        &img_ate2,
        SG_ATE},

    // 59
    // Flame Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_fs2,
        SG_FS},

    // 60
    // Fast Recon Vehicle
    {
        {INPUT_LEFT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, 0},
        SND_BACKPACK,
        sgBlue,
        &img_frv2,
        SG_FRV},

    // 61
    // Portable Hellbomb
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_UP, 0, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_ph2,
        SG_PH},

    // 62
    // Gas Mines
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0, 0},
        SND_MINES,
        sgGreen,
        &img_gm2,
        SG_GM},

    // 63
    // StA-X3 W.A.S.P. Launcher
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_wsp2,
        SG_WSP},

    // 64
    // E/GL-21 Grenadier Battlement
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_gb2,
        SG_GB},

    // 65
    // LIFT-860 Hover Pack
    {
        {INPUT_DOWN, INPUT_UP, INPUT_UP, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_hp2,
        SG_HP},

    // 66
    // One True Flag
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_UP, 0, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_otf2,
        SG_OTF},

    // 67
    // De-escalator
    {
        {INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_de2,
        SG_DE},

    // 68
    // Guard Dog K-9
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, INPUT_LEFT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_gdk2,
        SG_GDK},

    // 69
    // PLAS-45 Epoch
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_e2,
        SG_E},

    // 70
    // A/LAS-98 Laser Sentry
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0},
        SND_SENTRY,
        sgGreen,
        &img_ls2,
        SG_LS},

    // 71
    // LIFT-182 Warp Pack
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_wp2,
        SG_WP},

    // 72
    // Exandable Napalm
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_LEFT, 0, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_en2,
        SG_EN},

    // 73
    // Solo Silo
    {
        {INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_ss2,
        SG_SS},

    // 74
    // Speargun
    {
        {INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_sg2,
        SG_SG},

    // 75
    // CQC-9 Defoliation Tool
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_RIGHT, INPUT_DOWN, 0, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_dt2,
        SG_DT},

    // 76
    // M-1000 Maxigun
    {
        {INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0},
        SND_WEAPON,
        sgBlue,
        &img_mxg2,
        SG_MXG},

    // 77
    // AX/FLAM-75 "Guard Dog" Hot Dog
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_LEFT, INPUT_LEFT, 0, 0},
        SND_BACKPACK,
        sgBlue,
        &img_gdhd2,
        SG_GDHD}};

const stratagemBase strategemBaseList[] = {
    // 0
    // Reinforce
    {
        {INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_LEFT, INPUT_UP, 0, 0, 0},
        NULL},

    // 1
    // Resupply
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, 0, 0, 0, 0},
        NULL},

    // 2
    // SOS
    {
        {INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_UP, 0, 0, 0, 0},
        NULL},

    // 3
    // Eagle rearm
    {
        {INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_UP, INPUT_RIGHT, 0, 0, 0},
        NULL},

    // 4
    // Hellbomb
    {
        {INPUT_DOWN, INPUT_UP, INPUT_LEFT, INPUT_DOWN, INPUT_UP, INPUT_RIGHT, INPUT_DOWN, INPUT_UP},
        NULL},

    // 5
    // S.E.A.F.
    {
        {INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_DOWN, 0, 0, 0, 0},
        NULL},

    // 6
    // SSSD Delivery
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0, 0},
        NULL},

    // 7
    // Upload data
    {
        {INPUT_LEFT, INPUT_RIGHT, INPUT_UP, INPUT_UP, INPUT_UP, 0, 0, 0},
        NULL},

    // 8
    // Super Earth Flag
    {
        {INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_UP, 0, 0, 0, 0},
        NULL},

    // 9
    // Hive breaker drill
    {
        {INPUT_LEFT, INPUT_UP, INPUT_DOWN, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0},
        NULL},

    // 10
    // Tectonic drill
    {
        {INPUT_UP, INPUT_DOWN, INPUT_UP, INPUT_DOWN, INPUT_UP, INPUT_DOWN, 0, 0},
        NULL},

    // 11
    // Prospection drill
    {
        {INPUT_DOWN, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0},
        NULL},

    // 12
    // Seismic probe
    {
        {INPUT_UP, INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_DOWN, 0, 0},
        NULL},

    // 13
    // Orbital illumination flare
    {
        {INPUT_RIGHT, INPUT_RIGHT, INPUT_LEFT, INPUT_LEFT, 0, 0, 0, 0},
        NULL},

    // 14
    // Dark fluid vessel
    {
        {INPUT_UP, INPUT_LEFT, INPUT_RIGHT, INPUT_DOWN, INPUT_UP, INPUT_UP, 0, 0},
        NULL}};

#endif

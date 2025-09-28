#ifndef _UI_ASSIGNMENT_H
#define _UI_ASSIGNMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ui.h"
#include "screens.h"
#include <esp_system.h>

    enum stratagemType
    {
        // Weapons
        SG_AC,
        SG_AMR,
        SG_ARL,
        SG_AT,
        SG_C,
        SG_EAT,
        SG_FT,
        SG_GL,
        SG_HMG,
        SG_LC,
        SG_MG,
        SG_QC,
        SG_RG,
        SG_RR,
        SG_SPR,
        SG_WSP,
        SG_STE,
        SG_SW,
        SG_DE,
        SG_E,
        SG_EN,
        SG_SG,

        // Backpacks
        SG_BSB,
        SG_EE,
        SG_GD,
        SG_GDB,
        SG_GDR,
        SG_JP,
        SG_PE,
        SG_SGP,
        SG_SUP,
        SG_DS,
        SG_FRV,
        SG_PH,
        SG_HP,
        SG_OTF,
        SG_GDK,
        SG_WP,

        // Stationary
        SG_ACS,
        SG_APM,
        SG_ATM,
        SG_EMS,
        SG_GS,
        SG_HMGE,
        SG_IM,
        SG_MGS,
        SG_MS,
        SG_RS,
        SG_SGR,
        SG_TT,
        SG_ATE,
        SG_FS,
        SG_GM,
        SG_GB,
        SG_LS,
        SG_SS,

        // Strikes
        SG_120,
        SG_380,
        SG_OAS,
        SG_OES,
        SG_OGB,
        SG_OGS,
        SG_OL,
        SG_ONB,
        SG_OPS,
        SG_ORS,
        SG_OSS,
        SG_OWB,

        // Eagle
        SG_110,
        SG_500,
        SG_A,
        SG_CB,
        SG_NA,
        SG_SR,
        SG_ESS
    };

    // Assign stratagems index to UI buttons
    void assignStratagems(lv_event_t *e)
    {
        // Weapons
        objects.weapons_ac->user_data = (void *)SG_AC;
        objects.weapons_amr->user_data = (void *)SG_AMR;
        objects.weapons_arl->user_data = (void *)SG_ARL;
        objects.weapons_at->user_data = (void *)SG_AT;
        objects.weapons_c->user_data = (void *)SG_C;
        objects.weapons_eat->user_data = (void *)SG_EAT;
        objects.weapons_ft->user_data = (void *)SG_FT;
        objects.weapons_gl->user_data = (void *)SG_GL;
        objects.weapons_hmg->user_data = (void *)SG_HMG;
        objects.weapons_lc->user_data = (void *)SG_LC;
        objects.weapons_mg->user_data = (void *)SG_MG;
        objects.weapons_qc->user_data = (void *)SG_QC;
        objects.weapons_rg->user_data = (void *)SG_RG;
        objects.weapons_rr->user_data = (void *)SG_RR;
        objects.weapons_spr->user_data = (void *)SG_SPR;
        objects.weapons_wsp->user_data = (void *)SG_WSP;
        objects.weapons_ste->user_data = (void *)SG_STE;
        objects.weapons_sw->user_data = (void *)SG_SW;
        objects.weapons_de->user_data = (void *)SG_DE;
        objects.weapons_e->user_data = (void *)SG_E;
        objects.weapons_en->user_data = (void *)SG_EN;
        objects.weapons_sg->user_data = (void *)SG_SG;

        // Backpacks
        objects.backpack_bsb->user_data = (void *)SG_BSB;
        objects.supply_ee->user_data = (void *)SG_EE;
        objects.backpack_gd->user_data = (void *)SG_GD;
        objects.backpack_gdb->user_data = (void *)SG_GDB;
        objects.backpack_gdr->user_data = (void *)SG_GDR;
        objects.backpack_jp->user_data = (void *)SG_JP;
        objects.supply_pe->user_data = (void *)SG_PE;
        objects.backpack_sgp->user_data = (void *)SG_SGP;
        objects.backpack_sup->user_data = (void *)SG_SUP;
        objects.backpack_ds->user_data = (void *)SG_DS;
        objects.supply_frv->user_data = (void *)SG_FRV;
        objects.backpack_ph->user_data = (void *)SG_PH;
        objects.backpack_hp->user_data = (void *)SG_HP;
        objects.supply_otf->user_data = (void *)SG_OTF;
        objects.backpack_gdk->user_data = (void *)SG_GDK;
        objects.backpack_wp->user_data = (void *)SG_WP;

        // Stationary
        objects.sentry_acs->user_data = (void *)SG_ACS;
        objects.ground_apm->user_data = (void *)SG_APM;
        objects.ground_atm->user_data = (void *)SG_ATM;
        objects.sentry_ems->user_data = (void *)SG_EMS;
        objects.sentry_gs->user_data = (void *)SG_GS;
        objects.sentry_hmge->user_data = (void *)SG_HMGE;
        objects.ground_im->user_data = (void *)SG_IM;
        objects.sentry_mgs->user_data = (void *)SG_MGS;
        objects.sentry_ms->user_data = (void *)SG_MS;
        objects.sentry_rs->user_data = (void *)SG_RS;
        objects.ground_sgr->user_data = (void *)SG_SGR;
        objects.ground_tt->user_data = (void *)SG_TT;
        objects.sentry_ate->user_data = (void *)SG_ATE;
        objects.sentry_fs->user_data = (void *)SG_FS;
        objects.ground_gm->user_data = (void *)SG_GM;
        objects.ground_gb->user_data = (void *)SG_GB;
        objects.sentry_ls->user_data = (void *)SG_LS;
        objects.supply_ss->user_data = (void *)SG_SS;

        // Strikes
        objects.strike120->user_data = (void *)SG_120;
        objects.strike380->user_data = (void *)SG_380;
        objects.strike_oas->user_data = (void *)SG_OAS;
        objects.strike_oes->user_data = (void *)SG_OES;
        objects.strike_ogb->user_data = (void *)SG_OGB;
        objects.strike_ogs->user_data = (void *)SG_OGS;
        objects.strike_ol->user_data = (void *)SG_OL;
        objects.strike_onb->user_data = (void *)SG_ONB;
        objects.strike_ops->user_data = (void *)SG_OPS;
        objects.strike_ors->user_data = (void *)SG_ORS;
        objects.strike_oss->user_data = (void *)SG_OSS;
        objects.strike_owb->user_data = (void *)SG_OWB;

        // Eagle
        objects.eagle110->user_data = (void *)SG_110;
        objects.eagle500->user_data = (void *)SG_500;
        objects.eagle_a->user_data = (void *)SG_A;
        objects.eagle_cb->user_data = (void *)SG_CB;
        objects.eagle_na->user_data = (void *)SG_NA;
        objects.eagle_sr->user_data = (void *)SG_SR;
        objects.eagle_ss->user_data = (void *)SG_ESS;
    }

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
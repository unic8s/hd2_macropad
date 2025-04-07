#ifndef _UI_ASSIGNMENT_H
#define _UI_ASSIGNMENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ui.h"
#include <esp_system.h>

    enum stratagemType
    {
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
        SG_SS
    };

    // Assign stratagems index to UI buttons
    void assignStratagems(lv_event_t *e)
    {
        // Weapons
        ui_WeaponsAC->user_data = (void *)SG_AC;
        ui_WeaponsAMR->user_data = (void *)SG_AMR;
        ui_WeaponsARL->user_data = (void *)SG_ARL;
        ui_WeaponsAT->user_data = (void *)SG_AT;
        ui_WeaponsC->user_data = (void *)SG_C;
        ui_WeaponsEAT->user_data = (void *)SG_EAT;
        ui_WeaponsFT->user_data = (void *)SG_FT;
        ui_WeaponsGL->user_data = (void *)SG_GL;
        ui_WeaponsHMG->user_data = (void *)SG_HMG;
        ui_WeaponsLC->user_data = (void *)SG_LC;
        ui_WeaponsMG->user_data = (void *)SG_MG;
        ui_WeaponsQC->user_data = (void *)SG_QC;
        ui_WeaponsRG->user_data = (void *)SG_RG;
        ui_WeaponsRR->user_data = (void *)SG_RR;
        ui_WeaponsSPR->user_data = (void *)SG_SPR;
        ui_WeaponsWSP->user_data = (void *)SG_WSP;
        ui_WeaponsSTE->user_data = (void *)SG_STE;
        ui_WeaponsSW->user_data = (void *)SG_SW;

        // Backpacks
        ui_BackpacksBSB->user_data = (void *)SG_BSB;
        ui_BackpacksEE->user_data = (void *)SG_EE;
        ui_BackpacksGD->user_data = (void *)SG_GD;
        ui_BackpacksGDB->user_data = (void *)SG_GDB;
        ui_BackpacksGDR->user_data = (void *)SG_GDR;
        ui_BackpacksJP->user_data = (void *)SG_JP;
        ui_BackpacksPE->user_data = (void *)SG_PE;
        ui_BackpacksSGP->user_data = (void *)SG_SGP;
        ui_BackpacksSUP->user_data = (void *)SG_SUP;
        ui_BackpacksDS->user_data = (void *)SG_DS;
        ui_BackpacksFRV->user_data = (void *)SG_FRV;
        ui_BackpacksPH->user_data = (void *)SG_PH;
        ui_BackpacksHP->user_data = (void *)SG_HP;

        // Stationary
        ui_StationaryACS->user_data = (void *)SG_ACS;
        ui_StationaryAPM->user_data = (void *)SG_APM;
        ui_StationaryATM->user_data = (void *)SG_ATM;
        ui_StationaryEMS->user_data = (void *)SG_EMS;
        ui_StationaryGS->user_data = (void *)SG_GS;
        ui_StationaryHMGE->user_data = (void *)SG_HMGE;
        ui_StationaryIM->user_data = (void *)SG_IM;
        ui_StationaryMGS->user_data = (void *)SG_MGS;
        ui_StationaryMS->user_data = (void *)SG_MS;
        ui_StationaryRS->user_data = (void *)SG_RS;
        ui_StationarySGR->user_data = (void *)SG_SGR;
        ui_StationaryTT->user_data = (void *)SG_TT;
        ui_StationaryATE->user_data = (void *)SG_ATE;
        ui_StationaryFS->user_data = (void *)SG_FS;
        ui_StationaryGM->user_data = (void *)SG_GM;
        ui_StationaryGB->user_data = (void *)SG_GB;

        // Strikes
        ui_Strikes120->user_data = (void *)SG_120;
        ui_Strikes380->user_data = (void *)SG_380;
        ui_StrikesOAS->user_data = (void *)SG_OAS;
        ui_StrikesOES->user_data = (void *)SG_OES;
        ui_StrikesOGB->user_data = (void *)SG_OGB;
        ui_StrikesOGS->user_data = (void *)SG_OGS;
        ui_StrikesOL->user_data = (void *)SG_OL;
        ui_StrikesONB->user_data = (void *)SG_ONB;
        ui_StrikesOPS->user_data = (void *)SG_OPS;
        ui_StrikesORS->user_data = (void *)SG_ORS;
        ui_StrikesOSS->user_data = (void *)SG_OSS;
        ui_StrikesOWB->user_data = (void *)SG_OWB;

        // Eagle
        ui_Eagle110->user_data = (void *)SG_110;
        ui_Eagle500->user_data = (void *)SG_500;
        ui_EagleA->user_data = (void *)SG_A;
        ui_EagleCB->user_data = (void *)SG_CB;
        ui_EagleNA->user_data = (void *)SG_NA;
        ui_EagleSR->user_data = (void *)SG_SR;
        ui_EagleSS->user_data = (void *)SG_SS;
    }

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
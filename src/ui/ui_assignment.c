#include "ui.h"

// Assign stratagems index to UI buttons
void assignStratagems(lv_event_t *e)
{
	// Weapons
	ui_WeaponsAC->user_data = (void*)7;
	ui_WeaponsAMR->user_data = (void*)1;
	ui_WeaponsARL->user_data = (void*)15;
	ui_WeaponsAT->user_data = (void*)13;
	ui_WeaponsC->user_data = (void*)4;
	ui_WeaponsEAT->user_data = (void*)3;
	ui_WeaponsFT->user_data = (void*)6;
	ui_WeaponsGL->user_data = (void*)11;
	ui_WeaponsHMG->user_data = (void*)8;
	ui_WeaponsLC->user_data = (void*)12;
	ui_WeaponsMG->user_data = (void*)0;
	ui_WeaponsQC->user_data = (void*)14;
	ui_WeaponsRG->user_data = (void*)9;
	ui_WeaponsRR->user_data = (void*)5;
	ui_WeaponsSPR->user_data = (void*)10;
	ui_WeaponsSTE->user_data = (void*)16;
	ui_WeaponsSW->user_data = (void*)2;

	// Backpacks
	ui_BackpacksBSB->user_data = (void*)19;
	ui_BackpacksEE->user_data = (void*)25;
	ui_BackpacksGD->user_data = (void*)21;
	ui_BackpacksGDB->user_data = (void*)23;
	ui_BackpacksGDR->user_data = (void*)22;
	ui_BackpacksJP->user_data = (void*)17;
	ui_BackpacksPE->user_data = (void*)24;
	ui_BackpacksSGP->user_data = (void*)20;
	ui_BackpacksSUP->user_data = (void*)18;
	ui_BackpacksDS->user_data = (void*)57;
	ui_BackpacksFRV->user_data = (void*)60;
	ui_BackpacksPH->user_data = (void*)61;

	// Stationary
	ui_StationaryACS->user_data = (void*)35;
	ui_StationaryAPM->user_data = (void*)29;
	ui_StationaryATM->user_data = (void*)31;
	ui_StationaryEMS->user_data = (void*)37;
	ui_StationaryGS->user_data = (void*)33;
	ui_StationaryHMGE->user_data = (void*)26;
	ui_StationaryIM->user_data = (void*)30;
	ui_StationaryMGS->user_data = (void*)32;
	ui_StationaryMS->user_data = (void*)34;
	ui_StationaryRS->user_data = (void*)36;
	ui_StationarySGR->user_data = (void*)27;
	ui_StationaryTT->user_data = (void*)28;
	ui_StationaryATE->user_data = (void*)58;
	ui_StationaryFS->user_data = (void*)59;
	ui_StationaryGM->user_data = (void*)62;

	// Strikes
	ui_Strikes120->user_data = (void*)40;
	ui_Strikes380->user_data = (void*)41;
	ui_StrikesOAS->user_data = (void*)39;
	ui_StrikesOES->user_data = (void*)47;
	ui_StrikesOGB->user_data = (void*)38;
	ui_StrikesOGS->user_data = (void*)46;
	ui_StrikesOL->user_data = (void*)43;
	ui_StrikesONB->user_data = (void*)49;
	ui_StrikesOPS->user_data = (void*)45;
	ui_StrikesORS->user_data = (void*)44;
	ui_StrikesOSS->user_data = (void*)48;
	ui_StrikesOWB->user_data = (void*)42;

	// Eagle
	ui_Eagle110->user_data = (void*)55;
	ui_Eagle500->user_data = (void*)56;
	ui_EagleA->user_data = (void*)51;
	ui_EagleCB->user_data = (void*)52;
	ui_EagleNA->user_data = (void*)53;
	ui_EagleSR->user_data = (void*)50;
	ui_EagleSS->user_data = (void*)54;
}
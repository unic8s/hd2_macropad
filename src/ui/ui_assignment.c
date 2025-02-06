#include "ui.h"

// Assign stratagems index to UI buttons
void assignStratagems(lv_event_t *e)
{
	// Weapons
	ui_WeaponsAC->user_data = 7;
	ui_WeaponsAMR->user_data = 1;
	ui_WeaponsARL->user_data = 15;
	ui_WeaponsAT->user_data = 13;
	ui_WeaponsC->user_data = 4;
	ui_WeaponsEAT->user_data = 3;
	ui_WeaponsFT->user_data = 6;
	ui_WeaponsGL->user_data = 11;
	ui_WeaponsHMG->user_data = 8;
	ui_WeaponsLC->user_data = 12;
	ui_WeaponsMG->user_data = 0;
	ui_WeaponsQC->user_data = 14;
	ui_WeaponsRG->user_data = 9;
	ui_WeaponsRR->user_data = 5;
	ui_WeaponsSPR->user_data = 10;
	ui_WeaponsSTE->user_data = 16;
	ui_WeaponsSW->user_data = 2;

	// Backpacks
	ui_BackpacksBSB->user_data = 19;
	ui_BackpacksEE->user_data = 25;
	ui_BackpacksGD->user_data = 21;
	ui_BackpacksGDB->user_data = 23;
	ui_BackpacksGDR->user_data = 22;
	ui_BackpacksJP->user_data = 17;
	ui_BackpacksPE->user_data = 24;
	ui_BackpacksSGP->user_data = 20;
	ui_BackpacksSUP->user_data = 18;
	ui_BackpacksDS->user_data = 57;
	ui_BackpacksFRV->user_data = 60;
	ui_BackpacksPH->user_data = 61;

	// Stationary
	ui_StationaryACS->user_data = 35;
	ui_StationaryAPM->user_data = 29;
	ui_StationaryATM->user_data = 31;
	ui_StationaryEMS->user_data = 37;
	ui_StationaryGS->user_data = 33;
	ui_StationaryHMGE->user_data = 26;
	ui_StationaryIM->user_data = 30;
	ui_StationaryMGS->user_data = 32;
	ui_StationaryMS->user_data = 34;
	ui_StationaryRS->user_data = 36;
	ui_StationarySGR->user_data = 27;
	ui_StationaryTT->user_data = 28;
	ui_StationaryATE->user_data = 58;
	ui_StationaryFS->user_data = 59;

	// Strikes
	ui_Strikes120->user_data = 40;
	ui_Strikes380->user_data = 41;
	ui_StrikesOAS->user_data = 39;
	ui_StrikesOES->user_data = 47;
	ui_StrikesOGB->user_data = 38;
	ui_StrikesOGS->user_data = 46;
	ui_StrikesOL->user_data = 43;
	ui_StrikesONB->user_data = 49;
	ui_StrikesOPS->user_data = 45;
	ui_StrikesORS->user_data = 44;
	ui_StrikesOSS->user_data = 48;
	ui_StrikesOWB->user_data = 42;

	// Eagle
	ui_Eagle110->user_data = 55;
	ui_Eagle500->user_data = 56;
	ui_EagleA->user_data = 51;
	ui_EagleCB->user_data = 52;
	ui_EagleNA->user_data = 53;
	ui_EagleSR->user_data = 50;
	ui_EagleSS->user_data = 54;
}
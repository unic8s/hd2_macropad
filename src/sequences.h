#include "hid_dev.h"


#define INPUT_UP HID_KEY_W
#define INPUT_DOWN HID_KEY_S
#define INPUT_LEFT HID_KEY_A
#define INPUT_RIGHT HID_KEY_D


uint8_t sequences[57][8] = {
	// 0
	// MG-43 Machine Gun
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 1
	// APW-1 Anti-Materiel Rifle
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 2
	// M-105 Stalwart
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_LEFT,
	 0,
	 0},

	// 3
	// EAT-17 Expendable Anti-tank
	{INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 4
	// MLS-4X Commando
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 5
	// GR-8 Recoilless Rifle
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 0,
	 0,
	 0},

	// 6
	// FLAM-40 Flamethrower
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_UP,
	 0,
	 0,
	 0},

	// 7
	// AC-8 Autocannon
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_RIGHT,
	 0,
	 0},

	// 8
	// MG-206 Heavy Machine Gun
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 9
	// RS-422 Railgun
	{INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0},

	// 10
	// FAF-14 Spear Launcher
	{INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 11
	// GL-21 Grenade Launcher
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 12
	// LAS-98 Laser Cannon
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 0,
	 0,
	 0},

	// 13
	// ARC-3 Arc Thrower
	{INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_LEFT,
	 0,
	 0},

	// 14
	// LAS-99 Quasar Cannon
	{INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 15
	// RL-77 Airburst Rocket Launcher
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 16
	// TX-41 Sterilizer
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 0,
	 0,
	 0},

	// 17
	// LIFT-850 Jump Pack
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_UP,
	 0,
	 0,
	 0},

	// 18
	// B-1 Supply Pack
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_DOWN,
	 0,
	 0},

	// 19
	// SH-20 Ballistic Shield Backpack
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 0,
	 0},

	// 20
	// SH-32 Shield Generator Pack
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0},

	// 21
	// AX/AR-23 "Guard Dog"
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 0,
	 0},

	// 22
	// AX/LAS-5 "Guard Dog" Rover
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 0,
	 0},

	// 23
	// AX/TX-13 "Guard Dog" Dog Breath
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_UP,
	 0,
	 0},

	// 24
	// EXO-45 Patriot Exosuit
	{INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 0},

	// 25
	// EXO-49 Emancipator Exosuit
	{INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_UP,
	 0},

	// 26
	// E/MG-101 HMG Emplacement
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 0,
	 0},

	// 27
	// FX-12 Shield Generator Relay
	{INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0},

	// 28
	// A/ARC-3 Tesla Tower
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 0,
	 0},

	// 29
	// MD-6 Anti-Personnel Minefield
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_RIGHT,
	 0,
	 0,
	 0,
	 0},

	// 30
	// MD-I4 Incendiary Mines
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 0,
	 0,
	 0,
	 0},

	// 31
	// MD-17 Anti-Tank Mines
	{INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_UP,
	 0,
	 0,
	 0,
	 0},

	// 32
	// A/MG-43 Machine Gun Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_UP,
	 0,
	 0,
	 0},

	// 33
	// A/G-16 Gatling Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 0,
	 0,
	 0,
	 0},

	// 34
	// A/M-12 Mortar Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 35
	// A/AC-8 Autocannon Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_UP,
	 0,
	 0},

	// 36
	// A/MLS-4X Rocket Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 0,
	 0,
	 0},

	// 37
	// A/M-23 EMS Mortar Sentry
	{INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 38
	// Orbital Gatling Barrage
	{INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_UP,
	 INPUT_UP,
	 0,
	 0,
	 0},

	// 39
	// Orbital Airburst Strike
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 0,
	 0,
	 0,
	 0,
	 0},

	// 40
	// Orbital 120MM HE Barrage
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 0,
	 0},

	// 41
	// Orbital 380MM HE Barrage
	{INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_UP,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 0},

	// 42
	// Orbital Walking Barrage
	{INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 0,
	 0},

	// 43
	// Orbital Laser
	{INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 0,
	 0,
	 0},

	// 44
	// Orbital Railcannon Strike
	{INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 45
	// Orbital Precision Strike
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_UP,
	 0,
	 0,
	 0,
	 0,
	 0},

	// 46
	// Orbital Gas Strike
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0,
	 0},

	// 47
	// Orbital EMS Strike
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_LEFT,
	 INPUT_DOWN,
	 0,
	 0,
	 0,
	 0},

	// 48
	// Orbital Smoke Strike
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 0,
	 0,
	 0,
	 0},

	// 49
	// Orbital Napalm Barrage
	{INPUT_RIGHT,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_LEFT,
	 INPUT_RIGHT,
	 INPUT_UP,
	 0,
	 0},

	// 50
	// Eagle Strafing Run
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_RIGHT,
	 0,
	 0,
	 0,
	 0,
	 0},

	// 51
	// Eagle Airstrike
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0,
	 0},

	// 52
	// Eagle Cluster Bomb
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_RIGHT,
	 0,
	 0,
	 0},

	// 53
	// Eagle Napalm Airstrike
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_UP,
	 0,
	 0,
	 0,
	 0},

	// 54
	// Eagle Smoke Strike
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_DOWN,
	 0,
	 0,
	 0,
	 0},

	// 55
	// Eagle 110MM Rocket Pods
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_UP,
	 INPUT_LEFT,
	 0,
	 0,
	 0,
	 0},

	// 56
	// Eagle 500kg Bomb
	{INPUT_UP,
	 INPUT_RIGHT,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 INPUT_DOWN,
	 0,
	 0,
	 0}

	//
};
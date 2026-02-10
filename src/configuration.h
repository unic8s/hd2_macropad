#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <esp_system.h>
#include <lvgl.h>

	esp_err_t initConfig();
	int8_t getConfig(char *key, int8_t defaultValue);
	void setConfig(char *key, uint8_t value);
	void setDelay(int delay, bool restore);
	void setRotation(int rotation, bool restore);
	void setBrightness(int brightness, bool restore);
	void setMuted(bool muted, bool restore);
	void setConnectivity(uint8_t index, bool restore);
	void setKeymap(uint8_t index, bool restore);
	void setAutoComplete(bool enable, bool restore);
	void setCooldown(bool enable, bool restore);
	void setShipModules(bool restore);
	void loadConfig();
	esp_err_t openConfig();
	void closeConfig();
	void resetConfig();
	int8_t peekConfig(char *key, int8_t defaultValue);

	enum ModuleType
	{
		SHIP_LVC = 1,
		SHIP_ZBL = 2,
		SHIP_HC = 4,
		SHIP_MA = 8,
		SHIP_SRP = 16,
		SHIP_SS = 32,
		SHIP_TSU = 64,
		SHIP_RLS = 128,
		SHIP_DT = 256
	};

#define MAX_SHIP_MODULES 9

	typedef struct
	{
		uint16_t value;
		lv_obj_t *checkbox;
	} shipModule;

	typedef struct
	{
		uint16_t value;
		lv_obj_t *checkbox;
		uint8_t shift;
		double cooldown;
		double callin;
	} shipModuleDetails;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
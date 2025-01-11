#include "esp_system.h"
#include "hid_dev.h"


uint8_t keymapIndex = 0;

const uint8_t keymaps[2][4] = {
	{HID_KEY_W,
	 HID_KEY_S,
	 HID_KEY_A,
	 HID_KEY_D},
	{HID_KEY_UP_ARROW,
	 HID_KEY_DOWN_ARROW,
	 HID_KEY_LEFT_ARROW,
	 HID_KEY_RIGHT_ARROW}};

uint8_t LookupKeycode(uint8_t keyCode)
{
  uint8_t *keymap = keymaps[keymapIndex];
  uint8_t lookupIndex = keyCode - 1;

	keyCode = keymap[lookupIndex];

	return keyCode;
}
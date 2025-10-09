#include "main.h"
#include "ui.h"
#include "ui_events.h"


extern lv_obj_t *cooldownLabels[MAX_USER_STRATAGEMS];


void ui_post()
{
  lv_obj_t *tabsBtnsList[] = {
      lv_tabview_get_tab_btns(objects.tab_view_setup),
      lv_tabview_get_tab_btns(objects.tab_view_config)};

  lv_color_t itemColorActive = lv_color_hex(colorActive);

  for (uint8_t c = 0; c < 2; c++)
  {
    lv_obj_t *tabBtnsItem = tabsBtnsList[c];

    lv_obj_set_style_border_color(tabBtnsItem, itemColorActive, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(tabBtnsItem, 2, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_text_color(tabBtnsItem, itemColorActive, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(tabBtnsItem, lv_color_hex(0x999999), LV_PART_ITEMS | LV_STATE_CHECKED);
  }

  lv_obj_t *dropDownList[] = {
      lv_dropdown_get_list(objects.dd_connectivity),
      lv_dropdown_get_list(objects.dd_keymap)};

  for (uint8_t c = 0; c < 2; c++)
  {
    lv_obj_t *dropDownItem = dropDownList[c];

    lv_obj_set_style_text_color(dropDownItem, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(dropDownItem, itemColorActive, LV_PART_SELECTED | LV_STATE_CHECKED);
  }

  lv_obj_add_flag(objects.msg_box, LV_OBJ_FLAG_HIDDEN);

  cooldownLabels[0] = objects.label_cooldown1;
  cooldownLabels[1] = objects.label_cooldown2;
  cooldownLabels[2] = objects.label_cooldown3;
  cooldownLabels[3] = objects.label_cooldown4;
  cooldownLabels[4] = objects.label_cooldown5;
  cooldownLabels[5] = objects.label_cooldown6;

  resetCooldowns();
}
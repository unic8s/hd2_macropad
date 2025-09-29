#include "main.h"
#include "ui.h"
#include "ui_events.h"


#define ANIMATION_DURATION 100


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
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"

void animate_preset_load(lv_obj_t *target)
{
  lv_anim_t a, b;

  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_height);
  lv_anim_set_var(&a, target);
  lv_anim_set_time(&a, ANIMATION_DURATION);
  lv_anim_set_values(&a, 38, 46);
  lv_anim_start(&a);

  lv_anim_init(&b);
  lv_anim_set_exec_cb(&b, (lv_anim_exec_xcb_t)lv_obj_set_height);
  lv_anim_set_var(&b, target);
  lv_anim_set_time(&b, ANIMATION_DURATION);
  lv_anim_set_delay(&b, ANIMATION_DURATION);
  lv_anim_set_values(&b, 46, 38);
  lv_anim_start(&b);
}

void animate_preset_save(lv_obj_t *target)
{
  lv_anim_t a, b;
  
  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_height);
  lv_anim_set_var(&a, target);
  lv_anim_set_time(&a, ANIMATION_DURATION);
  lv_anim_set_values(&a, 38, 30);
  lv_anim_start(&a); 

  lv_anim_init(&b);
  lv_anim_set_exec_cb(&b, (lv_anim_exec_xcb_t)lv_obj_set_height);
  lv_anim_set_var(&b, target);
  lv_anim_set_time(&b, ANIMATION_DURATION);
  lv_anim_set_delay(&b, ANIMATION_DURATION);
  lv_anim_set_values(&b, 30, 38);
  lv_anim_start(&b);
}

#pragma GCC diagnostic pop
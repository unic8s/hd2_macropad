#include "main.h"
#include "ui.h"


#define ANIMATION_DURATION 150


typedef struct _ui_anim_user_data_t {
    lv_obj_t * target;
    lv_img_dsc_t ** imgset;
    int32_t imgset_size;
    int32_t val;
} ui_anim_user_data_t;


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


void PresetSaveAnim_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, ANIMATION_DURATION);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_values(&PropertyAnimation_0, 38, 30);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, ANIMATION_DURATION);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_values(&PropertyAnimation_1, 30, 38);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + ANIMATION_DURATION);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
void PresetLoadAnim_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, ANIMATION_DURATION);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_values(&PropertyAnimation_0, 38, 46);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, ANIMATION_DURATION);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_values(&PropertyAnimation_1, 46, 38);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + ANIMATION_DURATION);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
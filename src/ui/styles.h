#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: ButtonStd
lv_style_t *get_style_button_std_MAIN_DEFAULT();
lv_style_t *get_style_button_std_MAIN_CHECKED();
lv_style_t *get_style_button_std_MAIN_PRESSED();
void add_style_button_std(lv_obj_t *obj);
void remove_style_button_std(lv_obj_t *obj);

// Style: TabStratagem
lv_style_t *get_style_tab_stratagem_MAIN_DEFAULT();
void add_style_tab_stratagem(lv_obj_t *obj);
void remove_style_tab_stratagem(lv_obj_t *obj);

// Style: TabConfig
lv_style_t *get_style_tab_config_MAIN_DEFAULT();
void add_style_tab_config(lv_obj_t *obj);
void remove_style_tab_config(lv_obj_t *obj);

// Style: SliderConfig
lv_style_t *get_style_slider_config_MAIN_DEFAULT();
lv_style_t *get_style_slider_config_INDICATOR_DEFAULT();
lv_style_t *get_style_slider_config_KNOB_DEFAULT();
void add_style_slider_config(lv_obj_t *obj);
void remove_style_slider_config(lv_obj_t *obj);

// Style: SwitchConfig
lv_style_t *get_style_switch_config_MAIN_DEFAULT();
lv_style_t *get_style_switch_config_MAIN_CHECKED();
lv_style_t *get_style_switch_config_KNOB_DEFAULT();
lv_style_t *get_style_switch_config_KNOB_CHECKED();
lv_style_t *get_style_switch_config_INDICATOR_CHECKED();
lv_style_t *get_style_switch_config_INDICATOR_DEFAULT();
void add_style_switch_config(lv_obj_t *obj);
void remove_style_switch_config(lv_obj_t *obj);

// Style: LabelCooldown
lv_style_t *get_style_label_cooldown_MAIN_DEFAULT();
void add_style_label_cooldown(lv_obj_t *obj);
void remove_style_label_cooldown(lv_obj_t *obj);

// Style: CheckboxConfig
lv_style_t *get_style_checkbox_config_INDICATOR_DEFAULT();
lv_style_t *get_style_checkbox_config_INDICATOR_CHECKED();
lv_style_t *get_style_checkbox_config_MAIN_DEFAULT();
void add_style_checkbox_config(lv_obj_t *obj);
void remove_style_checkbox_config(lv_obj_t *obj);

// Style: DropdownConfig
lv_style_t *get_style_dropdown_config_MAIN_DEFAULT();
void add_style_dropdown_config(lv_obj_t *obj);
void remove_style_dropdown_config(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/
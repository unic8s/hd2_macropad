#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: ButtonStd
//

void init_style_button_std_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_button_std_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_std_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_std_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]));
};

lv_style_t *get_style_button_std_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_std_MAIN_CHECKED(style);
    }
    return style;
};

void init_style_button_std_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_img_opa(style, 127);
};

lv_style_t *get_style_button_std_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_std_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_button_std(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_std_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_std_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_button_std_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_button_std(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_std_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_std_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_button_std_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: TabStratagem
//

void init_style_tab_stratagem_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_pad_bottom(style, 2);
    lv_style_set_pad_left(style, 2);
    lv_style_set_pad_right(style, 2);
    lv_style_set_pad_column(style, 4);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_pad_top(style, 2);
    lv_style_set_pad_row(style, 4);
    lv_style_set_bg_color(style, lv_color_hex(0xff282b30));
};

lv_style_t *get_style_tab_stratagem_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_stratagem_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_stratagem(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_stratagem_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_stratagem(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_stratagem_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: TabConfig
//

void init_style_tab_config_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 8);
    lv_style_set_pad_bottom(style, 8);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 8);
    lv_style_set_pad_column(style, 8);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_START);
};

lv_style_t *get_style_tab_config_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_config_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: SliderConfig
//

void init_style_slider_config_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_width(style, 2);
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][0]));
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_slider_config_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_slider_config_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_slider_config_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]));
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_slider_config_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_slider_config_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_slider_config_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]));
    lv_style_set_border_width(style, 2);
    lv_style_set_pad_top(style, 8);
    lv_style_set_pad_bottom(style, 8);
    lv_style_set_pad_left(style, 8);
    lv_style_set_pad_right(style, 8);
};

lv_style_t *get_style_slider_config_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_slider_config_KNOB_DEFAULT(style);
    }
    return style;
};

void add_style_slider_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_slider_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_slider_config_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_slider_config_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
};

void remove_style_slider_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_slider_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_slider_config_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_slider_config_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
};

//
// Style: CheckboxConfig
//

void init_style_checkbox_config_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][0]));
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_checkbox_config_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_config_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_checkbox_config_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]));
};

lv_style_t *get_style_checkbox_config_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_config_MAIN_CHECKED(style);
    }
    return style;
};

void init_style_checkbox_config_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][0]));
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_checkbox_config_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_config_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_checkbox_config_KNOB_CHECKED(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(theme_colors[eez_flow_get_selected_theme_index()][1]));
};

lv_style_t *get_style_checkbox_config_KNOB_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_config_KNOB_CHECKED(style);
    }
    return style;
};

void init_style_checkbox_config_INDICATOR_CHECKED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_checkbox_config_INDICATOR_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checkbox_config_INDICATOR_CHECKED(style);
    }
    return style;
};

void add_style_checkbox_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_checkbox_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_checkbox_config_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_checkbox_config_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_checkbox_config_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_checkbox_config_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

void remove_style_checkbox_config(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_checkbox_config_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_checkbox_config_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_checkbox_config_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_checkbox_config_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_checkbox_config_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

//
// Style: LabelCooldown
//

void init_style_label_cooldown_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_BOTTOM_MID);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_width(style, 1);
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 4);
    lv_style_set_pad_right(style, 4);
    lv_style_set_text_font(style, &lv_font_montserrat_18);
    lv_style_set_radius(style, 4);
};

lv_style_t *get_style_label_cooldown_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_cooldown_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_cooldown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_cooldown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_cooldown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_cooldown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_button_std,
        add_style_tab_stratagem,
        add_style_tab_config,
        add_style_slider_config,
        add_style_checkbox_config,
        add_style_label_cooldown,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_button_std,
        remove_style_tab_stratagem,
        remove_style_tab_config,
        remove_style_slider_config,
        remove_style_checkbox_config,
        remove_style_label_cooldown,
    };
    remove_style_funcs[styleIndex](obj);
}


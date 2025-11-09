/*
 * eez-framework
 *
 * MIT License
 * Copyright 2024 Envox d.o.o.
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <math.h>

#if defined(EEZ_FOR_LVGL)

#include <stdint.h>

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #if LVGL_VERSION_MAJOR > 9 || (LVGL_VERSION_MAJOR == 9 && LVGL_VERSION_MINOR > 1)
        #ifdef __has_include
            #if __has_include("lvgl_private.h")
                #include "lvgl_private.h"
            #elif __has_include("src/lvgl_private.h")
                #include "src/lvgl_private.h"
            #endif
        #endif
    #endif
#else
    #include "lvgl/lvgl.h"
    #if LVGL_VERSION_MAJOR > 9 || (LVGL_VERSION_MAJOR == 9 && LVGL_VERSION_MINOR > 1)
        #include "lvgl/src/lvgl_private.h"
    #endif
#endif

#if LVGL_VERSION_MAJOR >= 9
#define lv_scr_load_anim_t lv_screen_load_anim_t
#define lv_scr_load_anim lv_screen_load_anim
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

typedef void (*ActionExecFunc)(lv_event_t * e);
void eez_flow_init(const uint8_t *assets, uint32_t assetsSize, lv_obj_t **objects, size_t numObjects, const ext_img_desc_t *images, size_t numImages, ActionExecFunc *actions);

void eez_flow_init_styles(
    void (*add_style)(lv_obj_t *obj, int32_t styleIndex),
    void (*remove_style)(lv_obj_t *obj, int32_t styleIndex)
);

void eez_flow_init_groups(lv_group_t **groups, size_t numGroups);

void eez_flow_init_screen_names(const char **screenNames, size_t numScreens);
void eez_flow_init_object_names(const char **objectNames, size_t numObjects);
void eez_flow_init_group_names(const char **groupNames, size_t numGroups);
void eez_flow_init_style_names(const char **styleNames, size_t numStyles);
void eez_flow_init_themes(const char **themeNames, size_t numThemes, void (*changeColorTheme)(uint32_t themeIndex));

void eez_flow_set_create_screen_func(void (*createScreenFunc)(int screenIndex));
void eez_flow_set_delete_screen_func(void (*deleteScreenFunc)(int screenIndex));

void eez_flow_tick();

bool eez_flow_is_stopped();

extern int16_t g_currentScreen;

int16_t eez_flow_get_current_screen();
void eez_flow_set_screen(int16_t screenId, lv_scr_load_anim_t animType, uint32_t speed, uint32_t delay);
void eez_flow_push_screen(int16_t screenId, lv_scr_load_anim_t animType, uint32_t speed, uint32_t delay);
void eez_flow_pop_screen(lv_scr_load_anim_t animType, uint32_t speed, uint32_t delay);

void eez_flow_create_screen(int16_t screenId);
void eez_flow_delete_screen(int16_t screenId);
bool eez_flow_is_screen_created(int16_t screenId);

void eez_flow_delete_screen_on_unload(int screenIndex);

void flowOnPageLoaded(unsigned pageIndex);

// if flowState is nullptr then userWidgetComponentIndexOrPageIndex is page index
void *getFlowState(void *flowState, unsigned userWidgetComponentIndexOrPageIndex);
void deletePageFlowState(unsigned pageIndex);

void flowPropagateValue(void *flowState, unsigned componentIndex, unsigned outputIndex);
void flowPropagateValueInt32(void *flowState, unsigned componentIndex, unsigned outputIndex, int32_t value);
void flowPropagateValueUint32(void *flowState, unsigned componentIndex, unsigned outputIndex, uint32_t value);
void flowPropagateValueLVGLEvent(void *flowState, unsigned componentIndex, unsigned outputIndex, lv_event_t *event);

#define evalTextProperty(flowState, componentIndex, propertyIndex, errorMessage) _evalTextProperty(flowState, componentIndex, propertyIndex, errorMessage, __FILE__, __LINE__)
#define evalIntegerProperty(flowState, componentIndex, propertyIndex, errorMessage) _evalIntegerProperty(flowState, componentIndex, propertyIndex, errorMessage, __FILE__, __LINE__)
#define evalUnsignedIntegerProperty(flowState, componentIndex, propertyIndex, errorMessage) _evalUnsignedIntegerProperty(flowState, componentIndex, propertyIndex, errorMessage, __FILE__, __LINE__)
#define evalBooleanProperty(flowState, componentIndex, propertyIndex, errorMessage) _evalBooleanProperty(flowState, componentIndex, propertyIndex, errorMessage, __FILE__, __LINE__)
#define evalStringArrayPropertyAndJoin(flowState, componentIndex, propertyIndex, errorMessage, separator) _evalStringArrayPropertyAndJoin(flowState, componentIndex, propertyIndex, errorMessage, separator, __FILE__, __LINE__)

#define assignStringProperty(flowState, componentIndex, propertyIndex, value, errorMessage) _assignStringProperty(flowState, componentIndex, propertyIndex, value, errorMessage, __FILE__, __LINE__)
#define assignIntegerProperty(flowState, componentIndex, propertyIndex, value, errorMessage) _assignIntegerProperty(flowState, componentIndex, propertyIndex, value, errorMessage, __FILE__, __LINE__)
#define assignBooleanProperty(flowState, componentIndex, propertyIndex, value, errorMessage) _assignBooleanProperty(flowState, componentIndex, propertyIndex, value, errorMessage, __FILE__, __LINE__) 

// PRIVATE functions
const char *_evalTextProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *errorMessage, const char *file, int line);
int32_t _evalIntegerProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *errorMessage, const char *file, int line);
uint32_t _evalUnsignedIntegerProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *errorMessage, const char *file, int line);
bool _evalBooleanProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *errorMessage, const char *file, int line);
const char *_evalStringArrayPropertyAndJoin(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *errorMessage, const char *separator, const char *file, int line);

void _assignStringProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, const char *value, const char *errorMessage, const char *file, int line);
void _assignIntegerProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, int32_t value, const char *errorMessage, const char *file, int line);
void _assignBooleanProperty(void *flowState, unsigned componentIndex, unsigned propertyIndex, bool value, const char *errorMessage, const char *file, int line);
//

float eez_linear(float x);
float eez_easeInQuad(float x);
float eez_easeOutQuad(float x);
float eez_easeInOutQuad(float x);
float eez_easeInCubic(float x);
float eez_easeOutCubic(float x);
float eez_easeInOutCubic(float x);
float eez_easeInQuart(float x);
float eez_easeOutQuart(float x);
float eez_easeInOutQuart(float x);
float eez_easeInQuint(float x);
float eez_easeOutQuint(float x);
float eez_easeInOutQuint(float x);
float eez_easeInSine(float x);
float eez_easeOutSine(float x);
float eez_easeInOutSine(float x);
float eez_easeInExpo(float x);
float eez_easeOutExpo(float x);
float eez_easeInOutExpo(float x);
float eez_easeInCirc(float x);
float eez_easeOutCirc(float x);
float eez_easeInOutCirc(float x);
float eez_easeInBack(float x);
float eez_easeOutBack(float x);
float eez_easeInOutBack(float x);
float eez_easeInElastic(float x);
float eez_easeOutElastic(float x);
float eez_easeInOutElastic(float x);
float eez_easeOutBounce(float x);
float eez_easeInBounce(float x);
float eez_easeOutBounce(float x);
float eez_easeInOutBounce(float x);

float getTimelinePosition(void *flowState);

extern int g_eezFlowLvlgMeterTickIndex;

// returns 0 if options are equal, 1 if options are different
int compareRollerOptions(lv_roller_t *roller, const char *new_val, const char *cur_val, lv_roller_mode_t mode);

uint32_t eez_flow_get_selected_theme_index();

#ifdef __cplusplus
}
#endif

#endif // defined(EEZ_FOR_LVGL)

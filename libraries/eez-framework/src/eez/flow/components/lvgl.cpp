/*
 * eez-framework
 *
 * MIT License
 * Copyright 2024 Envox d.o.o.
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <eez/conf-internal.h>

#include <stdio.h>
#include <string.h>
#include <eez/core/os.h>

#include <eez/flow/components.h>
#include <eez/flow/flow_defs_v3.h>
#include <eez/flow/expression.h>
#include <eez/flow/private.h>
#include <eez/flow/queue.h>
#include <eez/flow/debugger.h>
#include <eez/flow/hooks.h>
#include <eez/flow/lvgl_api.h>

#include <eez/flow/components/lvgl.h>

#if defined(EEZ_FOR_LVGL)

namespace eez {
namespace flow {

////////////////////////////////////////////////////////////////////////////////

static void anim_callback_set_x(void *obj, int32_t v) { lv_obj_set_x((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_x(lv_anim_t * a) { return lv_obj_get_x_aligned((lv_obj_t *)a->user_data); }

static void anim_callback_set_y(void *obj, int32_t v) { lv_obj_set_y((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_y(lv_anim_t * a) { return lv_obj_get_y_aligned((lv_obj_t *)a->user_data); }

static void anim_callback_set_width(void *obj, int32_t v) { lv_obj_set_width((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_width(lv_anim_t * a) { return lv_obj_get_width((lv_obj_t *)a->user_data); }

static void anim_callback_set_height(void *obj, int32_t v) { lv_obj_set_height((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_height(lv_anim_t * a) { return lv_obj_get_height((lv_obj_t *)a->user_data); }

static void anim_callback_set_opacity(void *obj, int32_t v) { lv_obj_set_style_opa((lv_obj_t *)obj, v, 0); }
static int32_t anim_callback_get_opacity(lv_anim_t * a) { return lv_obj_get_style_opa((lv_obj_t *)a->user_data, 0); }

static void anim_callback_set_image_zoom(void *obj, int32_t v) { lv_img_set_zoom((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_image_zoom(lv_anim_t * a) { return lv_img_get_zoom((lv_obj_t *)a->user_data); }

static void anim_callback_set_image_angle(void *obj, int32_t v) { lv_img_set_angle((lv_obj_t *)obj, v); }
static int32_t anim_callback_get_image_angle(lv_anim_t * a) { return lv_img_get_angle((lv_obj_t *)a->user_data); }

lv_anim_exec_xcb_t anim_set_callbacks[] = {
    anim_callback_set_x,
    anim_callback_set_y,
    anim_callback_set_width,
    anim_callback_set_height,
    anim_callback_set_opacity,
    anim_callback_set_image_zoom,
    anim_callback_set_image_angle
};

lv_anim_get_value_cb_t anim_get_callbacks[] = {
    anim_callback_get_x,
    anim_callback_get_y,
    anim_callback_get_width,
    anim_callback_get_height,
    anim_callback_get_opacity,
    anim_callback_get_image_zoom,
    anim_callback_get_image_angle
};

int32_t (*anim_path_callbacks[])(const lv_anim_t *a) = {
    lv_anim_path_linear,
    lv_anim_path_ease_in,
    lv_anim_path_ease_out,
    lv_anim_path_ease_in_out,
    lv_anim_path_overshoot,
    lv_anim_path_bounce
};

////////////////////////////////////////////////////////////////////////////////

enum PropertyCode {
    NONE,

    ARC_VALUE,

    BAR_VALUE,

    BASIC_X,
    BASIC_Y,
    BASIC_WIDTH,
    BASIC_HEIGHT,
    BASIC_OPACITY,
    BASIC_HIDDEN,
    BASIC_CHECKED,
    BASIC_DISABLED,

    DROPDOWN_SELECTED,

    IMAGE_IMAGE,
    IMAGE_ANGLE,
    IMAGE_ZOOM,

    LABEL_TEXT,

    ROLLER_SELECTED,

    SLIDER_VALUE,

    KEYBOARD_TEXTAREA
};

////////////////////////////////////////////////////////////////////////////////

enum GroupActions {
    GROUP_ACTION_SET_WRAP = 0,
    GROUP_ACTION_FOCUS_OBJ = 1,
    GROUP_ACTION_FOCUS_NEXT = 2,
    GROUP_ACTION_FOCUS_PREVIOUS = 3,
    GROUP_ACTION_FOCUS_FREEZE = 4,
    GROUP_ACTION_SET_EDITING = 5
};

////////////////////////////////////////////////////////////////////////////////

// in case when getLvglObjectFromIndexHook returns nullptr, i.e. LVGL widget is not yet created, we need to store
// the index of the next action to be executed in the component execution state, so we can try later
struct LVGLExecutionState : public ComponenentExecutionState {
    uint32_t actionIndex;
};

void executeLVGLComponent(FlowState *flowState, unsigned componentIndex) {
    auto component = (LVGLComponent *)flowState->flow->components[componentIndex];

    auto executionState = (LVGLExecutionState *)flowState->componenentExecutionStates[componentIndex];

    for (uint32_t actionIndex = executionState ? executionState->actionIndex : 0; actionIndex < component->actions.count; actionIndex++) {
        auto general = (LVGLComponent_ActionType *)component->actions[actionIndex];
        if (general->action == CHANGE_SCREEN) {
            auto specific = (LVGLComponent_ChangeScreen_ActionType *)general;
            if (specific->screen == -1) {
                eez_flow_pop_screen((lv_scr_load_anim_t)specific->fadeMode, specific->speed, specific->delay);
            } else {
                eez_flow_push_screen(specific->screen, (lv_scr_load_anim_t)specific->fadeMode, specific->speed, specific->delay);
            }
        } else if (general->action == PLAY_ANIMATION) {
            auto specific = (LVGLComponent_PlayAnimation_ActionType *)general;

            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            }

            lv_anim_t anim;
            lv_anim_init(&anim);

            lv_anim_set_time(&anim, specific->time);
            lv_anim_set_user_data(&anim, target);
            lv_anim_set_var(&anim, target);
            lv_anim_set_exec_cb(&anim, anim_set_callbacks[specific->property]);
            lv_anim_set_values(&anim, specific->start, specific->end);
            lv_anim_set_path_cb(&anim, anim_path_callbacks[specific->path]);
            lv_anim_set_delay(&anim, specific->delay);
            lv_anim_set_early_apply(&anim, specific->flags & ANIMATION_ITEM_FLAG_INSTANT ? true : false);
            if (specific->flags & ANIMATION_ITEM_FLAG_RELATIVE) {
                lv_anim_set_get_value_cb(&anim, anim_get_callbacks[specific->property]);
            }

            lv_anim_start(&anim);
        } else if (general->action == SET_PROPERTY) {
            auto specific = (LVGLComponent_SetProperty_ActionType *)general;

            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            }

            if (specific->property == KEYBOARD_TEXTAREA) {
                auto textarea = specific->textarea != -1 ? getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->textarea) : nullptr;
                if (!textarea) {
                    if (!executionState) {
                        executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                    }
                    executionState->actionIndex = actionIndex;
                    addToQueue(flowState, componentIndex, -1, -1, -1, true);
                    return;
                }
                lv_keyboard_set_textarea(target, textarea);
            } else {
                Value value;
                if (!evalExpression(flowState, componentIndex, specific->value, value, FlowError::PropertyInAction("LVGL Set Property", "Value", actionIndex))) {
                    return;
                }

                if (specific->property == IMAGE_IMAGE || specific->property == LABEL_TEXT) {
                    const char *strValue = value.toString(0xe42b3ca2).getString();
                    if (specific->property == IMAGE_IMAGE) {
                        const void *src = getLvglImageByNameHook(strValue);
                        if (src) {
                            lv_img_set_src(target, src);
                        } else {
                            throwError(flowState, componentIndex, FlowError::NotFoundInAction("Image", strValue, "LVGL Set Property", actionIndex));
                        }
                    } else {
                        lv_label_set_text(target, strValue ? strValue : "");
                    }
                } else if (specific->property == BASIC_HIDDEN) {
                    int err;
                    bool booleanValue = value.toBool(&err);
                    if (err) {
                        throwError(flowState, componentIndex, FlowError::PropertyInActionConvert("LVGL Set Property", "Value", "boolean", actionIndex));
                        return;
                    }

                    lv_obj_flag_t flag = LV_OBJ_FLAG_HIDDEN;

                    if (booleanValue) lv_obj_add_flag(target, flag);
                    else lv_obj_clear_flag(target, flag);
                } else if (specific->property == BASIC_CHECKED || specific->property == BASIC_DISABLED) {
                    int err;
                    bool booleanValue = value.toBool(&err);
                    if (err) {
                        throwError(flowState, componentIndex, FlowError::PropertyInActionConvert("LVGL Set Property", "Value", "boolean", actionIndex));
                        return;
                    }

                    lv_state_t state = specific->property == BASIC_CHECKED ? LV_STATE_CHECKED : LV_STATE_DISABLED;

                    if (booleanValue) lv_obj_add_state(target, state);
                    else lv_obj_clear_state(target, state);
                } else {
                    int err;
                    int32_t intValue = value.toInt32(&err);
                    if (err) {
                        throwError(flowState, componentIndex, FlowError::PropertyInActionConvert("LVGL Set Property", "Value", "integer", actionIndex));
                        return;
                    }

                    if (specific->property == ARC_VALUE) {
                        lv_arc_set_value(target, intValue);
                    } else if (specific->property == BAR_VALUE) {
                        lv_bar_set_value(target, intValue, specific->animated ? LV_ANIM_ON : LV_ANIM_OFF);
                    } else if (specific->property == BASIC_X) {
                        lv_obj_set_x(target, intValue);
                    } else if (specific->property == BASIC_Y) {
                        lv_obj_set_y(target, intValue);
                    } else if (specific->property == BASIC_WIDTH) {
                        lv_obj_set_width(target, intValue);
                    } else if (specific->property == BASIC_HEIGHT) {
                        lv_obj_set_height(target, intValue);
                    } else if (specific->property == BASIC_OPACITY) {
                        lv_obj_set_style_opa(target, intValue, 0);
                    } else if (specific->property == DROPDOWN_SELECTED) {
                        lv_dropdown_set_selected(target, intValue);
                    } else if (specific->property == IMAGE_ANGLE) {
                        lv_img_set_angle(target, intValue);
                    } else if (specific->property == IMAGE_ZOOM) {
                        lv_img_set_zoom(target, intValue);
                    } else if (specific->property == ROLLER_SELECTED) {
                        lv_roller_set_selected(target, intValue, specific->animated ? LV_ANIM_ON : LV_ANIM_OFF);
                    } else if (specific->property == SLIDER_VALUE) {
                        lv_slider_set_value(target, intValue, specific->animated ? LV_ANIM_ON : LV_ANIM_OFF);
                    }
                }
            }
            lv_obj_update_layout(target);
        } else if (general->action == ADD_STYLE) {
            auto specific = (LVGLComponent_AddStyle_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lvglObjAddStyleHook(target, specific->style);
            }
        } else if (general->action == REMOVE_STYLE) {
            auto specific = (LVGLComponent_RemoveStyle_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lvglObjRemoveStyleHook(target, specific->style);
            }
        } else if (general->action == ADD_FLAG) {
            auto specific = (LVGLComponent_AddFlag_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lv_obj_add_flag(target, (lv_obj_flag_t)specific->flag);
            }
        } else if (general->action == CLEAR_FLAG) {
            auto specific = (LVGLComponent_ClearFlag_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lv_obj_clear_flag(target, (lv_obj_flag_t)specific->flag);
            }
        } else if (general->action == GROUP) {
            auto specific = (LVGLComponent_Group_ActionType *)general;

            if (specific->groupAction == GROUP_ACTION_SET_WRAP) {
                auto target = getLvglGroupFromIndexHook(specific->target);
                if (target) {
                    lv_group_set_wrap(target, specific->enable ? true : false);
                }
            } else if (specific->groupAction == GROUP_ACTION_FOCUS_OBJ) {
                auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
                if (!target) {
                    if (!executionState) {
                        executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                    }
                    executionState->actionIndex = actionIndex;
                    addToQueue(flowState, componentIndex, -1, -1, -1, true);
                    return;
                } else {
                    lv_group_focus_obj(target);
                }
            } else if (specific->groupAction == GROUP_ACTION_FOCUS_NEXT) {
                auto target = getLvglGroupFromIndexHook(specific->target);
                if (target) {
                    lv_group_focus_next(target);
                }
            } else if (specific->groupAction == GROUP_ACTION_FOCUS_PREVIOUS) {
                auto target = getLvglGroupFromIndexHook(specific->target);
                if (target) {
                    lv_group_focus_prev(target);
                }
            } else if (specific->groupAction == GROUP_ACTION_FOCUS_FREEZE) {
                auto target = getLvglGroupFromIndexHook(specific->target);
                if (target) {
                    lv_group_focus_freeze(target, specific->enable ? true : false);
                }
            } else {
                // specific->groupAction == GROUP_ACTION_SET_EDITING
                auto target = getLvglGroupFromIndexHook(specific->target);
                if (target) {
                    lv_group_set_editing(target, specific->enable ? true : false);
                }
            }
        } else if (general->action == ADD_STATE) {
            auto specific = (LVGLComponent_AddState_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lv_obj_add_state(target, (lv_state_t)specific->state);
            }
        } else if (general->action == CLEAR_STATE) {
            auto specific = (LVGLComponent_ClearState_ActionType *)general;
            auto target = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + specific->target);
            if (!target) {
                if (!executionState) {
                    executionState = allocateComponentExecutionState<LVGLExecutionState>(flowState, componentIndex);
                }
                executionState->actionIndex = actionIndex;
                addToQueue(flowState, componentIndex, -1, -1, -1, true);
                return;
            } else {
                lv_obj_clear_state(target, (lv_state_t)specific->state);
            }
        }

    }

    propagateValueThroughSeqout(flowState, componentIndex);
}

////////////////////////////////////////////////////////////////////////////////

#define ACTION_START(NAME) static void NAME(FlowState *flowState, unsigned componentIndex, const ListOfAssetsPtr<Property> &properties, uint32_t actionIndex) { \
    const char *actionName = #NAME; \
    int propIndex = 0;

#define INT8_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int8_t NAME = NAME##Value.getInt8();

#define UINT8_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    uint8_t NAME = NAME##Value.getUInt8();

#define INT16_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int16_t NAME = NAME##Value.getInt16();

#define UINT16_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    uint16_t NAME = NAME##Value.getUInt16();

#define INT32_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int32_t NAME = NAME##Value.getInt();

#define UINT32_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    uint32_t NAME = NAME##Value.getUInt32();

#define BOOL_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int32_t NAME = NAME##Value.getBoolean();

#define STR_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    const char *NAME = NAME##Value.toString(0xe42b3ca2).getString();

#define SCREEN_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int32_t NAME; \
    if (NAME##Value.isString()) { \
        const char *screenName = NAME##Value.getString(); \
        NAME = getLvglScreenByNameHook(screenName); \
        if (NAME == 0) { \
            throwError(flowState, componentIndex, FlowError::NotFoundInAction("Screen", screenName, actionName, actionIndex)); \
            return; \
        } \
    } else { \
        NAME = NAME##Value.getInt(); \
    }

#define WIDGET_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    lv_obj_t *NAME; \
    if (NAME##Value.isWidget()) { \
        NAME = (lv_obj_t *)NAME##Value.getWidget(); \
    } else if (NAME##Value.isString()) { \
        const char *objectName = NAME##Value.getString(); \
        int32_t widgetIndex = getLvglObjectByNameHook(objectName); \
        if (widgetIndex == -1) { \
            throwError(flowState, componentIndex, FlowError::NotFoundInAction("Widget", objectName, actionName, actionIndex)); \
            return; \
        } \
        NAME = getLvglObjectFromIndexHook(flowState->lvglWidgetStartIndex + widgetIndex); \
    } else { \
        int32_t widgetIndex = NAME##Value.getInt(); \
        for (FlowState *fs = flowState; fs; fs = fs->parentFlowState) widgetIndex += fs->lvglWidgetStartIndex; \
        NAME = getLvglObjectFromIndexHook(widgetIndex); \
    } \
    if (!NAME) { \
        throwError(flowState, componentIndex, FlowError::NullInAction("Widget", actionName, actionIndex)); \
        return; \
    }

#define GROUP_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    lv_group_t *NAME; \
    if (NAME##Value.isString()) { \
        const char *groupName = NAME##Value.getString(); \
        int32_t NAME##_GroupIndex = getLvglGroupByNameHook(groupName); \
        if (NAME##_GroupIndex == -1) { \
            throwError(flowState, componentIndex, FlowError::NotFoundInAction("Group", groupName, actionName, actionIndex)); \
            return; \
        } \
        NAME = getLvglGroupFromIndexHook(NAME##_GroupIndex); \
    } else { \
        int32_t NAME##_GroupIndex = NAME##Value.getInt(); \
        NAME = getLvglGroupFromIndexHook(NAME##_GroupIndex); \
    } \
    if (!NAME) { \
        throwError(flowState, componentIndex, FlowError::NullInAction("Group", actionName, actionIndex)); \
        return; \
    }

#define STYLE_PROP(NAME) \
    Value NAME##Value; \
    if (!evalExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    int32_t NAME; \
    if (NAME##Value.isString()) { \
        const char *styleName = NAME##Value.getString(); \
        NAME = getLvglStyleByNameHook(styleName); \
        if (NAME == -1) { \
            throwError(flowState, componentIndex, FlowError::NotFoundInAction("Style", styleName, actionName, actionIndex)); \
            return; \
        } \
    } else { \
        NAME = NAME##Value.getInt(); \
    }

#define RESULT(NAME, VALUE) \
    Value NAME##Value; \
    if (!evalAssignableExpression(flowState, componentIndex, properties[propIndex]->evalInstructions, NAME##Value, FlowError::PropertyAssignInAction(#NAME, actionName, actionIndex))) { \
        return; \
    }\
    propIndex++; \
    assignValue(flowState, componentIndex, NAME##Value, VALUE);

#define ACTION_END }

////////////////////////////////////////////////////////////////////////////////

ACTION_START(changeScreen)
    SCREEN_PROP(screen);
    INT32_PROP(fadeMode);
    UINT32_PROP(speed);
    UINT32_PROP(delay);
    if (properties.count > 4) {
        BOOL_PROP(useStack);
        if (useStack) {
            eez_flow_push_screen(screen, (lv_scr_load_anim_t)fadeMode, speed, delay);
        } else {
            eez::flow::replacePageHook(screen, (lv_scr_load_anim_t)fadeMode, speed, delay);
        }
    } else {
        eez_flow_push_screen(screen, (lv_scr_load_anim_t)fadeMode, speed, delay);
    }
ACTION_END

ACTION_START(changeToPreviousScreen)
    INT32_PROP(fadeMode);
    UINT32_PROP(speed);
    UINT32_PROP(delay);
    eez_flow_pop_screen((lv_scr_load_anim_t)fadeMode, speed, delay);
ACTION_END

ACTION_START(objSetX)
    WIDGET_PROP(obj);
    INT32_PROP(x);
#if LVGL_VERSION_MAJOR >= 9
    lv_obj_set_x(obj, x);
#else
    lv_obj_set_x(obj, (lv_coord_t)x);
#endif
ACTION_END

ACTION_START(objGetX)
    WIDGET_PROP(obj);
#if LVGL_VERSION_MAJOR >= 9
    int32_t x = (int32_t)lv_obj_get_x(obj);
#else
    int32_t x = lv_obj_get_x(obj);
#endif
    RESULT(result, Value((int)x, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(objSetY)
    WIDGET_PROP(obj);
    INT32_PROP(y);
#if LVGL_VERSION_MAJOR >= 9
    lv_obj_set_y(obj, y);
#else
    lv_obj_set_y(obj, (lv_coord_t)y);
#endif
ACTION_END

ACTION_START(objGetY)
    WIDGET_PROP(obj);
#if LVGL_VERSION_MAJOR >= 9
    int32_t y = (int32_t)lv_obj_get_y(obj);
#else
    int32_t y = lv_obj_get_y(obj);
#endif
    RESULT(result, Value((int)y, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(objSetWidth)
    WIDGET_PROP(obj);
    INT32_PROP(width);
#if LVGL_VERSION_MAJOR >= 9
    lv_obj_set_width(obj, width);
#else
    lv_obj_set_width(obj, (lv_coord_t)width);
#endif
ACTION_END

ACTION_START(objGetWidth)
    WIDGET_PROP(obj);
#if LVGL_VERSION_MAJOR >= 9
    int32_t width = (int32_t)lv_obj_get_width(obj);
#else
    int32_t width = lv_obj_get_width(obj);
#endif
    RESULT(result, Value((int)width, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(objSetHeight)
    WIDGET_PROP(obj);
    INT32_PROP(height);
#if LVGL_VERSION_MAJOR >= 9
    lv_obj_set_height(obj, height);
#else
    lv_obj_set_height(obj, (lv_coord_t)height);
#endif
ACTION_END

ACTION_START(objGetHeight)
    WIDGET_PROP(obj);
#if LVGL_VERSION_MAJOR >= 9
    int32_t height = (int32_t)lv_obj_get_height(obj);
#else
    int32_t height = lv_obj_get_height(obj);
#endif
    RESULT(result, Value((int)height, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(objSetStyleOpa)
    WIDGET_PROP(obj);
    INT32_PROP(opa);
    lv_obj_set_style_opa(obj, (lv_opa_t)opa, 0);
ACTION_END

ACTION_START(objGetStyleOpa)
    WIDGET_PROP(obj);
    int32_t opa = (int32_t)lv_obj_get_style_opa(obj, 0);
    RESULT(result, Value((int)opa, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(objAddStyle)
    WIDGET_PROP(obj);
    STYLE_PROP(style);
    lvglObjAddStyleHook(obj, style);
ACTION_END

ACTION_START(objRemoveStyle)
    WIDGET_PROP(obj);
    STYLE_PROP(style);
    lvglObjRemoveStyleHook(obj, style);
ACTION_END

ACTION_START(objSetFlagHidden)
    WIDGET_PROP(obj);
    BOOL_PROP(hidden);
    if (hidden) lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
    else lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
ACTION_END

ACTION_START(objAddFlag)
    WIDGET_PROP(obj);
    INT32_PROP(flag);
    lv_obj_add_flag(obj, (lv_obj_flag_t)flag);
ACTION_END

ACTION_START(objClearFlag)
    WIDGET_PROP(obj);
    INT32_PROP(flag);
    lv_obj_clear_flag(obj, (lv_obj_flag_t)flag);
ACTION_END

ACTION_START(objHasFlag)
    WIDGET_PROP(obj);
    INT32_PROP(flag);
    bool result = lv_obj_has_flag(obj, (lv_obj_flag_t)flag);
    RESULT(result, Value(result, VALUE_TYPE_BOOLEAN));
ACTION_END

ACTION_START(objSetStateChecked)
    WIDGET_PROP(obj);
    BOOL_PROP(checked);
    if (checked) lv_obj_add_state(obj, LV_STATE_CHECKED);
    else lv_obj_clear_state(obj, LV_STATE_CHECKED);
ACTION_END

ACTION_START(objSetStateDisabled)
    WIDGET_PROP(obj);
    BOOL_PROP(disabled);
    if (disabled) lv_obj_add_state(obj, LV_STATE_DISABLED);
    else lv_obj_clear_state(obj, LV_STATE_DISABLED);
ACTION_END

ACTION_START(objAddState)
    WIDGET_PROP(obj);
    INT32_PROP(state);
    lv_obj_add_state(obj, (lv_state_t)state);
ACTION_END

ACTION_START(objClearState)
    WIDGET_PROP(obj);
    INT32_PROP(state);
    lv_obj_clear_state(obj, (lv_state_t)state);
ACTION_END

ACTION_START(objHasState)
    WIDGET_PROP(obj);
    INT32_PROP(flag);
    bool result = lv_obj_has_state(obj, (lv_state_t)flag);
    RESULT(result, Value(result, VALUE_TYPE_BOOLEAN));
ACTION_END

ACTION_START(arcSetValue)
    WIDGET_PROP(obj);
    INT32_PROP(value);
    lv_arc_set_value(obj, value);
ACTION_END

ACTION_START(barSetValue)
    WIDGET_PROP(obj);
    INT32_PROP(value);
    BOOL_PROP(animated);
    lv_bar_set_value(obj, value, animated ? LV_ANIM_ON : LV_ANIM_OFF);
ACTION_END

ACTION_START(dropdownSetSelected)
    WIDGET_PROP(obj);
    UINT32_PROP(value);
#if LVGL_VERSION_MAJOR >= 9
    lv_dropdown_set_selected(obj, value);
#else
    lv_dropdown_set_selected(obj, (uint16_t)value);
#endif
ACTION_END

ACTION_START(imageSetSrc)
    WIDGET_PROP(obj);
    STR_PROP(str);
    const void *src = getLvglImageByNameHook(str);
    if (src) {
        lv_img_set_src(obj, src);
    } else {
        throwError(flowState, componentIndex, FlowError::NotFoundInAction("Image", str, "imageSetSrc", actionIndex));
    }
ACTION_END

ACTION_START(imageSetAngle)
    WIDGET_PROP(obj);
    INT16_PROP(angle);
    lv_img_set_angle(obj, angle);
ACTION_END

ACTION_START(imageSetZoom)
    WIDGET_PROP(obj);
    UINT16_PROP(zoom);
    lv_img_set_zoom(obj, zoom);
ACTION_END

ACTION_START(labelSetText)
    WIDGET_PROP(obj);
    STR_PROP(text);
    lv_label_set_text(obj, text);
ACTION_END

ACTION_START(qrCodeUpdate)
    WIDGET_PROP(obj);
    STR_PROP(text);
#if LV_USE_QRCODE
    lv_qrcode_update(obj, text, strlen(text));
#endif
ACTION_END

ACTION_START(rollerSetSelected)
    WIDGET_PROP(obj);
    UINT32_PROP(selected);
    BOOL_PROP(animated);
#if LVGL_VERSION_MAJOR >= 9
    lv_roller_set_selected(obj, selected, animated ? LV_ANIM_ON : LV_ANIM_OFF);
#else
    lv_roller_set_selected(obj, (uint16_t)selected, animated ? LV_ANIM_ON : LV_ANIM_OFF);
#endif
ACTION_END

ACTION_START(sliderSetValue)
    WIDGET_PROP(obj);
    INT32_PROP(value);
    BOOL_PROP(animated);
    lv_slider_set_value(obj, value, animated ? LV_ANIM_ON : LV_ANIM_OFF);
ACTION_END

ACTION_START(sliderSetValueLeft)
    WIDGET_PROP(obj);
    INT32_PROP(valueLeft);
    BOOL_PROP(animated);
    lv_slider_set_left_value(obj, valueLeft, animated ? LV_ANIM_ON : LV_ANIM_OFF);
ACTION_END

ACTION_START(sliderSetRange)
    WIDGET_PROP(obj);
    INT32_PROP(min);
    INT32_PROP(max);
    lv_slider_set_range(obj, min, max);
ACTION_END

ACTION_START(keyboardSetTextarea)
    WIDGET_PROP(obj);
    WIDGET_PROP(textarea);
    lv_keyboard_set_textarea(obj, textarea);
ACTION_END

ACTION_START(groupFocusObj)
    WIDGET_PROP(obj);
    lv_group_focus_obj(obj);
ACTION_END

ACTION_START(groupFocusNext)
    GROUP_PROP(group);
    lv_group_focus_next(group);
ACTION_END

ACTION_START(groupFocusPrev)
    GROUP_PROP(group);
    lv_group_focus_prev(group);
ACTION_END

ACTION_START(groupGetFocused)
    GROUP_PROP(group);
    lv_obj_t *obj = lv_group_get_focused(group);
    RESULT(result, Value(obj, VALUE_TYPE_WIDGET));
ACTION_END

ACTION_START(groupFocusFreeze)
    GROUP_PROP(group);
    BOOL_PROP(enabled);
    lv_group_focus_freeze(group, enabled);
ACTION_END

ACTION_START(groupSetWrap)
    GROUP_PROP(group);
    BOOL_PROP(enabled);
    lv_group_set_wrap(group, enabled);
ACTION_END

ACTION_START(groupSetEditing)
    GROUP_PROP(group);
    BOOL_PROP(enabled);
    lv_group_set_editing(group, enabled);
ACTION_END

#define ANIM_PROPS \
    WIDGET_PROP(obj); \
    INT32_PROP(start); \
    INT32_PROP(end); \
    INT32_PROP(delay); \
    INT32_PROP(time); \
    BOOL_PROP(relative); \
    BOOL_PROP(instant); \
    INT32_PROP(path);

static void playAnimation(lv_obj_t *obj,
    int32_t start,
    int32_t end,
    int32_t delay,
    int32_t time,
    bool relative,
    bool instant,
    int32_t path,
    lv_anim_exec_xcb_t set_callback,
    lv_anim_get_value_cb_t get_callback
) {
    lv_anim_t anim;
    lv_anim_init(&anim);

    lv_anim_set_time(&anim, time);
    lv_anim_set_user_data(&anim, obj);
    lv_anim_set_var(&anim, obj);
    lv_anim_set_exec_cb(&anim, set_callback);
    lv_anim_set_values(&anim, start, end);
    lv_anim_set_path_cb(&anim, anim_path_callbacks[path]);
    lv_anim_set_delay(&anim, delay);
    lv_anim_set_early_apply(&anim, instant ? true : false);
    if (relative) {
        lv_anim_set_get_value_cb(&anim, get_callback);
    }

    lv_anim_start(&anim);
}

ACTION_START(animX)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_x, anim_callback_get_x);
ACTION_END

ACTION_START(animY)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_y, anim_callback_get_y);
ACTION_END

ACTION_START(animWidth)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_width, anim_callback_get_width);
ACTION_END

ACTION_START(animHeight)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_height, anim_callback_get_height);
ACTION_END

ACTION_START(animOpacity)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_opacity, anim_callback_get_opacity);
ACTION_END

ACTION_START(animImageZoom)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_image_zoom, anim_callback_get_image_zoom);
ACTION_END

ACTION_START(animImageAngle)
    ANIM_PROPS;
    playAnimation(obj, start, end, delay, time, relative, instant, path, anim_callback_set_image_angle, anim_callback_get_image_angle);
ACTION_END

ACTION_START(createScreen)
    SCREEN_PROP(screen);
    eez_flow_create_screen(screen);
ACTION_END

ACTION_START(deleteScreen)
    SCREEN_PROP(screen);
    eez_flow_delete_screen(screen);
ACTION_END

ACTION_START(isScreenCreated)
    SCREEN_PROP(screen);
    bool isCreated = eez_flow_is_screen_created(screen);
    RESULT(result, Value(isCreated, VALUE_TYPE_BOOLEAN));
ACTION_END

ACTION_START(calendarSetTodayDate)
    WIDGET_PROP(obj);
    UINT32_PROP(year);
    UINT32_PROP(month);
    UINT32_PROP(day);
    lv_calendar_set_today_date(obj, year, month, day);
ACTION_END

ACTION_START(calendarSetShowedDate)
    WIDGET_PROP(obj);
    UINT32_PROP(year);
    UINT32_PROP(month);
    lv_calendar_set_showed_date(obj, year, month);
ACTION_END

ACTION_START(calendarSetHighlightedDate)
    WIDGET_PROP(obj);
    UINT32_PROP(year);
    UINT32_PROP(month);
    UINT32_PROP(day);
    lv_calendar_date_t d;
    d.year = year;
    d.month = month;
    d.day = day;
    lv_calendar_set_highlighted_dates(obj, &d, 1);
ACTION_END

ACTION_START(calendarGetPressedDate)
    WIDGET_PROP(obj);
    lv_calendar_date_t d;
    lv_calendar_get_pressed_date(obj, &d);
    RESULT(year, Value((int)d.year, VALUE_TYPE_INT32));
    RESULT(month, Value((int)d.month, VALUE_TYPE_INT32));
    RESULT(day, Value((int)d.day, VALUE_TYPE_INT32));
ACTION_END

ACTION_START(buttonMatrixSetButtonCtrl)
    WIDGET_PROP(obj);
    UINT32_PROP(buttonID);
    UINT32_PROP(ctrl);
#if LVGL_VERSION_MAJOR >= 9
    lv_buttonmatrix_set_button_ctrl(obj, buttonID, (lv_buttonmatrix_ctrl_t)ctrl);
#else
    lv_btnmatrix_set_btn_ctrl(obj, buttonID, (lv_btnmatrix_ctrl_t)ctrl);
#endif
ACTION_END

ACTION_START(buttonMatrixClearButtonCtrl)
    WIDGET_PROP(obj);
    UINT32_PROP(buttonID);
    UINT32_PROP(ctrl);
#if LVGL_VERSION_MAJOR >= 9
    lv_buttonmatrix_clear_button_ctrl(obj, buttonID, (lv_buttonmatrix_ctrl_t)ctrl);
#else
    lv_btnmatrix_set_btn_ctrl(obj, buttonID, (lv_btnmatrix_ctrl_t)ctrl);
#endif
ACTION_END

////////////////////////////////////////////////////////////////////////////////

typedef void (*ActionType)(FlowState *flowState, unsigned componentIndex, const ListOfAssetsPtr<Property> &properties, uint32_t actionIndex);

static ActionType actions[] = {
    /* 0 */ &changeScreen,
    /* 1 */ &changeToPreviousScreen,
    /* 2 */ &objSetX,
    /* 3 */ &objGetX,
    /* 4 */ &objSetY,
    /* 5 */ &objGetY,
    /* 6 */ &objSetWidth,
    /* 7 */ &objGetWidth,
    /* 8 */ &objSetHeight,
    /* 9 */ &objGetHeight,
    /* 10 */ &objSetStyleOpa,
    /* 11 */ &objGetStyleOpa,
    /* 12 */ &objAddStyle,
    /* 13 */ &objRemoveStyle,
    /* 14 */ &objSetFlagHidden,
    /* 15 */ &objAddFlag,
    /* 16 */ &objClearFlag,
    /* 17 */ &objHasFlag,
    /* 18 */ &objSetStateChecked,
    /* 19 */ &objSetStateDisabled,
    /* 20 */ &objAddState,
    /* 21 */ &objClearState,
    /* 22 */ &objHasState,
    /* 23 */ &arcSetValue,
    /* 24 */ &barSetValue,
    /* 25 */ &dropdownSetSelected,
    /* 26 */ &imageSetSrc,
    /* 27 */ &imageSetAngle,
    /* 28 */ &imageSetZoom,
    /* 29 */ &labelSetText,
    /* 30 */ &rollerSetSelected,
    /* 31 */ &sliderSetValue,
    /* 32 */ &keyboardSetTextarea,
    /* 33 */ &groupFocusObj,
    /* 34 */ &groupFocusNext,
    /* 35 */ &groupFocusPrev,
    /* 36 */ &groupGetFocused,
    /* 37 */ &groupFocusFreeze,
    /* 38 */ &groupSetWrap,
    /* 39 */ &groupSetEditing,
    /* 40 */ &animX,
    /* 41 */ &animY,
    /* 42 */ &animWidth,
    /* 43 */ &animHeight,
    /* 44 */ &animOpacity,
    /* 45 */ &animImageZoom,
    /* 46 */ &animImageAngle,
    /* 47 */ &createScreen,
    /* 48 */ &deleteScreen,
    /* 49 */ &isScreenCreated,
    /* 50 */ &calendarSetTodayDate,
    /* 51 */ &calendarSetShowedDate,
    /* 52 */ &calendarSetHighlightedDate,
    /* 53 */ &calendarGetPressedDate,
    /* 54 */ &buttonMatrixSetButtonCtrl,
    /* 55 */ &buttonMatrixClearButtonCtrl,
    /* 56 */ &sliderSetValueLeft,
    /* 57 */ &sliderSetRange,
    /* 58 */ &qrCodeUpdate
};

////////////////////////////////////////////////////////////////////////////////

// in case when getLvglObjectFromIndexHook returns nullptr, i.e. LVGL widget is not yet created, we need to store
// the index of the next action to be executed in the component execution state, so we can try later
struct LVGLApiExecutionState : public ComponenentExecutionState {
    uint32_t actionIndex;
};


void executeLVGLApiComponent(FlowState *flowState, unsigned componentIndex) {
    auto component = (LVGLApiComponent *)flowState->flow->components[componentIndex];

    auto executionState = (LVGLApiExecutionState *)flowState->componenentExecutionStates[componentIndex];

    for (uint32_t actionIndex = executionState ? executionState->actionIndex : 0; actionIndex < component->actions.count; actionIndex++) {
        // printf("actionIndex: %d\n", actionIndex + 1);
        auto actionType = (LVGLApiComponent_ActionType *)component->actions[actionIndex];
        (*actions[actionType->action])(flowState, componentIndex, actionType->properties, actionIndex);
    }

    propagateValueThroughSeqout(flowState, componentIndex);
}

} // namespace flow
} // namespace eez


#else

namespace eez {
namespace flow {

void executeLVGLComponent(FlowState *flowState, unsigned componentIndex) {
    throwError(flowState, componentIndex, FlowError::Plain("Not implemented"));
}

void executeLVGLApiComponent(FlowState *flowState, unsigned componentIndex) {
    throwError(flowState, componentIndex, FlowError::Plain("Not implemented"));
}

} // namespace flow
} // namespace eez

#endif

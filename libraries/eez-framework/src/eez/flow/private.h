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

#include <eez/core/os.h>
#include <eez/core/assets.h>
#include <eez/core/value.h>

#if EEZ_OPTION_GUI
#include <eez/gui/gui.h>
using namespace eez::gui;
#endif

namespace eez {
namespace flow {

struct GlobalVariables {
    uint32_t count;
    Value values[1];
};

extern struct GlobalVariables *g_globalVariables;

void initGlobalVariables(Assets *assets);

static const int UNDEFINED_VALUE_INDEX = 0;
static const int NULL_VALUE_INDEX = 1;

#define TRACK_REF_COUNTER_FOR_COMPONENT_STATE(component) \
    !( \
        component->type == defs_v3::COMPONENT_TYPE_INPUT_ACTION || \
        component->type == defs_v3::COMPONENT_TYPE_LOOP_ACTION || \
        component->type == defs_v3::COMPONENT_TYPE_COUNTER_ACTION || \
        component->type == defs_v3::COMPONENT_TYPE_WATCH_VARIABLE_ACTION \
    )

struct ComponenentExecutionState {
	virtual ~ComponenentExecutionState() {}
};

struct CatchErrorComponenentExecutionState : public ComponenentExecutionState {
	Value message;
};

struct FlowState {
	uint32_t flowStateIndex;
	Assets *assets;
	FlowDefinition *flowDefinition;
	Flow *flow;
	uint16_t flowIndex;
	bool isAction;
	bool error;
    bool deleteOnNextTick;

    // Used for freeing flow state. While this is greater than 0, flow state cannot be freed
    // because it is still active. It is active if:
    //   - there is component in the queue
    //   - there is async component
    //   - there is component with execution state (not all components are tracked, check TRACK_REF_COUNTER_FOR_COMPONENT_STATE)
    //   - there is watch component in watch_list
    uint32_t refCounter;

    FlowState *parentFlowState;
	Component *parentComponent;
	int parentComponentIndex;

    // in case of action flow state, this is the input value that was passed to all action inputs, if such exists
    Value inputValue;

    Value *values;
	ComponenentExecutionState **componenentExecutionStates;
    bool *componenentAsyncStates;
    unsigned executingComponentIndex;
    float timelinePosition;
#if defined(EEZ_FOR_LVGL)
    int32_t lvglWidgetStartIndex;
#endif
    Value eventValue;

    FlowState *firstChild;
    FlowState *lastChild;
    FlowState *previousSibling;
    FlowState *nextSibling;
};

extern int g_selectedLanguage;
extern FlowState *g_firstFlowState;
extern FlowState *g_lastFlowState;

FlowState *initActionFlowState(int flowIndex, FlowState *parentFlowState, int parentComponentIndex, const Value &value);
FlowState *initPageFlowState(Assets *assets, int flowIndex, FlowState *parentFlowState, int parentComponentIndex);

void incRefCounterForFlowState(FlowState *flowState);
void decRefCounterForFlowState(FlowState *flowState);

bool canFreeFlowState(FlowState *flowState);
void freeFlowState(FlowState *flowState);
void freeAllChildrenFlowStates(FlowState *flowState);

void deallocateComponentExecutionState(FlowState *flowState, unsigned componentIndex);

extern void onComponentExecutionStateChanged(FlowState *flowState, int componentIndex);
template<class T>
T *allocateComponentExecutionState(FlowState *flowState, unsigned componentIndex) {
    if (flowState->componenentExecutionStates[componentIndex]) {
        deallocateComponentExecutionState(flowState, componentIndex);
    }
    auto executionState = ObjectAllocator<T>::allocate(0x72dc3bf4);
    flowState->componenentExecutionStates[componentIndex] = executionState;

    auto component = flowState->flow->components[componentIndex];
    if (TRACK_REF_COUNTER_FOR_COMPONENT_STATE(component)) {
        incRefCounterForFlowState(flowState);
    }

    onComponentExecutionStateChanged(flowState, componentIndex);
    return executionState;
}

void resetSequenceInputs(FlowState *flowState);

void propagateValue(FlowState *flowState, unsigned componentIndex, unsigned outputIndex, const Value &value);
void propagateValue(FlowState *flowState, unsigned componentIndex, unsigned outputIndex); // propagates null value
void propagateValueThroughSeqout(FlowState *flowState, unsigned componentIndex); // propagates null value through @seqout (0-th output)

#if EEZ_OPTION_GUI
void getValue(uint16_t dataId, DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value);
void setValue(uint16_t dataId, const WidgetCursor &widgetCursor, const Value& value);
#endif

void assignValue(FlowState *flowState, int componentIndex, Value &dstValue, const Value &srcValue);

void clearInputValue(FlowState *flowState, int inputIndex);

void startAsyncExecution(FlowState *flowState, int componentIndex);
void endAsyncExecution(FlowState *flowState, int componentIndex);

void executeCallAction(FlowState *flowState, unsigned componentIndex, int flowIndex, const Value& value);

extern FlowState *g_executeActionFlowState;
extern unsigned g_executeActionComponentIndex;

enum FlowEvent {
    FLOW_EVENT_OPEN_PAGE,
    FLOW_EVENT_CLOSE_PAGE,
    FLOW_EVENT_KEYDOWN
};

void onEvent(FlowState *flowState, FlowEvent flowEvent, Value eventValue);

enum FlowErrorType {
    FLOW_ERROR_PLAIN,
    FLOW_ERROR_PROPERTY,
    FLOW_ERROR_PROPERTY_INVALID,
    FLOW_ERROR_PROPERTY_CONVERT,
    FLOW_ERROR_PROPERTY_IN_ARRAY,
    FLOW_ERROR_PROPERTY_IN_ARRAY_CONVERT,
    FLOW_ERROR_PROPERTY_NUM,
    FLOW_ERROR_PROPERTY_IN_ACTION,
    FLOW_ERROR_PROPERTY_ASSIGN_IN_ACTION,
    FLOW_ERROR_PROPERTY_IN_ACTION_CONVERT,
    FLOW_ERROR_PROPERTY_NOT_FOUND_IN_ACTION,
    FLOW_ERROR_PROPERTY_IS_NULL_IN_ACTION,
    FLOW_ERROR_USER_PROPERTY,
    FLOW_ERROR_USER_ASSIGNABLE_PROPERTY
};

struct FlowError {
    static FlowError Plain(const char *message, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PLAIN, message, file, line);
    }

    static FlowError Property(const char *componentName, const char *propertyName, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY, componentName, propertyName, file, line);
    }

    static FlowError PropertyInvalid(const char *componentName, const char *propertyName, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_INVALID, componentName, propertyName, file, line);
    }

    static FlowError PropertyConvert(const char *componentName, const char *propertyName, const char *typeName, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_CONVERT, componentName, propertyName, typeName, file, line);
    }

    static FlowError PropertyInArray(const char *componentName, const char *propertyName, int index, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_IN_ARRAY, componentName, propertyName, index, file, line);
    }

    static FlowError PropertyInArrayConvert(const char *componentName, const char *propertyName, const char *typeName, int index, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_IN_ARRAY_CONVERT, componentName, propertyName, typeName, index, file, line);
    }

    static FlowError PropertyNum(const char *componentName, int index, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_NUM, componentName, index, file, line);
    }

    static FlowError PropertyInAction(const char *componentName, const char *propertyName, int actionIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_IN_ACTION, componentName, propertyName, actionIndex, file, line);
    }

    static FlowError PropertyAssignInAction(const char *componentName, const char *propertyName, int actionIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_ASSIGN_IN_ACTION, componentName, propertyName, actionIndex, file, line);
    }

    static FlowError PropertyInActionConvert(const char *componentName, const char *propertyName, const char *typeName, int actionIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_IN_ACTION_CONVERT, componentName, propertyName, typeName, actionIndex, file, line);
    }

    static FlowError NotFoundInAction(const char *resourceType, const char *resourceName, const char *actionName, int actionIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_NOT_FOUND_IN_ACTION, resourceType, resourceName, actionName, actionIndex, file, line);
    }

    static FlowError NullInAction(const char *resourceType, const char *actionName, int actionIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_PROPERTY_IS_NULL_IN_ACTION, resourceType, actionName, actionIndex, file, line);
    }

    static FlowError UserProperty(const char *componentName, int userPropertyIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_USER_PROPERTY, componentName, userPropertyIndex, file, line);
    }

    static FlowError UserAssignableProperty(const char *componentName, int userPropertyIndex, const char *file = 0, int line = -1) {
        return FlowError(FLOW_ERROR_USER_ASSIGNABLE_PROPERTY, componentName, userPropertyIndex, file, line);
    }

    FlowError setDescription(const char *description_) const {
        return FlowError(type, messagePart1, messagePart2, messagePart3, messagePartInt, description_, file, line);
    }

    const char *getMessage(char *messageStr, size_t messageStrLength, int flowIndex, int componentIndex) const;

private: 
    FlowErrorType type;
    const char *messagePart1;
    const char *messagePart2;
    const char *messagePart3;
    const char *description;
    int messagePartInt;

    const char *file;
    int line;

    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(0), messagePart3(0), description(0), messagePartInt(0), file(_file), line(_line) {}
    
    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_messagePart2, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(_messagePart2), messagePart3(0), description(0), messagePartInt(0), file(_file), line(_line) {}
    
    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_messagePart2, const char *_messagePart3, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(_messagePart2), messagePart3(_messagePart3), description(0), messagePartInt(0), file(_file), line(_line) {}

    FlowError(FlowErrorType _type, const char *_messagePart1, int _messagePartInt, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(0), messagePart3(0), description(0), messagePartInt(_messagePartInt), file(_file), line(_line) {}

    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_messagePart2, int _messagePartInt, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(_messagePart2), messagePart3(0), description(0), messagePartInt(_messagePartInt), file(_file), line(_line) {}

    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_messagePart2, const char *_messagePart3, int _messagePartInt, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(_messagePart2), messagePart3(_messagePart3), description(0), messagePartInt(_messagePartInt), file(_file), line(_line) {}

    FlowError(FlowErrorType _type, const char *_messagePart1, const char *_messagePart2, const char *_messagePart3, int _messagePartInt, const char *_description, const char *_file, int _line)
        : type(_type), messagePart1(_messagePart1), messagePart2(_messagePart2), messagePart3(_messagePart3), description(_description), messagePartInt(_messagePartInt), file(_file), line(_line) {}
};

void throwError(FlowState *flowState, int componentIndex, const char *errorMessage);
void throwError(FlowState *flowState, int componentIndex, const FlowError &error);

void enableThrowError(bool enable);

} // flow
} // eez

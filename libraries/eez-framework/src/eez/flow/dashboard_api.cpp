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

#if defined(EEZ_DASHBOARD_API)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <eez/core/os.h>

#include <eez/flow/flow.h>
#include <eez/flow/expression.h>
#include <eez/flow/dashboard_api.h>
#include <eez/flow/private.h>
#include <eez/flow/debugger.h>

using namespace eez;
using namespace eez::flow;

namespace eez {
namespace flow {

bool g_dashboardValueFree = false;

int getFlowStateIndex(FlowState *flowState) {
    return (int)((uint8_t *)flowState - ALLOC_BUFFER);
}

FlowState *getFlowStateFromFlowStateIndex(int flowStateIndex) {
    return (FlowState *)(ALLOC_BUFFER + flowStateIndex);
}

struct DashboardComponentExecutionState : public ComponenentExecutionState {
    ~DashboardComponentExecutionState() {
		EM_ASM({
            freeComponentExecutionState($0, $1);
        }, g_wasmModuleId, this);
    }
};

void executeDashboardComponent(uint16_t componentType, int flowStateIndex, int componentIndex) {
    EM_ASM({
        executeDashboardComponent($0, $1, $2, $3);
    }, g_wasmModuleId, componentType, flowStateIndex, componentIndex);
}

Value operationJsonGet(int json, const char *property) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return operationJsonGet($0, $1, UTF8ToString($2));
    }, g_wasmModuleId, json, property);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

int operationJsonSet(int json, const char *property, const Value *valuePtr) {
    return EM_ASM_INT({
        return operationJsonSet($0, $1, UTF8ToString($2), $3);
    }, g_wasmModuleId, json, property, valuePtr);
}

int operationJsonArrayLength(int json) {
    return EM_ASM_INT({
        return operationJsonArrayLength($0, $1);
    }, g_wasmModuleId, json);
}

Value operationJsonArraySlice(int json, int from, int to) {
    auto resultValuePtr = (Value *)EM_ASM_INT({
        return operationJsonArraySlice($0, $1, $2, $3);
    }, g_wasmModuleId, json, from, to);

    Value result = *resultValuePtr;

    ObjectAllocator<Value>::deallocate(resultValuePtr);

    return result;
}

Value operationJsonArrayAppend(int json, const Value *valuePtr) {
    auto resultValuePtr = (Value *)EM_ASM_INT({
        return operationJsonArrayAppend($0, $1, $2);
    }, g_wasmModuleId, json, valuePtr);

    Value result = *resultValuePtr;

    ObjectAllocator<Value>::deallocate(resultValuePtr);

    return result;
}

Value operationJsonArrayInsert(int json, int32_t position, const Value *valuePtr) {
    auto resultValuePtr = (Value *)EM_ASM_INT({
        return operationJsonArrayInsert($0, $1, $2, $3);
    }, g_wasmModuleId, json, position, valuePtr);

    Value result = *resultValuePtr;

    ObjectAllocator<Value>::deallocate(resultValuePtr);

    return result;
}

Value operationJsonArrayRemove(int json, int32_t position) {
    auto resultValuePtr = (Value *)EM_ASM_INT({
        return operationJsonArrayRemove($0, $1, $2);
    }, g_wasmModuleId, json, position);

    Value result = *resultValuePtr;

    ObjectAllocator<Value>::deallocate(resultValuePtr);

    return result;
}

Value operationJsonClone(int json) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return operationJsonClone($0, $1);
    }, g_wasmModuleId, json);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

Value operationJsonMake() {
    auto valuePtr = (Value *)EM_ASM_INT({
        return operationJsonMake($0);
    }, g_wasmModuleId);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

Value operationStringFormat(const char *format, const Value *paramPtr) {
    auto resultPtr = (Value *)EM_ASM_INT({
        return operationStringFormat($0, UTF8ToString($1), $2);
    }, g_wasmModuleId, format, paramPtr);

    Value result = *resultPtr;

    ObjectAllocator<Value>::deallocate(resultPtr);

    return result;
}

Value operationStringFormatPrefix(const char *format, const Value *valuePtr, const Value *paramPtr) {
    auto resultPtr = (Value *)EM_ASM_INT({
        return operationStringFormatPrefix($0, UTF8ToString($1), $2, $3);
    }, g_wasmModuleId, format, valuePtr, paramPtr);

    Value result = *resultPtr;

    ObjectAllocator<Value>::deallocate(resultPtr);

    return result;
}

Value convertFromJson(int json, uint32_t toType) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return convertFromJson($0, $1, $2);
    }, g_wasmModuleId, json, toType);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

Value convertToJson(const Value *arrayValuePtr) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return convertToJson($0, $1);
    }, g_wasmModuleId, arrayValuePtr);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

Value getObjectVariableMemberValue(Value *objectValue, int memberIndex) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return getObjectVariableMemberValue($0, $1, $2);
    }, g_wasmModuleId, objectValue, memberIndex);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

Value operationBlobToString(const uint8_t* blob, uint32_t len) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return operationBlobToString($0, $1, $2);
    }, g_wasmModuleId, blob, len);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

void dashboardObjectValueIncRef(int json) {
    EM_ASM({
        dashboardObjectValueIncRef($0, $1);
    }, g_wasmModuleId, json);
}

void dashboardObjectValueDecRef(int json) {
    EM_ASM({
        dashboardObjectValueDecRef($0, $1);
    }, g_wasmModuleId, json);
}

void onObjectArrayValueFree(ArrayValue *arrayValue) {
    EM_ASM({
        onObjectArrayValueFree($0, $1);
    }, g_wasmModuleId, arrayValue);
}

Value getBitmapAsDataURL(const char *bitmapName) {
    auto valuePtr = (Value *)EM_ASM_INT({
        return getBitmapAsDataURL($0, UTF8ToString($1));
    }, g_wasmModuleId, bitmapName);

    Value result = *valuePtr;

    ObjectAllocator<Value>::deallocate(valuePtr);

    return result;
}

void setDashboardColorTheme(const char *themeName) {
    EM_ASM({
        return setDashboardColorTheme($0, UTF8ToString($1));
    }, g_wasmModuleId, themeName);
}

} // flow
} // eez

static void updateArrayValue(ArrayValue *arrayValue1, ArrayValue *arrayValue2) {
    for (uint32_t i = 0; i < arrayValue1->arraySize; i++) {
        if (arrayValue1->values[i].isArray()) {
            updateArrayValue(arrayValue1->values[i].getArray(), arrayValue2->values[i].getArray());
        } else {
            arrayValue1->values[i] = arrayValue2->values[i];
            onValueChanged(&arrayValue1->values[i]);
        }
    }
}

EM_PORT_API(Value *) createUndefinedValue() {
    auto pValue = ObjectAllocator<Value>::allocate(0x2e821285);
    *pValue = Value(0, VALUE_TYPE_UNDEFINED);
    return pValue;
}

EM_PORT_API(Value *) createNullValue() {
    auto pValue = ObjectAllocator<Value>::allocate(0x69debded);
    *pValue = Value(0, VALUE_TYPE_NULL);
    return pValue;
}

EM_PORT_API(Value *) createIntValue(int value) {
    auto pValue = ObjectAllocator<Value>::allocate(0x20ea356c);
    *pValue = Value(value, VALUE_TYPE_INT32);
    return pValue;
}

EM_PORT_API(Value *) createDoubleValue(double value) {
    auto pValue = ObjectAllocator<Value>::allocate(0xecfb69a9);
    *pValue = Value(value, VALUE_TYPE_DOUBLE);
    return pValue;
}

EM_PORT_API(Value *) createBooleanValue(int value) {
    auto pValue = ObjectAllocator<Value>::allocate(0x76071378);
    *pValue = Value(value, VALUE_TYPE_BOOLEAN);
    return pValue;
}

EM_PORT_API(Value *) createStringValue(const char *value) {
    auto pValue = ObjectAllocator<Value>::allocate(0x0a8a7ed1);
    Value stringValue = Value::makeStringRef(value, strlen(value), 0x5b1e51d7);
    *pValue = stringValue;
    return pValue;
}

EM_PORT_API(Value *) createArrayValue(int arraySize, int arrayType) {
    Value value = Value::makeArrayRef(arraySize, arrayType, 0xeabb7edc);
    auto pValue = ObjectAllocator<Value>::allocate(0xbab14c6a);
    if (pValue) {
        *pValue = value;
    }
    return pValue;
}

EM_PORT_API(Value *) createStreamValue(int value) {
    dashboardObjectValueIncRef(value);
    auto pValue = ObjectAllocator<Value>::allocate(0x53a2e660);
    *pValue = Value(value, VALUE_TYPE_STREAM);
    return pValue;
}

EM_PORT_API(Value *) createDateValue(double value) {
    auto pValue = ObjectAllocator<Value>::allocate(0x90b7ce70);
    *pValue = Value(value, VALUE_TYPE_DATE);
    return pValue;
}

EM_PORT_API(Value *) createBlobValue(const uint8_t *buffer, uint32_t bufferLen) {
    auto pValue = ObjectAllocator<Value>::allocate(0x35109c5c);
    *pValue = Value::makeBlobRef(buffer, bufferLen, 0x1100895c);
    return pValue;
}

EM_PORT_API(Value *) createJsonValue(int value) {
    dashboardObjectValueIncRef(value);
    auto pValue = ObjectAllocator<Value>::allocate(0x734f514c);
    *pValue = Value(value, VALUE_TYPE_JSON);
    return pValue;
}

EM_PORT_API(Value *) createErrorValue() {
    auto pValue = ObjectAllocator<Value>::allocate(0x5ad2f119);
    *pValue = Value::makeError();
    return pValue;
}

EM_PORT_API(void) arrayValueSetElementValue(Value *arrayValuePtr, int elementIndex, Value *valuePtr) {
    auto array = arrayValuePtr->getArray();
    array->values[elementIndex] = *valuePtr;
}

EM_PORT_API(void) valueFree(Value *valuePtr) {
    eez::flow::g_dashboardValueFree = true;
    ObjectAllocator<Value>::deallocate(valuePtr);
    eez::flow::g_dashboardValueFree = false;
}

EM_PORT_API(Value *) getGlobalVariable(int globalVariableIndex) {
    auto flowDefinition = static_cast<FlowDefinition *>(eez::g_mainAssets->flowDefinition);
    if (g_globalVariables) {
        return g_globalVariables->values + globalVariableIndex;
    }
    return flowDefinition->globalVariables[globalVariableIndex];
}

EM_PORT_API(void) setGlobalVariable(int globalVariableIndex, Value *valuePtr) {
    auto flowDefinition = static_cast<FlowDefinition *>(eez::g_mainAssets->flowDefinition);
    Value *globalVariableValuePtr = g_globalVariables
        ? g_globalVariables->values + globalVariableIndex
        : flowDefinition->globalVariables[globalVariableIndex];
    *globalVariableValuePtr = *valuePtr;
    onValueChanged(globalVariableValuePtr);
}

EM_PORT_API(void) updateGlobalVariable(int globalVariableIndex, Value *valuePtr) {
    auto flowDefinition = static_cast<FlowDefinition *>(eez::g_mainAssets->flowDefinition);
    Value *globalVariableValuePtr = g_globalVariables
        ? g_globalVariables->values + globalVariableIndex
        : flowDefinition->globalVariables[globalVariableIndex];
    updateArrayValue(globalVariableValuePtr->getArray(), valuePtr->getArray());
}

EM_PORT_API(int) getFlowIndex(int flowStateIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    return flowState->flowIndex;
}

EM_PORT_API(void *) getComponentExecutionState(int flowStateIndex, int componentIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    auto executionState = (DashboardComponentExecutionState *)flowState->componenentExecutionStates[componentIndex];
    if (executionState) {
        return executionState;
    }
    return nullptr;
}

EM_PORT_API(void *) allocateDashboardComponentExecutionState(int flowStateIndex, int componentIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    auto executionState = (DashboardComponentExecutionState *)flowState->componenentExecutionStates[componentIndex];
    if (executionState) {
        return executionState;
    }
    return allocateComponentExecutionState<DashboardComponentExecutionState>(flowState, componentIndex);
}

EM_PORT_API(void) deallocateDashboardComponentExecutionState(int flowStateIndex, int componentIndex, int state) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    auto executionState = (DashboardComponentExecutionState *)flowState->componenentExecutionStates[componentIndex];
    if (executionState) {
        deallocateComponentExecutionState(flowState, componentIndex);
    }
}

EM_PORT_API(uint32_t) getUint8Param(int flowStateIndex, int componentIndex, int offset) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    return *(const uint8_t *)((const uint8_t *)component + sizeof(Component) + offset);
}

EM_PORT_API(uint32_t) getUint32Param(int flowStateIndex, int componentIndex, int offset) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    return *(const uint32_t *)((const uint8_t *)component + sizeof(Component) + offset);
}

EM_PORT_API(const char *) getStringParam(int flowStateIndex, int componentIndex, int offset) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    auto ptr = (AssetsPtr<const char> *)((const uint8_t *)component + sizeof(Component) + offset);
    return *ptr;
}

struct ExpressionList {
    uint32_t count;
    Value values[1];
};

EM_PORT_API(void *) getExpressionListParam(int flowStateIndex, int componentIndex, int offset) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];

    auto &list = *(ListOfAssetsPtr<uint8_t> *)((const uint8_t *)component + sizeof(Component) + offset);

    auto expressionList = (ExpressionList *)::malloc(sizeof(ExpressionList) + (list.count - 1) * sizeof(Value));

    expressionList->count = list.count;

    for (uint32_t i = 0; i < list.count; i++) {
        // call Value constructor
        new (expressionList->values + i) Value();

        auto valueExpression = list[i];
        if (!evalExpression(flowState, componentIndex, valueExpression, expressionList->values[i], FlowError::Plain("Failed to evaluate expression"))) {
            return nullptr;
        }
    }

    return expressionList;
}

EM_PORT_API(void) freeExpressionListParam(void *ptr) {
    auto expressionList = (ExpressionList*)ptr;

    for (uint32_t i = 0; i < expressionList->count; i++) {
        // call Value desctructor
        (expressionList->values + i)->~Value();
    }

    ::free(ptr);
}

struct Expressions {
    AssetsPtr<uint8_t> expressions[1];
};

EM_PORT_API(int) getListParamSize(int flowStateIndex, int componentIndex, int offset) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];
    auto list = (ListOfAssetsPtr<Expressions> *)((const uint8_t *)component + sizeof(Component) + offset);
    return list->count;
}

EM_PORT_API(Value *) evalListParamElementExpression(int flowStateIndex, int componentIndex, int listOffset, int elementIndex, int expressionOffset, const char *errorMessage) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto component = flowState->flow->components[componentIndex];

    ListOfAssetsPtr<Expressions> &list = *(ListOfAssetsPtr<Expressions> *)((const uint8_t *)component + sizeof(Component) + listOffset);
    auto &expressionInstructions = list[elementIndex]->expressions[expressionOffset / 4];

    Value result;
    if (!evalExpression(flowState, componentIndex, expressionInstructions, result, FlowError::Plain(errorMessage))) {
        return nullptr;
    }

    auto pValue = ObjectAllocator<Value>::allocate(0x15cb2009);
    if (!pValue) {
        throwError(flowState, componentIndex, FlowError::Plain("Out of memory"));
        return nullptr;
    }

    *pValue = result;

    return pValue;
}

EM_PORT_API(Value*) getInputValue(int flowStateIndex, int inputIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    return flowState->values + inputIndex;
}

EM_PORT_API(void) clearInputValue(int flowStateIndex, int inputIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    clearInputValue(flowState, inputIndex);
}

EM_PORT_API(Value *) evalProperty(int flowStateIndex, int componentIndex, int propertyIndex, int32_t *iterators, bool disableThrowError) {
    if (eez::flow::isFlowStopped()) {
        return nullptr;
    }

    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);

    if (disableThrowError) {
        eez::flow::enableThrowError(false);
    }

    Value result;
    if (!eez::flow::evalProperty(flowState, componentIndex, propertyIndex, result, FlowError::Plain("Failed to evaluate property"), nullptr, iterators)) {
        return nullptr;
    }

    if (disableThrowError) {
        eez::flow::enableThrowError(true);
    }

    auto pValue = ObjectAllocator<Value>::allocate(0xb7e697b8);
    if (!pValue) {
        throwError(flowState, componentIndex, FlowError::Plain("Out of memory"));
        return nullptr;
    }

    *pValue = result;

    return pValue;
}

EM_PORT_API(void) assignProperty(int flowStateIndex, int componentIndex, int propertyIndex, int32_t *iterators, Value *srcValuePtr) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);

    Value dstValue;
    if (evalAssignableProperty(flowState, componentIndex, propertyIndex, dstValue, FlowError::Plain(""), nullptr, iterators)) {
        assignValue(flowState, componentIndex, dstValue, *srcValuePtr);
    }
}

EM_PORT_API(void) setPropertyField(int flowStateIndex, int componentIndex, int propertyIndex, int fieldIndex, Value *valuePtr) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);

    Value result;
    if (!eez::flow::evalProperty(flowState, componentIndex, propertyIndex, result, FlowError::Plain("Failed to evaluate property"))) {
        return;
    }

	if (result.getType() == VALUE_TYPE_VALUE_PTR) {
		result = *result.pValueValue;
	}

    if (!result.isArray()) {
        throwError(flowState, componentIndex, FlowError::Plain("Property is not an array"));
        return;
    }

    auto array = result.getArray();

    if (fieldIndex < 0 || fieldIndex >= array->arraySize) {
        throwError(flowState, componentIndex, FlowError::Plain("Invalid field index"));
        return;
    }

    array->values[fieldIndex] = *valuePtr;
    onValueChanged(array->values + fieldIndex);
}

EM_PORT_API(void) propagateValue(int flowStateIndex, int componentIndex, int outputIndex, Value *valuePtr) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::propagateValue(flowState, componentIndex, outputIndex, *valuePtr);
}

EM_PORT_API(void) propagateValueThroughSeqout(int flowStateIndex, int componentIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
	eez::flow::propagateValueThroughSeqout(flowState, componentIndex);
}

EM_PORT_API(void) startAsyncExecution(int flowStateIndex, int componentIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::startAsyncExecution(flowState, componentIndex);
}

EM_PORT_API(void) endAsyncExecution(int flowStateIndex, int componentIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::endAsyncExecution(flowState, componentIndex);
}

EM_PORT_API(void) executeCallAction(int flowStateIndex, int componentIndex, int flowIndex) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::executeCallAction(flowState, componentIndex, flowIndex, Value());
}

EM_PORT_API(void) onEvent(int flowStateIndex, FlowEvent flowEvent, Value *flowValue) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::onEvent(flowState, flowEvent, *flowValue);
}

EM_PORT_API(void) logInfo(int flowStateIndex, int componentIndex, const char *infoMessage) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    eez::flow::logInfo(flowState, componentIndex, infoMessage);
}

EM_PORT_API(void) throwError(int flowStateIndex, int componentIndex, const char *errorMessage) {
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
	eez::flow::throwError(flowState, componentIndex, errorMessage);
}

EM_PORT_API(int) getFirstRootFlowState() {
    if (!g_firstFlowState) {
        return -1;
    }
    return getFlowStateIndex(g_firstFlowState);
}

EM_PORT_API(int) getFirstChildFlowState(int flowStateIndex) {
    if (flowStateIndex == -1) {
        return -1;
    }
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto firstChildFlowState = flowState->firstChild;
    if (!firstChildFlowState) {
        return -1;
    }
    return getFlowStateIndex(firstChildFlowState);
}

EM_PORT_API(int) getNextSiblingFlowState(int flowStateIndex) {
    if (flowStateIndex == -1) {
        return -1;
    }
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    auto nextSiblingFlowState = flowState->nextSibling;
    if (!nextSiblingFlowState) {
        return -1;
    }
    return getFlowStateIndex(nextSiblingFlowState);
}

EM_PORT_API(int) getFlowStateFlowIndex(int flowStateIndex) {
    if (flowStateIndex == -1) {
        return -1;
    }
    auto flowState = getFlowStateFromFlowStateIndex(flowStateIndex);
    return flowState->flowIndex;
}

EM_PORT_API(void) setDebuggerMessageSubsciptionFilter(uint32_t filter) {
    eez::flow::setDebuggerMessageSubsciptionFilter(filter);
}

EM_PORT_API(void) flowCleanup() {
    if (!isFlowStopped()) {
        stop();
        tick();
    }
}

#if EEZ_OPTION_GUI
EM_PORT_API(bool) isRTL() {
    return g_isRTL;
}
#endif

#endif // EEZ_DASHBOARD_API

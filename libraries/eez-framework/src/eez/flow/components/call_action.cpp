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

#include <eez/core/action.h>

#include <eez/flow/components.h>
#include <eez/flow/components/call_action.h>
#include <eez/flow/debugger.h>
#include <eez/flow/queue.h>
#include <eez/flow/expression.h>

namespace eez {
namespace flow {

FlowState *g_executeActionFlowState;
unsigned g_executeActionComponentIndex;

void executeCallAction(FlowState *flowState, unsigned componentIndex, int flowIndex, const Value& inputValue) {
    // if componentIndex == -1 then execute flow at flowIndex without CallAction component

	if (flowIndex >= (int)flowState->flowDefinition->flows.count) {
        // native action
        g_executeActionFlowState = flowState;
        g_executeActionComponentIndex = componentIndex;

		executeActionFunction(flowIndex - flowState->flowDefinition->flows.count);

        if ((int)componentIndex != -1 && !flowState->componenentAsyncStates[componentIndex]) {
		    propagateValueThroughSeqout(flowState, componentIndex);
        }

		return;
	}

	FlowState *actionFlowState = initActionFlowState(flowIndex, flowState, componentIndex, inputValue);

    // init user properties
    if ((int)componentIndex != -1) {
        for (uint32_t i = 0; i < actionFlowState->flow->userPropertiesAssignable.count; i++) {
            auto isAssignable = actionFlowState->flow->userPropertiesAssignable.items[i];

            Value value;
            if (isAssignable) {
                if (!evalAssignableProperty(flowState, componentIndex, i, value, FlowError::UserProperty("CallAction", i))) {
                    break;
                }
                if (value.getType() == VALUE_TYPE_FLOW_OUTPUT) {
                    value = Value::makePropertyRef(flowState, componentIndex, i, 0x5696e703);
                }
            } else {
                if (!evalProperty(flowState, componentIndex, i, value, FlowError::UserAssignableProperty("CallAction", i))) {
                    break;
                }
            }

            auto propValuePtr = actionFlowState->values + actionFlowState->flow->componentInputs.count + i;

            *propValuePtr = value;
            onValueChanged(propValuePtr);
        }
    }

	if (canFreeFlowState(actionFlowState)) {
        freeFlowState(actionFlowState);
        if ((int)componentIndex != -1) {
		    propagateValueThroughSeqout(flowState, componentIndex);
        }
	}
}

void executeCallActionComponent(FlowState *flowState, unsigned componentIndex) {
	auto component = (CallActionActionComponent *)flowState->flow->components[componentIndex];

	auto flowIndex = component->flowIndex;
	if (flowIndex < 0) {
		throwError(flowState, componentIndex, FlowError::Plain("Invalid action flow index in CallAction"));
		return;
	}

    executeCallAction(flowState, componentIndex, flowIndex, Value());
}

} // namespace flow
} // namespace eez

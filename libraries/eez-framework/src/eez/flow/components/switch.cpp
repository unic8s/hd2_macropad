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

#include <eez/flow/components.h>
#include <eez/flow/flow_defs_v3.h>
#include <eez/flow/expression.h>

#include <eez/flow/components/switch.h>

namespace eez {
namespace flow {

void executeSwitchComponent(FlowState *flowState, unsigned componentIndex) {
    auto component = (SwitchActionComponent *)flowState->flow->components[componentIndex];

    for (uint32_t testIndex = 0; testIndex < component->tests.count; testIndex++) {
        auto test = component->tests[testIndex];

        Value conditionValue;
        if (!evalExpression(flowState, componentIndex, test->condition, conditionValue, FlowError::PropertyInArray("Switch", "Test condition", testIndex))) {
            return;
        }

        int err;
        bool result = conditionValue.toBool(&err);
        if (err) {
            throwError(flowState, componentIndex, FlowError::PropertyInArrayConvert("Switch", "Test condition", "boolean", testIndex));
            return;
        }

        if (result) {
            Value outputValue;
            if (!evalExpression(flowState, componentIndex, test->outputValue, outputValue, FlowError::PropertyInArray("Switch", "Test output", testIndex))) {
                return;
            }

            propagateValue(flowState, componentIndex, test->outputIndex, outputValue);

            break;
        }
    }

	propagateValueThroughSeqout(flowState, componentIndex);
}

} // namespace flow
} // namespace eez

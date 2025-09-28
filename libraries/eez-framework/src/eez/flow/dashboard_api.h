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

#if defined(EEZ_DASHBOARD_API)

#include <emscripten.h>

#include <eez/core/value.h>

namespace eez {
namespace flow {

struct FlowState;

extern bool g_dashboardValueFree;

int getFlowStateIndex(FlowState *flowState);

void executeDashboardComponent(uint16_t componentType, int flowStateIndex, int componentIndex);

Value operationJsonGet(int json, const char *property);
int operationJsonSet(int json, const char *property, const Value *valuePtr);
int operationJsonArrayLength(int json);
Value operationJsonArraySlice(int json, int from, int to);
Value operationJsonArrayAppend(int json, const Value *valuePtr);
Value operationJsonArrayInsert(int json, int32_t position, const Value *valuePtr);
Value operationJsonArrayRemove(int json, int32_t position);
Value operationJsonClone(int json);

Value operationJsonMake();

Value convertFromJson(int json, uint32_t toType);
Value convertToJson(const Value *arrayValuePtr);

void dashboardObjectValueIncRef(int json);
void dashboardObjectValueDecRef(int json);

void onObjectArrayValueFree(ArrayValue *arrayValue);

Value getBitmapAsDataURL(const char *bitmapName);

} // flow
} // eez

#endif

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

#include <assert.h>
#include <math.h>

#include <eez/flow/hooks.h>

#include <eez/core/util.h>

#if EEZ_OPTION_GUI
#include <eez/gui/gui.h>
#endif

#if !defined(EEZ_DISABLE_DATE_NOW_DEFAULT_IMPLEMENTATION)
#include <chrono>
#endif

namespace eez {
namespace flow {

static void replacePage(int16_t pageId, uint32_t animType, uint32_t speed, uint32_t delay) {
#if EEZ_OPTION_GUI
	eez::gui::getAppContextFromId(APP_CONTEXT_ID_DEVICE)->replacePage(pageId);
#else
    EEZ_UNUSED(pageId);
    EEZ_UNUSED(animType);
    EEZ_UNUSED(speed);
    EEZ_UNUSED(delay);
#endif
}

static void showKeyboard(Value label, Value initialText, Value minChars, Value maxChars, bool isPassword, void(*onOk)(char *), void(*onCancel)()) {
    EEZ_UNUSED(label);
    EEZ_UNUSED(initialText);
    EEZ_UNUSED(minChars);
    EEZ_UNUSED(maxChars);
    EEZ_UNUSED(isPassword);
    EEZ_UNUSED(onOk);
    EEZ_UNUSED(onCancel);
}

static void showKeypad(Value label, Value initialValue, Value min, Value max, Unit unit, void(*onOk)(float), void(*onCancel)()) {
    EEZ_UNUSED(label);
    EEZ_UNUSED(initialValue);
    EEZ_UNUSED(min);
    EEZ_UNUSED(max);
    EEZ_UNUSED(unit);
    EEZ_UNUSED(onOk);
    EEZ_UNUSED(onCancel);
}

static void stopScript() {
	assert(false);
}

static void scpiComponentInit() {
}

static void startToDebuggerMessage() {
}

static void writeDebuggerBuffer(const char *buffer, uint32_t length) {
    EEZ_UNUSED(buffer);
    EEZ_UNUSED(length);
}

static void finishToDebuggerMessage() {
}

static void onDebuggerInputAvailable() {
}

void (*replacePageHook)(int16_t pageId, uint32_t animType, uint32_t speed, uint32_t delay) = replacePage;
void (*showKeyboardHook)(Value label, Value initialText, Value minChars, Value maxChars, bool isPassword, void(*onOk)(char *), void(*onCancel)()) = showKeyboard;
void (*showKeypadHook)(Value label, Value initialValue, Value min, Value max, Unit unit, void(*onOk)(float), void(*onCancel)()) = showKeypad;
void (*stopScriptHook)() = stopScript;

void (*scpiComponentInitHook)() = scpiComponentInit;

void (*startToDebuggerMessageHook)() = startToDebuggerMessage;
void (*writeDebuggerBufferHook)(const char *buffer, uint32_t length) = writeDebuggerBuffer;
void (*finishToDebuggerMessageHook)() = finishToDebuggerMessage;
void (*onDebuggerInputAvailableHook)() = onDebuggerInputAvailable;

#if defined(EEZ_FOR_LVGL)
static lv_obj_t *getLvglObjectFromIndex(int32_t index) {
    EEZ_UNUSED(index);
    return 0;
}

static lv_group_t *getLvglGroupFromIndex(int32_t index) {
    EEZ_UNUSED(index);
    return 0;
}

static int32_t getLvglScreenByName(const char *name) {
    EEZ_UNUSED(name);
    return -1;
}

static int32_t getLvglObjectByName(const char *name) {
    EEZ_UNUSED(name);
    return -1;
}

static int32_t getLvglGroupByName(const char *name) {
    EEZ_UNUSED(name);
    return -1;
}

static int32_t getLvglStyleByName(const char *name) {
    EEZ_UNUSED(name);
    return -1;
}

static const void *getLvglImageByName(const char *name) {
    EEZ_UNUSED(name);
    return 0;
}

static void executeLvglAction(int actionIndex) {
    EEZ_UNUSED(actionIndex);
}

static void lvglObjAddStyle(lv_obj_t *object, int32_t styleIndex) {
    EEZ_UNUSED(object);
    EEZ_UNUSED(styleIndex);
}

static void lvglObjRemoveStyle(lv_obj_t *object, int32_t styleIndex) {
    EEZ_UNUSED(object);
    EEZ_UNUSED(styleIndex);
}

static void lvglSetColorTheme(const char *themeName) {
    EEZ_UNUSED(themeName);
}

lv_obj_t *(*getLvglObjectFromIndexHook)(int32_t index) = getLvglObjectFromIndex;
lv_group_t *(*getLvglGroupFromIndexHook)(int32_t index) = getLvglGroupFromIndex;

int32_t (*getLvglScreenByNameHook)(const char *name) = getLvglScreenByName;
int32_t (*getLvglObjectByNameHook)(const char *name) = getLvglObjectByName;
int32_t (*getLvglGroupByNameHook)(const char *name) = getLvglGroupByName;
int32_t (*getLvglStyleByNameHook)(const char *name) = getLvglStyleByName;
const void *(*getLvglImageByNameHook)(const char *name) = getLvglImageByName;

void (*executeLvglActionHook)(int actionIndex) = executeLvglAction;

void (*lvglObjAddStyleHook)(lv_obj_t *object, int32_t styleIndex) = lvglObjAddStyle;
void (*lvglObjRemoveStyleHook)(lv_obj_t *object, int32_t styleIndex) = lvglObjRemoveStyle;

void (*lvglSetColorThemeHook)(const char *themeName) = lvglSetColorTheme;
#endif

#if !defined(EEZ_DISABLE_DATE_NOW_DEFAULT_IMPLEMENTATION)

static double getDateNowDefaultImplementation() {
    using namespace std::chrono;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    return (double)ms.count();
}

double (*getDateNowHook)() = getDateNowDefaultImplementation;

#else

double (*getDateNowHook)() = nullptr;

#endif

void (*onFlowErrorHook)(FlowState *flowState, int componentIndex, const char *errorMessage) = nullptr;

} // namespace flow
} // namespace eez


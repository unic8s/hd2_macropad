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

#include <eez/flow/components.h>
#include <eez/flow/flow_defs_v3.h>
#include <eez/flow/expression.h>
#include <eez/flow/private.h>
#include <eez/flow/hooks.h>

#if defined(EEZ_DASHBOARD_API)
#include <eez/flow/dashboard_api.h>
#endif

#if EEZ_OPTION_GUI
#include <eez/gui/gui.h>
#include <eez/gui/display.h>
#endif

namespace eez {
namespace flow {

void executeSetColorThemeComponent(FlowState *flowState, unsigned componentIndex) {
	Value themeValue;
	if (!evalProperty(flowState, componentIndex, defs_v3::SET_COLOR_THEME_ACTION_COMPONENT_PROPERTY_THEME, themeValue, FlowError::Property("SetColorTheme", "Theme"))) {
		return;
	}

	const char *theme = themeValue.getString();

#if defined(EEZ_FOR_LVGL)
    lvglSetColorThemeHook(theme);
#elif EEZ_OPTION_GUI

#if defined(EEZ_DASHBOARD_API)
    if (g_mainAssets->assetsType == ASSETS_TYPE_DASHBOARD) {
        setDashboardColorTheme(theme);
        propagateValueThroughSeqout(flowState, componentIndex);
    } else {
#endif

    	auto &themes = flowState->assets->colorsDefinition->themes;

        for (uint32_t themeIndex = 0; themeIndex < themes.count; themeIndex++) {
            if (strcmp(themes[themeIndex]->name, theme) == 0) {
                eez::gui::g_selectedThemeIndex = themeIndex;
                eez::gui::display::onThemeChanged();
                propagateValueThroughSeqout(flowState, componentIndex);
                return;
            }
        }
        char message[256];
        snprintf(message, sizeof(message), "Unknown theme %s", theme);
        throwError(flowState, componentIndex, FlowError::Plain(message));

#if defined(EEZ_DASHBOARD_API)
    }
#endif

#endif
}

} // namespace flow
} // namespace eez

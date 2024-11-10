cmake_minimum_required(VERSION 3.16.0)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(DEMO_LVGL)
add_definitions(
    -DARDUINO_USB_MODE
	-DARDUINO_USB_CDC_ON_BOOT
)
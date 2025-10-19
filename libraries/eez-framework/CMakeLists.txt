if(ESP_PLATFORM)
    # for arduino as component ESP-IDF
    # get_filename_component(dir ${CMAKE_CURRENT_LIST_FILE} PATH)
    # FILE(GLOB_RECURSE app_sources ${dir}/src/eez/*.c*)
    # idf_component_register(SRCS ${app_sources}      
    #     INCLUDE_DIRS "src" "src/eez/libs/agg"
    #     PRIV_REQUIRES arduino lvgl
    # )    
else()
    cmake_minimum_required(VERSION 3.12)

    include_directories(
        ./src
        ./src/eez/libs/agg
    )

    file(GLOB_RECURSE SOURCES
        ./src/eez/*.cpp
        ./src/eez/*.c
    )

    ADD_LIBRARY(eez-framework STATIC ${SOURCES})

    target_include_directories(eez-framework SYSTEM PUBLIC ./src ./src/eez/libs/agg)
endif()

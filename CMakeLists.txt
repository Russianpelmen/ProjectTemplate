cmake_minimum_required(VERSION 3.8)
project("ProjectTemplate")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(RESOURCE
    "Resource/resource.rc"
    "Resource/resource.h"
)

set(SOURCE
    "src/Common.hpp"
    "src/main.cpp"
)

add_executable(${PROJECT_NAME} WIN32 ${SOURCE} ${RESOURCE})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND mt.exe -manifest ${CMAKE_CURRENT_SOURCE_DIR}/manifest.xml 
    -outputresource:$<TARGET_FILE:${PROJECT_NAME}>\;1
)

if (WIN32)
  set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE YES)
endif()
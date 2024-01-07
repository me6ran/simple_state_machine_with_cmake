cmake_minimum_required(VERSION "3.19.2")

include(${CMAKE_SOURCE_DIR}/common_macros.cmake)

project(state-trafficlight VERSION 1.0 LANGUAGES C)

SET(TARGET_NAME state-trafficlight)
message(STATUS "Value of CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "Value of CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")


include_directories(${PROJECT_SOURCE_DIR}/common/include)

add_library(common_lib STATIC
            common/src/traffic_light.c
            common/src/math_operations.c           
)

add_subdirectory(${PROJECT_SOURCE_DIR}/buffer_interface)

add_executable(${TARGET_NAME} state_machine_fpointer.c)

target_link_libraries(${TARGET_NAME} common_lib)

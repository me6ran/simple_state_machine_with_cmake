cmake_minimum_required(VERSION "3.19.2")

project(stateMachineTrafficLight VERSION 1.0 LANGUAGES C)

SET(TARGET_NAME stateMachineTrafficLight)
include_directories(${PROJECT_SOURCE_DIR}/common/include)

add_library(common_lib STATIC
            common/src/traffic_light.c
            common/src/math_operations.c           
)

add_subdirectory(${PROJECT_SOURCE_DIR}/buffer_interface)

add_executable(${TARGET_NAME} state_machine_fpointer.c)

target_link_libraries(${TARGET_NAME} common_lib)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${TARGET_NAME}>
    ${PROJECT_SOURCE_DIR}
)
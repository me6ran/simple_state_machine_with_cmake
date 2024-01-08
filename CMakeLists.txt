cmake_minimum_required(VERSION "3.19.2")

include(${CMAKE_SOURCE_DIR}/common_macros.cmake)

add_subdirectory(${PROJECT_SOURCE_DIR}/buffer_interface)
add_subdirectory(${PROJECT_SOURCE_DIR}/state_machine_traffic_light)

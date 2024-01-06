
project(bufferInterface VERSION 1.0 LANGUAGES C)

SET(TARGET_NAME bufferInterface)

message(STATUS "bufferInterface- Value of CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "bufferInterface- Value of CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${TARGET_NAME} buffer_interface.c)

copy_target_2_src_dir("${TARGET_NAME}" "${PROJECT_SOURCE_DIR}/${TARGET_NAME}")
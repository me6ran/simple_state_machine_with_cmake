
project(buffer_interface VERSION 1.0 LANGUAGES C)

SET(TARGET_NAME buffer-interface)

add_executable(${TARGET_NAME} buffer_interface.c)

# copy_target_2_src_dir("${TARGET_NAME}" "${PROJECT_SOURCE_DIR}/${TARGET_NAME}")
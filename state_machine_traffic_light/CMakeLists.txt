
SET(TARGET_NAME state-trafficlight)

message(STATUS "PROJECT_SOURCE_DIR for state machine: ${PROJECT_SOURCE_DIR}")


include_directories(${PROJECT_SOURCE_DIR}/state_machine_traffic_light/common/include)

add_library(common_lib STATIC
            common/src/traffic_light.c
            common/src/math_operations.c           
)

add_executable(${TARGET_NAME} state_machine_fpointer.c)

target_link_libraries(${TARGET_NAME} common_lib)


SET(TARGET_NAME state-trafficlight)

message(STATUS "PROJECT_SOURCE_DIR for state machine: ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_IS_TOP_LEVEL for state machine: ${PROJECT_IS_TOP_LEVEL}")
message(STATUS "PROJECT_BINARY_DIR for state machine: ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_NAME for state machine: ${PROJECT_NAME}")



include_directories(${PROJECT_SOURCE_DIR}/state_machine_traffic_light/common/include)

add_library(common_lib STATIC
            common/src/traffic_light.c
            common/src/math_operations.c           
)

add_executable(${TARGET_NAME} state_machine_fpointer.c)

target_link_libraries(${TARGET_NAME} common_lib)

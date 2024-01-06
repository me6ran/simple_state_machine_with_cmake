
macro(copy_target_2_src_dir target_name destination)
    add_custom_command(
        TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${target_name}>
        ${destination}
    )
endmacro()
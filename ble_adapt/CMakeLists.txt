add_library(ble_adapt_objects OBJECT
    ll_adapt.c
)

target_include_directories(ble_adapt_objects PRIVATE
    ${PROJECT_SOURCE_DIR}/ble_stack/host/inc
    ${PROJECT_SOURCE_DIR}/ble_stack/linklayer/inc
)

set(STACK_ELF
    "${PROJECT_BINARY_DIR}/ble_stack/fw.elf"
)

set(ADAPT_OBJECT
    "${CMAKE_CURRENT_BINARY_DIR}/libfw.o"
)

add_custom_command(
    OUTPUT ${ADAPT_OBJECT}

    COMMAND ${CMAKE_COMMAND} -E make_directory
            ${CMAKE_CURRENT_BINARY_DIR}

    COMMAND ${CMAKE_LINKER}
            -r
            -R ${STACK_ELF}
            $<TARGET_OBJECTS:ble_adapt_objects>
            -o ${ADAPT_OBJECT}

    DEPENDS
        ble_stack_fw
        ble_adapt_objects

    COMMENT "Partial linking BLE Adapt: libfw.o"

    COMMAND_EXPAND_LISTS
    VERBATIM
)

# --------------------------------------------------
# 3. Custom target
# --------------------------------------------------

add_custom_target(ble_adapt_lib ALL
    DEPENDS ${ADAPT_OBJECT}
)

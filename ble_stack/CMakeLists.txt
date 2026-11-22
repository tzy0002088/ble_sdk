add_library(ble_host OBJECT
    host/src/gap.c
    host/src/gatt.c
    host/src/l2cap.c
)

target_include_directories(ble_host PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/host/inc
)

add_library(ble_linklayer OBJECT
    linklayer/src/adv.c
    linklayer/src/connect.c
    linklayer/src/hci.c
    linklayer/src/ll.c
    linklayer/src/scan.c
    linklayer/src/schedule.c
)

target_include_directories(ble_linklayer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/linklayer/inc
)

add_executable(ble_stack_fw
    $<TARGET_OBJECTS:ble_host>
    $<TARGET_OBJECTS:ble_linklayer>
)

set_target_properties(ble_stack_fw PROPERTIES
    OUTPUT_NAME fw
    SUFFIX ".elf"
)

target_link_options(ble_stack_fw PRIVATE
    -nostartfiles
    -T${CMAKE_CURRENT_SOURCE_DIR}/linker/stack.ld
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/fw.map
)
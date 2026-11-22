add_executable(ble_dis
    main.c
)

set(LIBFW_OBJECT
    "${PROJECT_BINARY_DIR}/ble_adapt/libfw.o"
)

target_sources(ble_dis PRIVATE
    ${LIBFW_OBJECT}
)

target_link_options(ble_dis PRIVATE
    -nostartfiles
    -T${CMAKE_CURRENT_SOURCE_DIR}/../linker/app.ld
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/ble_dis.map
)

add_dependencies(ble_dis ble_adapt_lib)
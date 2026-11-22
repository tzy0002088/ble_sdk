cmake_minimum_required(VERSION 3.20)

project(ble_sw_arch C ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ARM Cortex-M0+
add_compile_options(
    -mcpu=cortex-m0plus
    -mthumb
    -ffunction-sections
    -fdata-sections
)

add_subdirectory(ble_stack)
add_subdirectory(ble_adapt)
add_subdirectory(ble_example)
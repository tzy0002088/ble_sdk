
ENTRY(main)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    __data_start__ = DEFINED(__stack_bss_end__) ? __stack_bss_end__ : ORIGIN(RAM);

    .text :
    {
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .data __data_start__ :
    {
        . = ALIGN(4);
        *(.data*)
        . = ALIGN(4);
    } > RAM AT> FLASH

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
    } > RAM

    ASSERT(. <= ORIGIN(RAM) + LENGTH(RAM), "app RAM overflow")

    /DISCARD/ :
    {
        *(.comment*)
        *(.note*)
    }
}

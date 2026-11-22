#include <stdint.h>

extern void ble_adapt_init(void);
extern void ble_process(void);

/* app 自己的 bss —— 应落在 __stack_bss_end__ 之后,和栈的 ll_em_pool 不重叠 */
uint8_t app_scratch[256];

int main()
{
    ble_adapt_init();

    while (1) {
        ble_process();
    }

    return 0;
}
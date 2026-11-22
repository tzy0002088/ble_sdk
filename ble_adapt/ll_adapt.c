#include "linklayer.h"

__attribute__((weak)) uint32_t __stack_bss_end__;
uint32_t ble_adapt_stack_bss_end = (uint32_t)&__stack_bss_end__;

static void hci_read(uint8_t *data, uint16_t len)
{

}

static void hci_write(uint8_t *data, uint16_t len)
{

}

static void *ll_malloc(size_t size)
{
    return NULL;
}

static void ll_free(void *ptr)
{
}

static uint8_t app_event_count;

static void app_ble_event(uint8_t evt_type)
{
    app_event_count++;
}

void ble_adapt_init(void)
{
    ll_init(ll_malloc, ll_free);
    hci_init(hci_read, hci_write);

    ll_event_callback = app_ble_event;
}

void ble_process(void)
{
    ll_schedule();
}
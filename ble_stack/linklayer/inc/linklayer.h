#ifndef LINKLAYER_H
#define LINKLAYER_H

#include <stdint.h>
#include <stddef.h>

typedef void (*hci_read_func_t)(uint8_t *data, uint16_t len);
typedef void (*hci_write_func_t)(uint8_t *data, uint16_t len);

typedef void *(*ll_malloc_func_t)(size_t size);
typedef void (*ll_free_func_t)(void *ptr);

void ll_init(ll_malloc_func_t ll_malloc, ll_free_func_t ll_free);
int hci_init(hci_read_func_t hci_read, hci_write_func_t hci_write);
void ll_schedule();
extern void (*ll_event_callback)(uint8_t evt_type);


#endif
#include "linklayer.h"

void (*ll_event_callback)(uint8_t evt_type);

void ll_schedule()
{
    if (ll_event_callback) {
        ll_event_callback(1);
    }
}


#include "linklayer.h"

static hci_read_func_t hci_read_func = NULL;
static hci_write_func_t hci_write_func = NULL;

int hci_init(hci_read_func_t hci_read, hci_write_func_t hci_write)
{
    if (hci_read == NULL || hci_write == NULL)
    {
        return -1; // Invalid function pointers
    }

    hci_read_func = hci_read;
    hci_write_func = hci_write;

    return 0; // Success
}

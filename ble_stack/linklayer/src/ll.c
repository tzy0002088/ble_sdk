#include "linklayer.h"

static ll_malloc_func_t ll_malloc_func;
static ll_free_func_t ll_free_func;

/* 栈自己的 bss 占用 —— 用来观察同一块 RAM 的划界 */
uint8_t ll_em_pool[512];

void ll_init(ll_malloc_func_t ll_malloc, ll_free_func_t ll_free)
{
    if (ll_malloc == NULL || ll_free == NULL)
    {
        // Handle error: Invalid function pointers
        return;
    }

    ll_malloc_func = ll_malloc;
    ll_free_func = ll_free;
}
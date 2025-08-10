#include "stack.h"

void Stack_init(stack* p, int size)
{
    p->base = (char*)malloc(size);
    p->top = p->base;
    p->size = size;
}

int Stack_Isempty(stack* p)
{
    return (p->top == p->base);
}

int Stack_Isfull(stack* p)
{
    return ((p->base - p->top) >= p->size);
}

bool Stack_push(stack* p, void* val, uint32_t size)
{
    if (Stack_Isfull)
    {
        return false;
    }
    p->top = (p->top - size);
    memcpy(p->top, val, size);
    return true;
}

bool Stack_pop(stack* p, void* val, uint32_t size)
{
    if (p->top + size > p->base)
        return false;
    memcpy(val, p->top, size);
    p->top += size;
    return true;
}

void Stack_free(stack* p)
{
    free(p->base);
    p->base = NULL;
    p->top = NULL;
}
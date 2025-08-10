#pragma once

#include<stdio.h>
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef struct {
    char* top;//
    char* base;//
    int size;
}stack;

void Stack_init(stack* p, int size);
int Stack_Isempty(stack* p);
int Stack_Isfull(stack* p);
bool Stack_push(stack* p, void* val, uint32_t size);
bool Stack_pop(stack* p, void* val, uint32_t size);
void Stack_free(stack* p);
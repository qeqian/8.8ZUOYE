#include "stack.h"

int main()
{
    int size = 10;         //size表示申请内存的字节数
    float val1 = 6.78f;    //val表示入栈区的变量
    //char val2 = 'r';
    stack p;
    Stack_init(&p, size);
    Stack_push(&p, &val1, sizeof(val1));
    printf("%.4f   ", val1);
    Stack_pop(&p, &val1, sizeof(val1));
    printf("%.4f   ", val1);
    Stack_free(&p);
    return 0;
}
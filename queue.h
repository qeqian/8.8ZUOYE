#pragma once 

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

#define QUEUE_LEN 20
typedef struct {
    int data[QUEUE_LEN];
    uint8_t front;
    uint8_t rear;
}queue;

void Queue_init(queue* p);  //初始化循环队列
int Queue_Isfull(queue* p); //判断队列是否满了
int Queue_Isempty(queue* p);  //判断队列是否空了
bool Queue_Enqueue(queue *p, int val);  //入队
bool Queue_Dequeue(queue* p, int* val);   //出队
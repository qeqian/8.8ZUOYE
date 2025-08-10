 #include "queue.h"

void Queue_init(queue* p)     //都初始化0
{
    p->front = p->rear = 0;
    for (int i = 0; i < QUEUE_LEN; i++)
    {
        p->data[i] = 0;
    }
}

int Queue_Isempty(queue* p)
{
    return (p->front == p->rear);   //如果队列是空的返�?，反�?
}

int Queue_Isfull(queue* p)
{
    return (((p->rear + 1) % QUEUE_LEN) == p->front);    //如果队列是满的返�?，反�?
}

bool Queue_Enqueue(queue *p, int val)
{
    if (Queue_Isfull(p))
    {
        //printf("该队列已满\n");
        return false;
    }
    p->data[p->rear] = val;
    p->rear = (p->rear + 1) % QUEUE_LEN;     //对队尾进行修�?同时防止rear超出队列长度，利用取模将rear限制在循环中
    return true;
}

bool Queue_Dequeue(queue *p, int *val)
{
    if (Queue_Isempty(p) ){
        //prinrtf("该队列已空\n");
        return false;
    }
    *val = p->data[p->front];     //只是赋值，离队就是front向后移动�?
    p->front = (p->front + 1) % QUEUE_LEN;
    return true;
}
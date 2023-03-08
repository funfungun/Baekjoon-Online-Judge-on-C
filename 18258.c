#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 2000000

typedef int element;

typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}QueueType;

void init_queue(QueueType *q)
{
    q->front = -1;
    q->rear = -1;
}

int empty(QueueType *q)
{
    if(q->front == q->rear)
        return 1;
    
    return 0;
}

int full(QueueType *q)
{
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
        
    return 0;
}

int size(QueueType *q)
{
    return ((q->rear) - (q->front));
}

void enqueue(QueueType *q, element item)
{
    if(full(q))
        return;
    
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType *q)
{
    if(empty(q))
        return -1;
    
    return q->data[++(q->front)];
}

element front(QueueType *q)
{
    if(empty(q))
        return -1;

    return q->data[(q->front)+1];
}

element back(QueueType *q)
{
    if(empty(q))
        return -1;

    return q->data[q->rear];
}

int main()
{
    QueueType q;
    
    init_queue(&q);
    
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        char str[6];
        scanf("%s", str);
        
        if(strcmp(str, "push") == 0)
        {
            int n;
            scanf("%d", &n);
            
            enqueue(&q, n);
        }
        
        if(strcmp(str, "pop") == 0)
            printf("%d\n", dequeue(&q));
            
        if(strcmp(str, "size") == 0)
            printf("%d\n", size(&q));
        
        if(strcmp(str, "empty") == 0)
            printf("%d\n", empty(&q));
            
        if(strcmp(str, "front") == 0)
            printf("%d\n", front(&q));
            
        if(strcmp(str, "back") == 0)
            printf("%d\n", back(&q));
    }
    
    return 0;
}
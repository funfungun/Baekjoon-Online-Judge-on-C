//c언어로 쉽게 풀어쓴 자료구조 p.150 참고

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000

//선형큐 정의
typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}QueueType;

//초기화 함수
//선형큐에서는 -1로 초기화
void init_queue(QueueType *q)
{
    q->front = -1;
    q->rear = -1;
}

//공백 검출 함수
int empty(QueueType *q)
{
   return (q->front == q->rear);//front와 rear가 같으면 공백
}

//포화 검출 함수
int full(QueueType *q)
{
    return (q->rear == MAX_QUEUE_SIZE - 1);//rear가 최대 큐 크기 -1 과 같으면 포화
}

//큐 크기 함수
int size(QueueType *q)
{
    return ((q->rear) - (q->front));
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    if(full(q))
        return;
    
    q->data[++(q->rear)] = item;//rear 먼저 증가시키고 그 자리에 요소 삽입
}

//삭제 함수
element dequeue(QueueType *q)
{
    if(empty(q))
        return -1;
    
    return q->data[++(q->front)];//front 먼저 증가시키고 그 자리에 있는 요소 반환
}

//peek front 함수
element front(QueueType *q)
{
    if(empty(q))
        return -1;

    return q->data[(q->front)+1];//front는 가장 앞 요소 바로 전을 가리킴
}

//peek rear 함수
element back(QueueType *q)
{
    if(empty(q))
        return -1;

    return q->data[q->rear];//rear가 가리키는 값 반환
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

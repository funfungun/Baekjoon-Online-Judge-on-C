#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEQUE_SIZE 10000

typedef int element;

typedef struct//덱 타입 정의(덱은 원형큐에서 연산만 추가됨)
{
    element data[MAX_DEQUE_SIZE];
    int front;
    int rear;
}DequeType;

void init_deque(DequeType *d)//초기화 함수
{
    d -> front = 0;
    d -> rear = 0;
}

int is_empty(DequeType *d)//공백인지
{
    return (d->front == d->rear);
}

int is_full(DequeType *d)//포화인지
{
    return ((d->rear + 1)%(MAX_DEQUE_SIZE) == d->front);
}

void add_front(DequeType *d, element item)//전단 삽입 함수
{
    if(is_full(d))
        return;
        
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

void add_rear(DequeType *d, element item)//말단 삽입 함수
{
    if(is_full(d))
        return;
        
    d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d->data[d->rear] = item;
}

element delete_front(DequeType *d)//전단 삭제 함수
{
    if(is_empty(d))
        return -1;
    
    d->front = (d->front + 1) % MAX_DEQUE_SIZE;
    
    return d->data[d->front];
}

element delete_rear(DequeType *d)//후단 삭제 함수
{
    if(is_empty(d))
        return -1;
        
    int temp = d->rear;
    
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    
    return d->data[temp];
}

element size(DequeType *d)//사이즈?
{
    return (((d->rear) - (d->front) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE);
}

element get_front(DequeType *d)//peek 전단
{
    if(is_empty(d))
        return -1;
    
    return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}

element get_rear(DequeType *d)//peek 후단
{
    if(is_empty(d))
        return -1;
    
    return d->data[d->rear];
}

int main()
{
    DequeType d;
    init_deque(&d);
    
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        char s[11];
        scanf("%s", s);
        
        int n = 0;
        
        if(strcmp(s, "push_front") == 0)
        {
            scanf("%d", &n);
            
            add_front(&d, n);
        }
        
        else if(strcmp(s, "push_back") == 0)
        {
            scanf("%d", &n);
            
            add_rear(&d, n);
        }
        
        else if(strcmp(s, "pop_front") == 0)
        {
            n = delete_front(&d);
            printf("%d\n", n);
        }
        
        else if(strcmp(s, "pop_back") == 0)
        {
            n = delete_rear(&d);
            printf("%d\n", n);
        }
        
        else if(strcmp(s, "size") == 0)
        {
            n = size(&d);
            printf("%d\n", n);
        }
        
        else if(strcmp(s, "empty") == 0)
        {
            if(is_empty(&d))
                printf("1\n");
                
            else
                printf("0\n");
        }
        
        else if(strcmp(s, "front") == 0)
        {
            n = get_front(&d);
            printf("%d\n", n);
        }
        
        else if(strcmp(s, "back") == 0)
        {
            n = get_rear(&d);
            printf("%d\n", n);
        }
    }
    
    return 0;
}

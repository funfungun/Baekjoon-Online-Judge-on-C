//c언어로 쉽게 풀어쓴 자료구조 p.114 참고

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000

typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s)//스택 초기화
{
    s->top = -1;
}

void push(StackType *s, element item)//삽입
{
    s->data[++(s->top)] = item;
}

element pop(StackType *s)//삭제
{
    return s->data[(s->top)--];
}

int main()
{
    StackType s;
    init_stack(&s);
    
    int sum = 0;
    int K;
    scanf("%d", &K);
    
    for(int i=0; i<K; i++)
    {
        int num;
        scanf("%d", &num);
        
        if(num == 0)
            pop(&s);
            
        else
            push(&s, num);
    }
    
    for(int i=s.top; i>=0; i--)
        sum += pop(&s);
    
    printf("%d", sum);
    
    return 0;
}

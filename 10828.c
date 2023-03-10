//c언어로 쉽게 풀어쓴 자료구조 p.114 참고

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

//스택 정의
typedef int element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;//스택의 top 변수가 -1 값을 가지면 공백
}

//공백 검출 함수
int empty(StackType *s)
{
    return (s->top == -1);
}

//포화 검출 함수
int full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

//스택 크기 반환 함수
int size(StackType *s)
{
    return (s->top)+1;//공백일 때 top이 -1이므로 0이 되려면 +1을 해줌
}

//삽입 함수
void push(StackType *s, element item)
{
    if(full(s))
        return;
    
    s->data[++(s->top)] = item;//top을 먼저 증가시키고 그 자리에 값 삽입
}

//삭제 함수
element pop(StackType *s)
{
    if(empty(s))
        return -1;
    
    return s->data[(s->top)--];//top 변수가 가리키는 데이터를 반환하고, top은 하나 줄어듦
}

//피크 함수
element top(StackType *s)
{
    if(empty(s))
        return -1;

    return s->data[s->top];//top 변수가 가리키는 데이터 반환
}

int main()
{
    StackType s;
    
    init_stack(&s);
    
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
            
            push(&s, n);
        }
        
        if(strcmp(str, "pop") == 0)
            printf("%d\n", pop(&s));
            
        if(strcmp(str, "size") == 0)
            printf("%d\n", size(&s));
        
        if(strcmp(str, "empty") == 0)
            printf("%d\n", empty(&s));
            
        if(strcmp(str, "top") == 0)
            printf("%d\n", top(&s));
    }
    
    return 0;
}

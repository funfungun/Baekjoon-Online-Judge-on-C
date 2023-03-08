#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 51

//c언어로 쉽게 풀어쓴 자료구조 p.122 참고

typedef char element;//문자형 요소

typedef struct//스택 정의
{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;


void init_stack(StackType *s)//초기화
{
    s->top = -1;
}


int is_empty(StackType *s)//공백 체크
{
    return (s->top==-1);
}


int is_full(StackType *s)//포화 체크
{
    return (s->top==(MAX_STACK_SIZE-1));
}


void push(StackType *s, element item)//삽입
{
    if(is_full(s))
        return;
        
    else
        s->data[++(s->top)] = item;
}


element pop(StackType *s)//제거
{
    if(is_empty(s))
        exit(1);
        
    else
        return s->data[(s->top)--];
}


int check_matching(char in[])//괄호 문자열 체크 함수(문제 없으면 1, 있으면 0)
{
    StackType s;
    init_stack(&s);
    
    for(int i=0; i<strlen(in); i++)//현재 문자열 순회
    {
        if(in[i] == '(')// '('이면
            push(&s, in[i]);//스택에 삽입 후 다음 문자로
        
        else if(in[i] == ')')// ')'이면
        {
            if(is_empty(&s))//스택에 저장된 '('가 없으면 잘못 태어난 놈
                return 0;
                
            else// '('가 있으면
                pop(&s);// '(' 삭제
        }
    }
    
    if(!is_empty(&s))//순회를 다 했는데 남은 '('가 있다면 실패
        return 0;
        
    return 1;//문제가 없으면 1 반환
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        char str[51];
        scanf("%s", str);
        
        if(check_matching(str) == 1)
            printf("YES\n");
            
        else
            printf("NO\n");
    }
    
    return 0;
}
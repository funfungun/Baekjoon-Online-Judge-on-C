//c언어로 쉽게 풀어쓴 자료구조 p.133 참고

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
    if(is_full(s))
        return;
        
    else
        s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if(is_empty(s))
        return;
        
    else
        return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if(is_empty(s))
        return;
        
    else
        return s->data[(s->top)];
}

int prec(char op)//연산자의 우선순위 반환
{
    switch(op)
    {
        case '(' :
        case ')' :
            return 0;
            
        case '+' :
        case '-' :
            return 1;
            
        case '*' :
        case '/' :
            return 2;
    }
    
    return -1;
}

void infix_to_postfix(char exp[])//중위 표기 -> 후위 표기
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    
    init_stack(&s);
    
    for(i=0; i<len; i++)
    {
        ch = exp[i];
        
        switch(ch)
        {
            case '+' ://문자가 연산자면
            case '-' :
            case '*' :
            case '/' :
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))))//해당 문자의 연산자가 스택의 연산자들보다 우선순위가 낮거나
                    printf("%c", pop(&s));                          //작으면 스택에 쌓아둔 연산자를 먼저 삭제 후 출력.
                    
                push(&s, ch);//그 다음 스택에 해당 문자의 연산자를 추가.
                break;
                
            case '(' ://(는 일단 쌓는다.
                push(&s, ch);
                break;
                
            case ')' ://)를 만나면 일단 임시변수에 스택의 top을 초기값으로 저장. 
                top_op = pop(&s);
                
                while(top_op != '(')//(를 만날때까지
                {
                    printf("%c", top_op);//스택의 top 출력
                    top_op = pop(&s);
                }
                
                break;
                
            default ://피연산자면
                printf("%c", ch);//무지성 출력
                break;
        }
    }
    
    while(!is_empty(&s))//마지막 남는 연산자 출력
        printf("%c", pop(&s));
}

int main()
{
    char s[100];
    scanf("%s", s);
    infix_to_postfix(s);
    
    return 0;
}

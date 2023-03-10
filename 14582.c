#include <stdio.h>

int main()
{
    int A[9];
    int B[9];
    
    scanf("%d", &A[0]);
    
    for(int i=1; i<9; i++)
    {
        scanf("%d", &A[i]);
        A[i] += A[i-1];
    }
    
    scanf("%d", &B[0]);
    
    for(int i=1; i<9; i++)
    {
        scanf("%d", &B[i]);
        B[i] += B[i-1];
    }
    
    int temp = 0;//역전패 판단 변수
    
    if(A[0] > 0)//A팀 선공이므로 1회부터 선취점을 냈다면 무조건 역전패
    {
        temp = 1;
        printf("Yes");
    }
    
    else//남은 이닝동안 이전 이닝 B팀의 점수보다 A팀의 점수가 많은 이닝이 있으면 역전패
    {
        for(int i=1; i<9; i++)
        {                     
            if(A[i] > B[i-1])
            {
                temp = 1;
                printf("Yes");
                break;
            }
        }
    }
    
    if(temp == 0)
        printf("No");
    
    return 0;
}

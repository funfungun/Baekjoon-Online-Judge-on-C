#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    //단순 규칙 찾기
    if(N%2 == 1)
        printf("SK");
        
    else
        printf("CY");
        
    return 0;
}

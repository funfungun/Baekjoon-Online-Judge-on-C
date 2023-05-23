#include <stdio.h>

int main()
{
    long long N;
    scanf("%lld", &N);
    
    //단순 추론
    if(N%2 == 1)
        printf("SK");
        
    else
        printf("CY");
        
    return 0;
}

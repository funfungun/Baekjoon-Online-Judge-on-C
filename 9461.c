#include <stdio.h>

int main()
{
    //수열에서 규칙 찾기
    long long P[101];
    P[0] = 1;
    P[1] = 1;
    P[2] = 1;
    
    for(int i=3; i<101; i++)
        P[i] = P[i-3] + P[i-2];
    
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        int N;
        scanf("%d", &N);
        
        printf("%lld\n", P[N-1]);
    }
    
    return 0;
}

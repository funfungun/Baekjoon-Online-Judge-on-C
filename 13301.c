#include <stdio.h>

int main()
{
    long long dp[81];
    
    dp[1] = 1;
    dp[2] = 1;
    
    //피보나치 DP
    for(int i=3; i<81; i++)
        dp[i] = dp[i-2] + dp[i-1];
        
    int N;
    scanf("%d", &N);
    
    if(N == 1)
        printf("1");
        
    else
        printf("%lld", (dp[N-1]+dp[N])*2 + dp[N]*2);
    
    return 0;
}

#include <stdio.h>

int main()
{
    long long f[117];
    f[1] = 1;
    f[2] = 1;
    f[3] = 1;
    
    //f(n) = f(n-1) + f(n-3)
    for(int i=4; i<117; i++)
        f[i] = f[i-1] + f[i-3];
        
    int n;
    scanf("%d", &n);
    
    printf("%lld", f[n]);
    
    return 0;
}

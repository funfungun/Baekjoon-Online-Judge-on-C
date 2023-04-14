#include <stdio.h>

//유클리드 호제법
int GCD(int a, int b)
{
    if(a%b == 0)
        return b;
        
    else
        return GCD(b, a%b);
}

int main()
{
    int n,m;
    scanf("%d:%d", &n, &m);
    printf("%d:%d", n/GCD(n,m), m/GCD(n,m));
    
    return 0;
}

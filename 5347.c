#include <stdio.h>

//유클리드 호제법
long long GCD(long long a, long long b)
{
    if(a%b == 0)
        return b;
        
    else
        return GCD(b, a%b);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    //최대공약수로 최소공배수 만들기
    for(int i=0; i<n; i++)
    {
        long long A,B;
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", GCD(A, B) * A/GCD(A, B) * B/GCD(A, B));
    }
    
    return 0;
}

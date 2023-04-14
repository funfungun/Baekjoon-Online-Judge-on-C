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
    long long A,B;
    scanf("%lld %lld", &A, &B);
    
    //최대공약수로 최소공배수 찾기
    long long gcd = GCD(A, B);
    printf("%lld", gcd*(A/gcd)*(B/gcd));
    
    return 0;
}

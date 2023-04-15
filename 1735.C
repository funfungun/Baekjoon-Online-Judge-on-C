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
    int A1,B1;
    int A2,B2;
    
    scanf("%d %d\n%d %d", &A1, &B1, &A2, &B2);
    
    int B = GCD(B1, B2) * (B1/GCD(B1, B2)) * (B2/GCD(B1, B2));//공통분모는 최소공배수
    int A = (B/B1)*A1 + (B/B2)*A2;//분자끼리 더함
    
    printf("%d %d", A/GCD(A, B), B/GCD(A, B));//최대공약수로 약분
    
    return 0;
}

#include <stdio.h>

int main()
{
    int A[46];
    int B[46];
    
    A[0] = 1;
    B[0] = 0;
    A[1] = 0;
    B[1] = 1;
    
    //피보나치 같은 느낌
    for(int i=2; i<46; i++)
    {
        A[i] = A[i-2] + A[i-1];
        B[i] = B[i-2] + B[i-1];
    }
    
    int K;
    scanf("%d", &K);
    
    printf("%d %d", A[K], B[K]);
    
    return 0;
}

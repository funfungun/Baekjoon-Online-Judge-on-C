#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int A[n];
    int B[n];
    
    //단순 구현
    scanf("%d", &A[0]);
    B[0] = A[0];
    
    for(int i=1; i<n; i++)
    {
        B[i] = B[i-1];
        B[i]++;
        scanf("%d", &A[i]);
        
        if(A[i] <= B[i])
            B[i] = A[i];
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", B[i]);
        
    return 0;
}

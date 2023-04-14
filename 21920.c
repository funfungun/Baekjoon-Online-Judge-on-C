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
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
        
    int X;
    scanf("%d", &X);
    
    double sum = 0;
    int count = 0;
    
    //서로소 평균 구하기
    for(int i=0; i<N; i++)
    {
        if(GCD(X, arr[i]) == 1)
        {
            sum += arr[i];
            count++;
        }
    }
    
    printf("%f", sum/count);
    
    return 0;
}

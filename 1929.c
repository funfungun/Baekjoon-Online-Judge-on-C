#include <stdio.h>

//에라토스테네스의 체
int main()
{
    int M,N;
    scanf("%d %d", &M, &N);
    
    int arr[1000001] = {0,};
    
    for(int i=2; i<=N; i++)
        arr[i] = i;
        
    for(int i=2; i<=N; i++)
    {
        if(arr[i] == 0)
            continue;
            
        for(int j=i+i; j<=N; j+=i)
            arr[j] = 0;
    }
    
    for(int i=M; i<=N; i++)
    {
        if(arr[i] != 0)
            printf("%d\n", arr[i]);
    }
    
    return 0;
}

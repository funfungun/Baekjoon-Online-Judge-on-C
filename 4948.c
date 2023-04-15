#include <stdio.h>

//에라토스테네스의 체
int main()
{
    int N = 300000;
    int arr[300001] = {0,};
    
    for(int i=2; i<=N; i++)
        arr[i] = i;
        
    for(int i=2; i<=N; i++)
    {
        if(arr[i] == 0)
            continue;
            
        for(int j=i+i; j<=N; j+=i)
            arr[j] = 0;
    }
    
    while(1)
    {
        int n;
        scanf("%d", &n);
        
        if(n == 0)
            break;
        
        int count = 0;
        
        //n보다 크고 2*n보다 작거나 같은 소수의 개수
        for(int i=n+1; i<=2*n; i++)
        {
            if(arr[i] != 0)
                count++;
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}

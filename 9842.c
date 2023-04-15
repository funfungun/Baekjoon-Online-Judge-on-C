#include <stdio.h>

//에라토스테네스의 체
int main()
{
    int N = 200000;
    int arr[200001] = {0,};
    
    for(int i=2; i<=N; i++)
        arr[i] = i;
        
    for(int i=2; i<=N; i++)
    {
        if(arr[i] == 0)
            continue;
            
        for(int j=i+i; j<=N; j+=i)
            arr[j] = 0;
    }
    
    int n;
    scanf("%d", &n);
    
    int count = 0;
    
    for(int i=2; i<=N; i++)
    {
        if(arr[i] != 0)
            count++;
            
        if(count == n)
        {
            printf("%d", i);
            break;
        }
    }
    
    return 0;
}

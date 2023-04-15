#include <stdio.h>

//에라토스테네스의 체
int main()
{
    int N,K;
    scanf("%d %d", &N, &K);
    
    int arr[1001] = {0,};
    int count = 0;
    int check = 0;
    
    for(int i=2; i<=N; i++)
        arr[i] = i;
        
    for(int i=2; i<=N; i++)
    {
        if(arr[i] == 0)
            continue;
        
        for(int j=i; j<=N; j+=i)
        {
            //이미 지워졌다면 또 지울 필요가 없다
            if(arr[j] == 0)
                continue;
            
            arr[j] = 0;
            count++;
            
            if(count == K)
            {
                printf("%d", j);
                check = 1;
                break;
            }
        }
        
        if(check)
            break;
    }
    
    return 0;
}

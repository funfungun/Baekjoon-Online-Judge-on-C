#include <stdio.h>

//에라토스테네스의 체
int main()
{
    int N = 100000;
    int arr[100001] = {0,};
    
    for(int i=2; i<=N; i++)
        arr[i] = i;
        
    for(int i=2; i<=N; i++)
    {
        if(arr[i] == 0)
            continue;
            
        for(int j=i+i; j<=N; j+=i)
            arr[j] = 0;
    }
    
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        int sum = 0;
        
        //입력 받은 수보다 작지 않은 가장 작은 소수들의 합
        for(int j=0; j<5; j++)
        {
            int num;
            scanf("%d", &num);
            
            for(int k=num; k<=N; k++)
            {
                if(arr[k] != 0)
                {
                    sum += arr[k];
                    break;
                }    
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}

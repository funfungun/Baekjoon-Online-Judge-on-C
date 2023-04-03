#include <stdio.h>

int main()
{
    int N,K;
    scanf("%d %d", &N, &K);
    
    int arr[N];
    int temp = K;
    int count = 0;
    
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    
    //K 이하의 가장 큰 수부터 최대한 거슬러주면 최소의 동전이 될 것이 보장
    for(int i=N-1; i>=0; i--)
    {
        if(K>=arr[i])
        {
            count += (temp/arr[i]);
            temp %= arr[i];
            
            if(temp == 0)
                break;
        }
    }
    
    printf("%d", count);
    
    return 0;
}

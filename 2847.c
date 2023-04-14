#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int count = 0;
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    
    //이전 레벨은 현재 레벨보다 최소 1 작아야 함
    for(int i=N-1; i>0; i--)
    {
        if(arr[i] <= arr[i-1])
        {
            count += arr[i-1] - arr[i] + 1;
            arr[i-1] -= (arr[i-1] - arr[i]) + 1;
        }
    }
    
    printf("%d", count);
    
    return 0;
}

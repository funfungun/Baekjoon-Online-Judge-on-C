#include <stdio.h>
#include <stdlib.h>

int compare(const void* index1, const void* index2)
{
    if(*(int *)index1 > *(int *)index2)
        return 1;
        
    else if(*(int *)index1 == *(int *)index2)
        return 0;
        
    else
        return -1;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int sum = 0;
    int temp = 0;
    int arr[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    qsort((void *)arr, (size_t)N, sizeof(int), compare);
    
    //가장 적게 걸리는 사람부터 인출하면 최소가 될 것이 보장
    for(int i=0; i<N; i++)
    {
        sum += (temp + arr[i]);
        temp += arr[i];
    }
    
    printf("%d", sum);
    
    return 0;
}

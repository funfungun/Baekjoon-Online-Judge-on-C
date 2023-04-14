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
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
        
    qsort((void *)arr, (size_t)N, sizeof(int), compare);
    
    //정렬 후 해당 인덱스 값과 남은 인덱스의 수만큼 곱했을 때 최대값 찾기
    int sum = arr[0]*N;
    
    for(int i=1; i<N; i++)
    {
        if(arr[i]*(N-i) > sum)
            sum = arr[i]*(N-i);
    }
    
    printf("%d", sum);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int compare(const void *index1, const void *index2)//오름차순
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
        
    qsort((void *)arr, (size_t)N, sizeof(int), compare);//퀵 정렬
    
    printf("%d ", arr[0]);
    
    for(int i=1; i<N; i++)
    {
        if(arr[i-1] != arr[i])//중복 제외
            printf("%d ", arr[i]);
    }
    
    return 0;
}
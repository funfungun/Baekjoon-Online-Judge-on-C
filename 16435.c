#include <stdio.h>
#include <stdlib.h>

int compare(const void* index1, const void* index2)//오름차순
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
    int N,L;
    scanf("%d %d", &N, &L);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
        
    qsort((void *)arr, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    //came from the bottom
    for(int i=0; i<N; i++)
    {
        if(arr[i] <= L)
            L++;
    }
    
    printf("%d", L);
    
    return 0;
}

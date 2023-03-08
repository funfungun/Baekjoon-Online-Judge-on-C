#include <stdio.h>
#include <stdlib.h>

//퀵 정렬 라이브러리 참고 - c언어로 쉽게 풀어쓴 자료구조 p.478
int compare(const void *index1, const void *index2)
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
    
    for(int i=0; i<N; i++)
        printf("%d\n", arr[i]);
        
    return 0;
}
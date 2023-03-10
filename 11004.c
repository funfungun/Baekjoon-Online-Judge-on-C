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
    int N,K;
    scanf("%d %d", &N, &K);
    
    int A[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
        
    qsort((void *)A, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    printf("%d", A[K-1]);
    
    return 0;
}

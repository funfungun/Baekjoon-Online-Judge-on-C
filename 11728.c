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
    int N,M;
    scanf("%d %d", &N, &M);
    
    int temp[N+M];
    
    for(int i=0; i<N+M; i++)
    {
        if(i<N)
            scanf("%d", &temp[i]);
        
        else
            scanf("%d", &temp[i]);
    }
    
    qsort((void *)temp, (size_t)(N+M), sizeof(int), compare);//퀵 정렬 라이브러리
    
    for(int i=0; i<N+M; i++)
        printf("%d ", temp[i]);
    
    return 0;
}

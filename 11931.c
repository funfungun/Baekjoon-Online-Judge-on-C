#include <stdio.h>
#include <stdlib.h>

int compare(const void *index1, const void *index2)//내림차순
{
    if(*(int *)index1 > *(int *)index2)
        return -1;
        
    else if(*(int *)index1 == *(int *)index2)
        return 0;
        
    else
        return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int temp[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &temp[i]);
    
    qsort((void *)temp, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    for(int i=0; i<N; i++)
        printf("%d\n", temp[i]);
    
    return 0;
}

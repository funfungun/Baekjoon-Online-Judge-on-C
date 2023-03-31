#include <stdio.h>
#include <stdlib.h>

int compare1(const void *index1, const void *index2)//오름차순
{
    if(*(int *)index1 > *(int *)index2)
        return 1;
        
    else if(*(int *)index1 == *(int *)index2)
        return 0;
        
    else
        return -1;
}

int compare2(const void *index1, const void *index2)//내림차순
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
    
    int A[N];
    int B[N];
    
    int S = 0;
    
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
        
    for(int i=0; i<N; i++)
        scanf("%d", &B[i]);
        
    qsort((void *)A, (size_t)N, sizeof(int), compare1);//A는 오름차순 정렬
    qsort((void *)B, (size_t)N, sizeof(int), compare2);//B는 내림차순 정렬
    
    for(int i=0; i<N; i++)
        S += (A[i]*B[i]);//A의 가장 작은 원소와 B의 가장 큰 원소 순서대로 곱해주면 S의 값이 최소가 될 것이 보장
    
    printf("%d", S);
    
    return 0;
}

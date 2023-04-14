#include <stdio.h>
#include <stdlib.h>

int compare(const void* index1, const void* index2)//내림차순
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
    int N,M,K;
    scanf("%d %d %d", &N, &M, &K);
    
    int check = 1;
    int sum = 0;
    int A[N];
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
        
    qsort((void *)A, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    //가장 많은 회원부터 빌려야 최소
    for(int i=0; i<N; i++)
    {
        sum += A[i];
        
        if(M*K <= sum)
        {
            check = 0;
            printf("%d", i+1);
            break;
        }
    }
    
    if(check)
        printf("STRESS");
        
    return 0;
}

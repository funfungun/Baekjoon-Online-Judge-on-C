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
    int N,M;
    scanf("%d %d", &N, &M);
    
    int A[M];
    int B[M];
    
    int sum = 0;
    
    for(int i=0; i<M; i++)
        scanf("%d %d", &A[i], &B[i]);
    
    //퀵 정렬 라이브러리
    qsort((void *)A, (size_t)M, sizeof(int), compare);
    qsort((void *)B, (size_t)M, sizeof(int), compare);
    
    //낱개로 제일 싼 것으로 6개 사는 거랑 제일 싼 한 묶음이랑 비교
    //제일 싼 묶음으로 최대한 사고
    //남은 갯수는 묶음 하나 사고 남기는 게 이득인지, 낱개로 딱 맞춰 사는게 이득인지 비교
    if(A[0] <= B[0]*6)
    {
        if(N%6 == 0)
            sum = (N/6)*A[0];
            
        else
        {
            if(A[0] > (N%6)*B[0])
                sum = (N/6)*A[0] + (N%6)*B[0];
                
            else
                sum = ((N/6)+1)*A[0];
        }
    }
    
    else
        sum = N*B[0];
    
    printf("%d", sum);
    
    return 0;
}

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

int search(int s[], int low, int high, int key)//이진 탐색
{
    int mid;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        
        if(key < s[mid])
            high = mid - 1;
            
        else if(key > s[mid])
            low = mid + 1;
            
        else
            return 1;
    }
    
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int A[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
        
    qsort((void *)A, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    int M;
    scanf("%d", &M);
    
    int B[M];
    
    for(int i=0; i<M; i++)
        scanf("%d", &B[i]);
    
    for(int i=0; i<M; i++)
        printf("%d\n", search(A, 0, N-1, B[i]));
    
    return 0;
}

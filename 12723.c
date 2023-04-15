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
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        int n;
        scanf("%d", &n);
        
        int v1[n];
        int v2[n];
        
        for(int j=0; j<n; j++)
            scanf("%d", &v1[j]);
            
        for(int j=0; j<n; j++)
            scanf("%d", &v2[j]);
        
        //퀵 정렬 라이브러리
        qsort((void *)v1, (size_t)n, sizeof(int), compare);
        qsort((void *)v2, (size_t)n, sizeof(int), compare);
        
        long long Y = 0;
        
        //하나는 오름차순, 하나는 내림차순이라고 생각하면
        //같은 인덱스끼리 곱해 더하면 최소
        for(int j=0; j<n; j++)
            Y += v1[j] * v2[n-j-1];
            
        printf("Case #%d: %lld\n", i+1, Y);
    }
    
    return 0;
}

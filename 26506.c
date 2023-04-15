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
    int n;
    scanf("%d", &n);
    
    int S[n];
    for(int i=0; i<n; i++)
        scanf("%d", &S[i]);
        
    qsort((void *)S, (size_t)n, sizeof(int), compare);//퀵 정렬 라이브러리
    
    //오름차순 정렬 후 양끝에 있는 것들의 합이 최소가 되게
    int min = S[0] + S[n-1];
    
    for(int i=1; i<n/2; i++)
    {
        if(min > S[i] + S[n-i-1])
            min = S[i] + S[n-i-1];
    }
    
    printf("%d", min);
    
    return 0;
}

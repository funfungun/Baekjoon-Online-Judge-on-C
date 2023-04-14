#include <stdio.h>
#include <stdlib.h>

int compare(const void* index1, const void* index2)//내림차순
{
    if(*(int *)index1 > *(int *)index2)
        return -1;
        
    else if(*(int *)index1 > *(int *)index2)
        return 0;
        
    else
        return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int C[N];
    for(int i=0; i<N; i++)
        scanf("%d", &C[i]);
    
    qsort((void *)C, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    //내림차순 정렬 후 3n번째 것들만 거르면 됨
    int sum = 0;
    int n = 1;
    int temp = 3*n - 1;
    
    for(int i=0; i<N; i++)
    {
        if(i != temp)
            sum += C[i];
            
        else
        {
            n++;
            temp = 3*n - 1;
        }
    }
    
    printf("%d", sum);
    
    return 0;
}

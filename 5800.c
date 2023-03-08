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
    int K;
    scanf("%d", &K);
    
    for(int i=0; i<K; i++)
    {
        int N;
        scanf("%d", &N);
        
        int arr[N];
        
        for(int j=0; j<N; j++)
            scanf("%d", &arr[j]);
            
        qsort((void *)arr, (size_t)N, sizeof(int), compare);//퀵 정렬
        
        int min = arr[0];
        int max = arr[N-1];
        int gap = 0;
        
        for(int j=0; j<N-1; j++)
        {
            if(gap < arr[j+1] - arr[j])
                gap = arr[j+1] - arr[j];
        }
        
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i+1, max, min, gap);
    }
    
    return 0;
}
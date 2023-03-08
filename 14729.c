#include <stdio.h>
#include <stdlib.h>

int compare(const void* index1, const void* index2)//비내림차순
{
    if(*(double*)index1 > *(double*)index2)
        return 1;
        
    else if(*(double*)index1 == *(double*)index2)
        return 0;
        
    else
        return -1;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    double arr[N];
    
    for(int i=0; i<N; i++)
        scanf("%lf", &arr[i]);
        
    qsort((void *)arr, (size_t)N, sizeof(double), compare);//퀵 정렬
    
    for(int i=0; i<7; i++)
        printf("%.3f\n", arr[i]);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    if(*(int *)a > *(int *)b)
        return 1;
        
    else if(*(int *)a == *(int *)b)
        return 0;
        
    else
        return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    qsort((void *)arr, (size_t)n, sizeof(int), compare);
    
    //위 아래 제외 절사평균
    int temp = (int)round(n*0.3/2);
    int sum = 0;
    
    for(int i=temp; i<n-temp; i++)
        sum += arr[i];
    
    if(n)
        printf("%d", (int)round((double)sum/(n-(2*temp))));
        
    else
        printf("0");
    
    return 0;
}

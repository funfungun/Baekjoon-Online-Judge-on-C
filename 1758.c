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
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
        
    qsort((void *)arr, (size_t)N, sizeof(int), compare);//퀵 정렬 라이브러리
    
    long long sum = 0;
    
    //예제 4를 보면 많은 사람한테 최대한 뽑아먹는게 이득
    for(int i=0; i<N; i++)
    {
        if(arr[i] - i> 0)
            sum += arr[i] - i;
    }
    
    printf("%lld", sum);
    
    return 0;
}

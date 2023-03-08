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

int search(int s[], int low, int high, int key)//이분 탐색
{
    int mid;
    
    if(low<=high)
    {
        mid = (low+high) / 2;
        
        if(key == s[mid])
            return 1;
            
        else if(key < s[mid])
            return search(s, low, mid-1, key);
            
        else
            return search(s, mid+1, high, key);
    }
    
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int arr1[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &arr1[i]);
        
    qsort((void *)arr1, (size_t)N, sizeof(int), compare);//퀵 정렬 후
    
    int M;
    scanf("%d", &M);
    
    int arr2[M];
    
    for(int i=0; i<M; i++)
        scanf("%d", &arr2[i]);
    
    for(int i=0; i<M; i++)
        printf("%d ", search(arr1, 0, N-1, arr2[i]));//이분 탐색
    
    return 0;
}
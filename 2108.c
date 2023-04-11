#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int N;
    scanf("%d", &N);
    int arr[N];//N개의 수
    int often_minus[4001] = {0, };//음수 빈도수
    int often_plus[4001] = {0, };//양수 빈도수
    int sum = 0;
    
    scanf("%d", &arr[0]);
    
    if(arr[0] < 0)
        often_minus[arr[0]*(-1)]++;
        
    else
        often_plus[arr[0]]++;
    
    int min = arr[0];
    int max = arr[0];
    sum += arr[0];
    
    for(int i=1; i<N; i++)
    {
        scanf("%d", &arr[i]);
        
        if(arr[i] < 0)
            often_minus[arr[i]*(-1)]++;
        
        else
            often_plus[arr[i]]++;
        
        sum += arr[i];
        
        if(arr[i] < min)
            min = arr[i];
            
        if(arr[i] > max)
            max = arr[i];
    }
    
    qsort((void *)arr, (size_t)N, sizeof(int), compare);//퀵 정렬
    
    int most_often = often_minus[0];//최다 빈도수
    int mode = 0;//최빈값
    
	  //음수와 양수 따로 최다 빈도수 및 최빈값 결정
    for(int i=min; i<=max; i++)
    {
        if(i < 0)
        {
            if(most_often < often_minus[i*(-1)])
            {
                most_often = often_minus[i*(-1)];
                mode = i;
            }
        }
        
        else
        {
            if((most_often < often_plus[i]))
            {
                most_often = often_plus[i];
                mode = i;
            }
        }
    }
    
	  //처음 결정된 최다 빈도수와 같은 값이 나오는 바로 다음의 인덱스가 여러 개의 최빈값 중 두번째로 작은 값 
    for(int i=mode+1; i<=max; i++)
    {
        if(i < 0)
        {
            if(most_often == often_minus[i*(-1)])
            {
                mode = i;
                break;
            }
        }
        
        else
        {
            if(most_often == often_plus[i])
            {
                mode = i;
                break;
            }
        }
    }
    
    printf("%d\n%d\n%d\n%d", (int)(round((double)sum/N)), arr[N/2], mode, max-min);

    return 0;
}

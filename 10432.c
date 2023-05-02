#include <stdio.h>

int main()
{
    int P;
    scanf("%d", &P);
    
    for(int i=0; i<P; i++)
    {
        int T;
        scanf("%d", &T);
        
        int sum = 0;
        
        int arr[12];
        for(int j=0; j<12; j++)
            scanf("%d", &arr[j]);
        
        int min;
        
        //첫 수와 마지막 수는 0이므로 index는 1~10
        for(int j=1; j<11; j++)
        {
            //부분수열을 하나씩 늘리고 그때 부분수열의 최솟값을 시작과 끝의 수와 비교
            for(int k=j; k<11; k++)
            {
                min = arr[k];
                
                for(int l=j; l<k; l++)
                {
                    if(arr[l] < min)
                        min = arr[l];
                }
                
                if(min > arr[j-1] && min > arr[k+1])
                    sum++;
            }
        }
        
        printf("%d %d\n", T, sum);
    }
    
    return 0;
}

#include <stdio.h>
#define SIZE 100

int main()
{
    int arr[SIZE][SIZE] = {};
    
    int count = 0;
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        
        for(int j=y; j<y+10; j++)
        {
            for(int k=x; k<x+10; k++)
                arr[j][k] = 1;//행렬로 생각하고, 입력받은 좌표가 원점과 가장 가까운 꼭짓점이니
        }                     //10씩 나아가면서 1로 초기화
    }
    
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(arr[i][j])//브루트포스로 좌표가 1로 초기화됐으면 카운트
                count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
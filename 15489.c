#include <stdio.h>

int pascal[31][31];

int main()
{
    for(int i=1; i<31; i++)
    {
        pascal[i][1] = 1;
        pascal[i][i] = 1;
    }
    
    for(int i=3; i<31; i++)
    {
        for(int j=2; j<i; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    
    int sum = 0;
    int temp = 0;
    int R,C,W;
    scanf("%d %d %d", &R, &C, &W);
    
    //탑다운 방식으로, C번째 수에서 층 높이만큼 우측으로 이동
    for(int i=R; i<R+W; i++)
    {
        temp++;
        for(int j=0; j<temp; j++)
            sum += pascal[i][C+j];
    }
    
    printf("%d", sum);
    
    return 0;
}

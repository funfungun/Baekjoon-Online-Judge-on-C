#include <stdio.h>

int pascal[101][101];

int main()
{
    for(int i=1; i<101; i++)
    {
        pascal[i][1] = i;
        pascal[i][i] = 1;
    }
    
    for(int i=3; i<101; i++)
    {
        for(int j=2; j<i; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    
    int N;
    scanf("%d", &N);
    
    //대각선의 교차점 한 개는 N각형의 꼭짓점 4개의 조합
    printf("%d", pascal[N][4]);
    
    return 0;
}

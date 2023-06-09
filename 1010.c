#include <stdio.h>

//파스칼의 삼각형 DP ver.
int pascal[30][30];

int main()
{
    for(int i=1; i<30; i++)
    {
        pascal[i][1] = i;
        pascal[i][i] = 1;
    }
    
    for(int i=3; i<30; i++)
    {
        for(int j=2; j<i; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
    }
    
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {
        int N,M;
        scanf("%d %d", &N, &M);
        printf("%d\n", pascal[M][N]);
    }
    
    return 0;
}

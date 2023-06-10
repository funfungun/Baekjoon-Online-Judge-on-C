#include <stdio.h>

//파스칼의 삼각형 DP ver.
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
    
    int n,k;
    scanf("%d %d", &n, &k);
    printf("%d", pascal[n][k]);
    
    return 0;
}

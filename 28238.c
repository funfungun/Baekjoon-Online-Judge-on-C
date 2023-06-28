#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n][5];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
            scanf("%d", &arr[i][j]);
    }
    
    int max = 0;
    int I = 0;
    int J = I+1;
    
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            int count = 0;
            
            //이틀씩 조합해 모두 참석 가능한 n명의 학생을 전부 카운트해 최대값 갱신
            for(int k=0; k<n; k++)
            {
                if(arr[k][i] == 1 && arr[k][j] == 1)
                    count++;
            }
            
            if(count > max)
            {
                I = i;
                J = j;
                max = count;
            }
        }
    }
    
    printf("%d\n", max);
    for(int i=0; i<5; i++)
    {
        if(i!=0)
            printf(" ");
    
        if(i==I || i == J)
            printf("1");
            
        else
            printf("0");
    }
    
    return 0;
}

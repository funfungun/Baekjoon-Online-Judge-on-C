#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int num = 0;
    
    for(int i=0; i<N; i++)
    {
        int n;
        scanf("%d", &n);
        
        int temp = 0;
        
        for(int j=1; j<=n; j++)//입력 받은 수를 1부터 자기 자신까지의 수 들로 나누어 약수의 수 계산 
        {
            if(n%j == 0)
                temp++;
        }
        
        if(temp==2)//약수가 1과 자기 자신. 총 두 개이면 소수
            num++;
    }
    
    printf("%d", num);
    
    return 0;
}

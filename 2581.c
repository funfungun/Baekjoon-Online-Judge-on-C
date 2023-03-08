#include <stdio.h>

int main()
{
    int N,M;
    scanf("%d\n%d", &N, &M);
    
    int num = 0;
    int sum = 0;
    int min = 0;
    
    for(int i=N; i<=M; i++)//N이상 M이하의 자연수 중
    {
        int temp = 0;
        
        for(int j=1; j<=i; j++)//1부터 자기 자신까지의 수로 나누었을 때 약수의 갯수 계산
        {
            if(i%j == 0)
                temp++;
        }
        
        if(temp==2)//소수이면
        {
            num++;//소수 개수 증가
            
            if(num==1)//수가 커져봐야 최초 발견된 소수보다 작을 수 없으므로 최솟깂에 저장
                min = i;
            
            sum += i;//합계
        }
    }
    
    if(num <= 0)
        printf("-1");
        
    else
        printf("%d\n%d", sum, min);
        
    return 0;
}
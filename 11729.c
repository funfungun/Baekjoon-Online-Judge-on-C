// c언어로 쉽게 풀어쓴 자료구조 p.61 참고

#include <stdio.h>

int count = 0;

void count_hanoi(int n, int from, int temp, int to)//수행 횟수를 계산을 위해 전역 변수를 사용
{
    if(n==1)
        count++;
    
    else
    {
        count_hanoi(n-1, from, to, temp);
        count++;
        count_hanoi(n-1, temp, from, to);
    }
}

void hanoi(int n, int from, int temp, int to)//n개의 원판을 from에서 temp를 이용해 to로 이동
{//함수의 매개변수와 함수 호출시의 인수를 구분해서 볼 것
    if(n==1)//from에 있는 한 개의 원판을 to로 옮김
        printf("%d %d\n", from, to);
    
    else
    {
        hanoi(n-1, from, to, temp);//n-1개의 원판을 from에서 to를 이용해 temp까지 옮긴다
        printf("%d %d\n", from, to);//from에 있는 한 개의 원판을 to로 옮김
        hanoi(n-1, temp, from, to);//남은 n-1개의 원판을 temp에서 from을 이용해 to로 옮긴다
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    
    count_hanoi(N, 1, 2, 3);
    printf("%d\n", count);
    
    hanoi(N, 1, 2, 3);
    
    return 0;
}

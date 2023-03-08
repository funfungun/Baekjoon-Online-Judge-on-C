#include <stdio.h>

int d(int n)//d(n) 정의
{
    if(n<10)
        return n+n;
        
    else if(n>=10 && n<100)
        return n+(n/10)+(n%10);
        
    else if(n>=100 && n<1000)
        return n+(n/100)+((n%100)/10)+(n%10);
        
    else if(n>=1000 && n<10000)
        return n+(n/1000)+((n%1000)/100)+(((n%1000)%100)/10)+(n%10);
        
    else
        return n+1;
} 

int main()
{
    int arr[10036] = {};//생성자가 9999일 때, d(n)은 10035이므로 10036 크기의 배열 선언 및 0으로 초기화
    
    for(int i=1; i<=10000; i++)//생성자를 통해 나타나는 d(n) 인덱스 값은 1로 설정
        arr[d(i)] = 1;
        
    for(int i=1; i<=10000; i++)//나머지의 셀프 넘버 인덱스를 만나면 인덱스 번호 출력
    {
        if(arr[i] == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
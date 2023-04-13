#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int check = 1;
    int count = 0;
    int temp = 0;
    
    count = N/5;
    temp = N%5;
    
    /*5원으로 최대한 나눠주고, 나머지가 3원으로 나눠 떨어지지 않으면
    5원의 갯수를 하나씩 줄이면서 나머지가 3원으로 나눠 떨어지는지 확인*/
    if(temp)
    {
        if(temp%3 != 0)
        {
            while(temp)
            {
                count--;
            
                if(count < 0)
                {
                    check = 0;
                    printf("-1");
                    break;
                }
            
                temp += 5;
                
                if(temp%3 == 0)
                {
                    count += temp/3;
                    temp %= 3;
                }
            }
        }
        
        else
            count += temp/3;
    }
    
    if(check)
        printf("%d", count);
        
    return 0;
}

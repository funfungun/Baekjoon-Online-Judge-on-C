#include <stdio.h>
#include <string.h>

int checker(char s[])//체크 함수(1이면 yes, 0이면 no)
{
    for(int i=0; i<strlen(s); i++)//문자열 순회
    {
        if(s[i] != s[i+1])//앞뒤 문자가 다르면
        {
            for(int j=i+2; j<strlen(s); j++)//앞의 문자가 기준점
            {
                if(s[i] == s[j])//나머지 문자열 중에 같은 문자가 있으면 0반환
                    return 0;
            }
        }
    }
    
    return 1;//0이 반환되지 않은 경우에는 1반환
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int count = 0;
    
    for(int i=0; i<N; i++)
    {
        char s[101];
        scanf("%s", s);
        
        if(checker(s) == 1)
            count++;
    }
    
    printf("%d", count);
    
    return 0;
}
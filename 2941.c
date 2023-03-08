#include <stdio.h>

int main()
{
    char s[101];
    scanf("%s", s);
    
    int count = 0;
    int temp = 0;
    
    for(int i=0; i<101; i++)
    {
        if(s[i] == '\0')
            break;
            
        count++;
    }
    
    for(int i=0; i<count; i++)//크로아티아 문자를 만나면 그 문자의 끝 인덱스로 옮겨서 하나의 문자처럼 생각
    {
        if(s[i] == 'c' && s[i+1] == '=')
            i++;
            
        else if(s[i] == 'c' && s[i+1] == '-')
            i++;
            
        else if(s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=')
            i += 2;
            
        else if(s[i] == 'd' && s[i+1] == '-')
            i++;
            
        else if(s[i] == 'l' && s[i+1] == 'j')
            i++;
            
        else if(s[i] == 'n' && s[i+1] == 'j')
            i++;
            
        else if(s[i] == 's' && s[i+1] == '=')
            i++;
            
        else if(s[i] == 'z' && s[i+1] == '=')
            i++;
            
        temp++;
    }
    
    printf("%d", temp);
    
    return 0;
}
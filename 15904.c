#include <stdio.h>
#include <string.h>

int main()
{
    char s[1002];
    fgets(s, sizeof(s), stdin);
    
    int U = 0, C = 0, P = 0, c = 0, i = 0, j = 0, k = 0, l = 0;
    int len = strlen(s)-1;
    
    //단순구현
    for(i=0; i<len; i++)
    {
        if(s[i] == 'U')
        {
            U++;
            break;
        }
    }
    
    if(U)
    {
        for(j=i+1; j<len; j++)
        {
            if(s[j] == 'C')
            {
                C++;
                break;
            }
        }
    }
    
    if(C)
    {
        for(k=j+1; k<len; k++)
        {
            if(s[k] == 'P')
            {
                P++;
                break;
            }
        }
    }
    
    if(P)
    {
        for(l=k+1; l<len; l++)
        {
            if(s[l] == 'C')
            {
                c++;
                break;
            }
        }
    }
    
    if(c)
        printf("I love UCPC");
        
    else
        printf("I hate UCPC");
    
    return 0;
}

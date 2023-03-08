#include <stdio.h>

int hansu(int n)
{
    if(n<100)
        return 1;
        
    else
    {
        if(((n/100) - ((n%100)/10) > 0) && (((n%100)/10) - (n%10)) == ((n/100) - ((n%100)/10)))
            return 1;
            
        else if(((n/100) - ((n%100)/10) == 0) && (((n%100)/10) - (n%10)) == ((n/100) - ((n%100)/10)))
            return 1;
            
        else if(((n/100) - ((n%100)/10) < 0) && (((n%100)/10) - (n%10)) == ((n/100) - ((n%100)/10)))
            return 1;
            
        else
            return 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int count = 0;
    
    for(int i=1; i<=n; i++)
    {
        if(hansu(i) == 1)
            count++;
    }
    
    printf("%d", count);
    
    return 0;
}
#include <stdio.h>

//유클리드 호제법
int GCD(int a, int b)
{
    if(a%b == 0)
        return b;
        
    else
        return GCD(b, a%b);
}

int main()
{
    int t;
    scanf("%d", &t);
    
    for(int i=0; i<t; i++)
    {
        long long sum = 0;
        
        int n;
        scanf("%d", &n);
        
        int arr[n];
        for(int j=0; j<n; j++)
            scanf("%d", &arr[j]);
            
        for(int j=0; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
                sum += GCD(arr[j], arr[k]);
        }
        
        printf("%lld\n", sum);
    }
    
    return 0;
}

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
    int N;
    scanf("%d", &N);
    
    int arr[N];
    scanf("%d", &arr[0]);
    for(int i=1; i<N; i++)
    {
        scanf("%d", &arr[i]);
        printf("%d/%d\n", arr[0]/GCD(arr[0], arr[i]), arr[i]/GCD(arr[0], arr[i]));
    }
    
    return 0;
}

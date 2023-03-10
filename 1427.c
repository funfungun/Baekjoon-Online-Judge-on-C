#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *index1, const void *index2)
{
    if(*(char *)index1 > *(char *)index2)
        return -1;//책에는 안 나왔지만 compare 함수의 return 값을 서로 바꿔주면
        
    else if(*(char *)index1 == *(char *)index2)
        return 0;
        
    else
        return 1;//오름차순 or 내림차순 선택 가능
}

int main()
{
    char N[11];
    scanf("%s", N);
    
    qsort((void *)N, (size_t)strlen(N), sizeof(char), compare);
    
    for(int i=0; i<strlen(N); i++)
        printf("%c", N[i]);
    
    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    double point_num = 0.0;
    double pointxgrade = 0.0;
    
    for(int i=0; i<20; i++)
    {
        char s[51];
        scanf("%s", s);
        
        double point;
        scanf("%lf", &point);
        point_num += point;
        
        char grade[3];
        scanf("%s", grade);
        
        if(strcmp(grade, "A+") == 0)
            pointxgrade += point * 4.5;
            
        else if(strcmp(grade, "A0") == 0)
            pointxgrade += point * 4.0;
            
        else if(strcmp(grade, "B+") == 0)
            pointxgrade += point * 3.5;
            
        else if(strcmp(grade, "B0") == 0)
            pointxgrade += point * 3.0;
            
        else if(strcmp(grade, "C+") == 0)
            pointxgrade += point * 2.5;
            
        else if(strcmp(grade, "C0") == 0)
            pointxgrade += point * 2.0;
            
        else if(strcmp(grade, "D+") == 0)
            pointxgrade += point * 1.5;
            
        else if(strcmp(grade, "D0") == 0)
            pointxgrade += point * 1.0;
            
        else if(strcmp(grade, "F") == 0)
            pointxgrade += point * 0;
            
        else if(strcmp(grade, "P") == 0)
            point_num -= point;
    }
    
    printf("%f", pointxgrade/point_num);
    
    return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include <stdarg.h>

int main(void)
{   
    int a = 10;
    int b = 20;
    float c = 123.456;

    printf("ceil %lf \n",ceil(c));
    printf("floor %lf \n ",floor(c));
    printf("absolute %lf \n ",fabs(c));
    printf("log %lf \n ",log(c));
    printf("mod %lf \n ",fmod(c,a));
    printf("sqrt %lf \n ",sqrt(c,a));

    return 0 ;
}


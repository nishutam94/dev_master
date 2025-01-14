#include<stdio.h>
int main()
{
    char a = 30;
    char b = 40;
    char c = a*b;
    
    printf("%d",c); //this will print -80 instead 1200 becouse char range is -128 to 127


    // similerly char a + 1 = 'b' character arthametic. 

    return 0;
}
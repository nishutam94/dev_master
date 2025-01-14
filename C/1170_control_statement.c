#include<stdio.h>
int main()
{
    int n = 10;

    start:
        printf("%d",n);
        n=n-1;

    if (n > 0)
        goto start;
        
    return 0;

}
#include<stdio.h>
int main()
{   int i = 10;
    printf("%d,%d,%d\n",i,i++,i++);
    i = 10;
    printf("%d,%d,%d\n",i,++i,++i);
    i = 10;
    printf("%d,%d,%d\n",i,i++,++i);
    i = 10;
    printf("%d,%d,%d\n",i,++i,i++);
    i = 10;
    printf("%d,%d,%d\n",i++,i++,i);


    return 0;
}
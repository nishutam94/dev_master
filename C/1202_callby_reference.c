#include<stdio.h>


int swap(int *a,int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
};

int main()
{   int a = 10;
    int b = 20;
    printf("%d%d\n",a,b);
    swap(&a,&b);
    printf("%d%d",a,b);

    return 0;
}
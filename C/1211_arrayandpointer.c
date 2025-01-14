#include<stdio.h>

int * arrayfun(int *ptr,int size)
{
    for (int i = 0;i<size-1;i++)
        printf("%d",*ptr++);
    
    return ptr;
}

int main()
{
    int a[] = {1,2,3};
    int size=sizeof(a)/sizeof(a[0]);
    int * ptr = arrayfun(a,size);
    for (int i = 0;i<size;i++)
        printf("%d",*ptr--);
    return 0;
}
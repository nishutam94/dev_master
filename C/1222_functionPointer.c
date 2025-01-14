#include<stdio.h>
int function(int a,int b)
{
    return a+b;
};
int main()
{
    int (*fptr)(int,int);
    fptr=&function;
    printf("%d",fptr(10,20));
    return 0;
}
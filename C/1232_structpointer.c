#include<stdio.h>

struct var 
{
    int a;
    char c;
};

int main()
{
    struct var var1 = {1,'c'};
    struct var *ptr;
    ptr=&var1;
    printf("%d",ptr->a);
}
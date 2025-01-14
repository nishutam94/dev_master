#include<stdio.h>

struct var 
{
    int a;
    char c;
    struct var *next;

};

int main()
{
    struct var var1;
    var1.a = 10;
    var1.c ='c';

    struct var var2;
    var2.a = 10;
    var2.c ='c';

    var2.next = &var1;

}
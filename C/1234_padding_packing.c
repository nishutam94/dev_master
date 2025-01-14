#include<stdio.h>
struct var 
{
    int a;
    char c;
}__attribute((packed))__;

struct var2 
{
    int a;
    char c;
};

struct var5
{
    int a:16;
    char c;
};


int main()
{
struct var var4;
struct var2 var3;
struct var5 var6;
printf("%d",sizeof(var4));
printf("%d",sizeof(var3));
printf("%d",sizeof(var6));
return 0;
}
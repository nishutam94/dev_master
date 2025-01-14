#include<stdio.h>
union var
{
    int i;
    char a;
    short int array[10]; 
};
int main()
{
    union var var1;
    printf("%d",sizeof(var1));
    return 0;
}


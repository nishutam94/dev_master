#include<stdio.h>

int function1()
{
    return 10;
}

int function2(int(*ptr)())
{
    (*ptr)();
}

int main()
{   

    int  (*ptr2)() = &function1;
    function(ptr2);
}
// a callback is the process of passing a function (executable code) to anther function as argument 
// and then it is called by the passed function.

#include<stdio.h>

int function1()
{
int value = 5;
return value;
}

int function2(int (*fun)())
{
int value = 10;
(*fun)();
return value;
}


int main()
{
    int (*fun1)() = &function1;

    function2(fun1);

    return 0;
}
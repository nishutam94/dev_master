#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include <stdarg.h>

int addon(int n, ...)
{
int sum =0 ;
va_list ptr;
va_start(ptr,n);
for (int i=0;i<n;i++)
{
    sum = sum + va_arg(ptr,int);
}
va_end(ptr);

return sum;
}

int additioncbv( int a,int b)
{
int sum;
sum = a + b;
return sum;
}
int additioncbr( int *a,int *b)
{
int sum;
sum = *a + *b;
return sum;
}
int function1()
{   
    auto int function3();
    function3();
    int function3()
    {
        printf("inside function3 \n");
        return 1;
    }
    return 0;
}

int main(void)
{   
    int a = 10;
    int b = 20;
    auto int function2();
    function2();
    printf("call by value : %d\n", additioncbv( a,b));
    printf("call by reference : %d\n", additioncbr(&a,&b));


    int function2()
    {
        printf("inside function2 \n");
        return 1;
    }
    function1();

    printf("call by variadic function : %d\n", addon(4, 1,2,3,4));


    return 0 ;
}


#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdarg.h>
#include<stdlib.h>

#define SOURCE 5 //Macro
#define foo(a, b) a + b


void func1();
void func2();
 
void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();
 
void func1()
{
    printf("Inside func1()\n");
}
 
void func2()
{
    printf("Inside func2()\n");
}
 

int function(int a)
{
    printf("From the funciton : %d \n",a);
    return 0;
}

int main(void)
{   

    printf("Current File :%s\n", __FILE__);
    printf("Current Date :%s\n", __DATE__);
    printf("Current Time :%s\n", __TIME__);
    printf("Line Number :%d\n", __LINE__);
    int a =10;
    int *ptr1=&a;
    printf("%d \n",*ptr1);

    int (*ptr2)(int) = function;
    (*ptr2)(a);

    int value = 100;
    int value2 = 200;

    int const * ptr4 = &value; 
    ptr4=&value2;
    
    int * const ptr5 = &value; 
    //ptr2 = &value2;
    *ptr5 = value2;
    
    int *dagptr = (int*)malloc(sizeof(value2));
    printf("%d \n ",dagptr);
    printf("%p \n ",dagptr);
    free(dagptr);
    printf("%p \n ",dagptr);

    dagptr=NULL;

    return 0 ;
}


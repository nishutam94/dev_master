#include<stdio.h>
#define pi 3.14 // constant using macro #define
enum Vars { var = 3,var2 = 7};
int main()
{
const int a = 10;
printf("%d\n",a);
int c = 20;
int d = 30;
char e = 'a';

//pointer to constant
// you can made a pointer read only. 
//We can change the pointer to point to any other integer variable 
//but cannot change the value of the object (entity) pointed using pointer. 
const int * b = &c; // this mean a can not chnage the value store in it. address can be different.  
printf("%d\n",*b);
b = &d; // valid.
printf("%d\n",*b);
b= &e;
printf("%d\n",*b);
//*b = 100; // not vaild 

// pointer to variable :   int * ptr
// pointer to constant :   const int * ptr or int const * ptr  // cannot change the value, address possible  
// constant pointer to variable : int * const ptr  // can change the value not address. 
// constant pointer to constant : const int * const ptr // none

printf("%d\n",var);






return a;
}
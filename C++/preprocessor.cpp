#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define VALUE1 10
#define fun(a,b) a*b*b



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


int main()
{   
#ifdef VALUE1
    cout<<VALUE1;
#endif
    cout<<fun(5,10);

    cout<<"Last statement";

return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef void (*callbackfunction)();
class base
{
    public:
    void callbyvalue(int x)
    {
        cout<<x<<"\n";
        x=x+1;
        cout<<x<<"\n";
    }

    void callbyref(int *y)
    {
        cout<<*y<<"\n";
        *y=*y+1;
        cout<<*y<<"\n";
    }

    void callbyvstr(string s)
    {
        cout<<s<<"\n";
    }
    void callbyrefstr(const string &s)
    {
        cout<<s<<"\n";
    }
    void callbyptrstr(const string *s)
    {
        cout<<*s<<"\n";
    }

        int add(int a,int b)
    {
        return a+b;
    }
    int mul(int a,int b)
    {
        return a*b;
    }
    int sub(int a,int b)
    {
        return a-b;
    }

    int (base :: *functionptr[3])(int,int) = {add,mul,sub}; // arrey of function pointer

    void static mycallback()
    {
        cout<<"this is call back function \n";
    }

    void PerformAction(callbackfunction callback)
    {
        cout<<"this is performace Action \n";
        callback();
    }
};




int main()
{   
    int x = 10;
    int y = 20;
    base *b1 = new base;
    string str1 = "Hi this is string pointer.";
    string str2 = "Hi this is string reference";
    b1->callbyvalue(x);
    b1->callbyvalue(x);
    b1->callbyref(&y);
    b1->callbyref(&y);
    b1->callbyvstr("Hi this is string");
    b1->callbyrefstr(str2);
    b1->callbyptrstr(&str1);
    b1->PerformAction(base::mycallback);

    cout<<(b1->*b1->functionptr[2])(2,3);

}
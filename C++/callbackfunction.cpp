#include<bits/stdc++.h>
using namespace std;

typedef void (*callbackfunction)();

class base
{
public:
void static mycallback() // Need to make it static as it return the pointer function. 
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

    base *b1 = new base;
    b1->PerformAction(base::mycallback);
}
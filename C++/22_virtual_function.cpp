#include<bits/stdc++.h>
using namespace std;
/*
 A virtual function (also known as virtual methods) is a member function that is declared
 within a base class and is re-defined (overridden) by a derived class. 
 When you refer to a derived class object using a pointer or a reference to the base class,
 you can call a virtual function for that object and execute the derived class’s version of the method.
*/

// If we remove the virtual key word from the below class 
//and use the drive class object it will always go for base 
//class function(even we are using drive calls object).

//pure virtual function 
class base2
{
    virtual void function()=0; // this is pure virtual function
};


class base
{
public:
    int value = 10;//    
    int base_function1()
    {
        cout<<"Base Function1 \n";
        return 1;
    }

    virtual int virtual_function()
    {
        cout<<"Base virtual Function1 \n";
        return 1;
    }
};
class drived : public base
{
public:
    int virtual_function()
    {
        cout<<"Drived virtual Function1 \n";
        return 1;
    }
};

int main() // argument in C++
{
base *base1 = new base;
base1->base_function1();
base1->virtual_function();

base *base2 = new drived;
base2->base_function1();
base2->virtual_function(); 
// this will print the drived class object. (overridding a function.)
// this will work as expected. 
base base3;
base3.base_function1();
base3.virtual_function();

drived drived2;
drived2.base_function1();
drived2.virtual_function();

return 0;
}




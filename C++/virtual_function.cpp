#include<bits/stdc++.h>
using namespace std;
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

return 0;
}




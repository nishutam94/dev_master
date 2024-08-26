#include<bits/stdc++.h>
using namespace std;

void function2()
{

class base
{ 
    public:
    base()
    {
        cout<<"this is base1";
    }

};

class base2
{   
    public:

    base t1;

    void print()
    {
        cout<<"print base2";
    }

};
    base2 t2;
    t2.print();
}

int main()
{
function2();
return 0;
}

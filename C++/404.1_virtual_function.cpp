#include<bits/stdc++.h>
using namespace std;
class base
{
    public:
        virtual void method()
        {
            cout<<"this is base class method";
        }

};

class drived : public base
{
    public:
        void method()
        {
            cout<<"this is drived class method"; 
        }
};

int main()
{

    base * objptr =  new drived();
    objptr->method();


    return 0;
}
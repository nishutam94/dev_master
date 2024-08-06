#include<bits/stdc++.h>
using namespace std;
class base
{
    private:
    int x = 20;
    public:
        void function(int x)
        {

            x=x;
        }
        void thisfunction(int x)
        {
        // The 'this' pointer is used to retrieve the object's x 
        // hidden by the local variable 'x' 
            this->x=x;
        }
        void print()
        {
            cout<<"value of x:"<<x;
        }
        // Chained function calls.  All calls modify the same object 
        // as the same object is returned by reference 
        base& setx(int x)
        {   
            this->x =x; 
            return *this;
        }
        base& sety(int y)
        {   
            this->x =y; 
            return *this;
        }
    

};


int main()
{
base *obj = new base;
obj->function(30);
obj->print();
obj->setx(45).sety(56);
obj->print();

return 0;
}
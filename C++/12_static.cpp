#include<bits/stdc++.h>
using namespace std;
class base
{
    private:

    static int a;
    public:
        void seta(int a)
        {
            this->a = a;
        }
        void setar(int a)
        {
            base::a = a;  // here we are using the resolution operator (only for static data members )
        }
        void print()
        {
            cout<<"value of a:"<<a;
        }
};

int base :: a = 10; // you can not define an static member into base class. 

int main()
{
    base obj;
    obj.seta(20);
    obj.print();
    obj.setar(40);
    obj.print();
   
    return 0;

}


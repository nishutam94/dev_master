#include<bits/stdc++.h>
using namespace std;

namespace space1
{   
    class base
    {
        public:
        void show();
    };


    void fun()
    {
        cout<<"inside space1";
    }
}

void space1::base::show()
{
    cout<<"It is a show function";
}

namespace space2
{
    void fun()
    {
        cout<<"inside space2";
    }
}
//using namespace space2;
int main()
{
    space2::fun();
    space1::fun();
    space1::base obj1;
    obj1.show();
    return 0;
}

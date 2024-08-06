#include<bits/stdc++.h>
using namespace std;
class base
{

    private:
    int a = 10;
    public:
    class nested
    {
        public:
        void print(base & b1)
        {
            cout<<b1.a;
        }
    };


};

int main()
{
    base b2;
    base::nested n2;
    n2.print(b2);

    
}


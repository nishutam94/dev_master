#include<bits/stdc++.h>
using namespace std;
class error
{
    public:
    error()
    {
        cout<<"This is error";
    }
    ~error()
    {
        
    }
};

int main()
{       
    int c=100;

    try
    { 

        if (c == 10)
            cout<<"yes";
        else
            throw error();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(int c)
    {
        std::cerr << c << '\n';
    }
    catch(error obj)
    {
        std::cerr << "out"<< '\n';
    }

    try 
    {
        if (c ==  100)
        {
            throw "this exceprion";
        }
    }
    catch(const char *str)
    {
        cerr<<"exception"<< str;
    }


}
#include<bits/stdc++.h>
using namespace std;
/*
A template is a simple yet very powerful tool in C++. 
The simple idea is to pass the data type as a parameter so that we don’t 
need to write the same code for different data types.
*/
template <class T2>
T2 max_min(T2 a, T2 b)
{
    if (a < b)
        return a;
    else
        return b;
}


class template_class
{

    public:
    template <typename T>


    T max(T x)
    {
        return x;
    }  
    
};



int main()
{

    template_class tc;

    tc.max(5);
    tc.max('h');
    tc.max(5.5);
    cout<<max_min(3.2, 5.5);
    cout<<max_min(3, 5);
    cout<<max_min('d', 'a');
    return 0;
}
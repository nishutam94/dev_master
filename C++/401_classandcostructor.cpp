#include<bits/stdc++.h>
using namespace std;

class base
{   

    public: //scope is public, open to all
        int x = 10;
        base() // this is default constructor 
        {
            cout<<"This is default constructor.\t \n";
        }
        ~base() // this is default constructor 
        {
            cout<<"This is destructor.\t \n";
        }
        base(int x) // This is Parameterized constructor 
        {
            cout<<"This is Parameterized constructor.\t"<<x<<"\n";
        }
        void base_member_fucntion();
        void base_function()
        {   
            cout<<"Defining the base function inside the base class\n";
        }

}object(30); 
// creating object like structure this is also valid now. 
// Also supplying the parameter

void base :: base_member_fucntion()
{
    cout<<"Defining the Member function outside the base class\n";
}

class drived : public base // inharitance
{
    public:
    void drived_function()
    {
        cout<<"Defining the drived function inside the drived class\n";        
    }

};


int main()
{
// ways to declear object    
base base1; 
// this called the deafult constructor;
base *base2 = new base;
//calling the functions through objects 
base1.base_function();
base2->base_function();
base2->base_member_fucntion();


drived drive1 ;
drived *drive2 = new drived;
// Acceing the base class function using drived class object.inheritence. (function overriffing.)
drive1.base_member_fucntion(); 
return 0;
}
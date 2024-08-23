#include<bits/stdc++.h>
using namespace std;

class base
{   
    private:
        //Scope is within the class only, Only member function or 
        //friend function can access the variable.
        int private_var = 10;
        static int private_static_var;

    protected: 
        // very similer to private class,Only member function 
        // or friend function or derived class members can 
        // access the variable.
        int id_protected; 

    public: //scope is public, open to all
        int x = 10;

        void base_function()
        {   
            cout<<"Defining the base function inside the base class\n";
            cout<<"Private Var:\t"<<private_var<<"\n";
            private_static_var+=1;
            cout<<"Private Static Var:\t"<<private_static_var<<"\n";
            cout<<"Protected Var:\t"<<id_protected<<"\n";
        }

        friend class friend_class;
        friend void friend_function(base& obj);

};


void friend_function(base& b1)
{
        cout<<"Defining the friend function outside the base class\n";        
        cout<<"Accessing public Var from friend class:\t"<<b1.x<<"\n"; 
        cout<<"Private Sattic Var:\t"<<b1.private_static_var<<"\n";
        cout<<"Protected Var:\t"<<b1.id_protected<<"\n";  
}

int base ::  private_static_var = 10; //defining the memmber variable outside. 


class drived : public base
{
    public:
    void drived_function()
    {
        cout<<"Defining the drived function inside the drived class\n";        
        cout<<"public Var:\t"<<x<<"\n"; 
        //cout<<"Private Static Var:\t"<<private_static_var<<"\n"; Cant access the private variables from base class
        cout<<"Protected Var:\t"<<id_protected<<"\n"; 
    }
};
/*A friend class or function can access private and protected members of 
other classes in which it is declared as a friend. */

class friend_class 
{
    public: //scope is public, open to all
        void friendclassbase_function(base& b1)
        {   
        cout<<"Defining the function inside the friend class\n";        
        cout<<"Accessing public Var from friend class:\t"<<b1.x<<"\n"; 
        cout<<"Private Sattic Var:\t"<<b1.private_static_var<<"\n";
        cout<<"Protected Var:\t"<<b1.id_protected<<"\n"; 
        }

};


int main()
{
 
base *base2 = new base;
base2->base_function();

drived *drived2 = new drived;
drived2->drived_function();

friend_class *fc1 = new friend_class;
fc1->friendclassbase_function(*base2); // accesing the base class private and protected members in friend class.

friend_function(*base2);
return 0;
}
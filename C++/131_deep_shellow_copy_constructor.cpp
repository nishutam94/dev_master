#include<bits/stdc++.h>
using namespace std;
class base
{
    static int y;
    public:
        int x = 10;
        base(); // default constructor
        //base(base& obj); //  copy constructor  
        void base_function()
        {            
            cout<<"base function() \n";
            x=x+1;
            cout<<"shellow Copy : "<<x<<"\n";
            //In shallow copy, an object is created by 
            //simply copying the data of all variables 
            //of the original object.
            //In shallow copy, the two objects are not independent.

        }       
};

base::base()
{    
    cout<<"default constructor" ;
    // A constructor without any arguments or 
    // with the default value for every argument 
    // is said to be the Default constructor.     
}

/*base::base(base& obj) 
{    
    cout<<"user defined copy constructor";
    // A constructor without any arguments or 
    // with the default value for every argument is said 
    //to be the Default constructor.     
}*/


int main()
{
    base b1; // default constructor 
    b1.base_function();
    base b2(b1); // this is deep copy. copy constructor.
                 // Passing the another object to object.
    b2.base_function(); 

    base b2 = b1; //shellow copy

}
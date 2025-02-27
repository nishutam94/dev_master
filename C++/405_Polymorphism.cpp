#include<bits/stdc++.h>
using namespace std;
/*
1. function overloading did not works with const and static funciotions.
2. function overloading did not works with different return type function.
*/
class function_overlaod
{
    public:
    void print(int x)
    {
        cout<<x;
    }
    void print(double x)
    {
        cout<<x;
    }
    void print(char x)
    {
        cout<<x;
    }    
};
/*Operator overloading” is to use C++ operators with class variables or class objects. 
Redefining the meaning of operators really does not change their original meaning; 
instead, they have been given additional meaning along with their existing ones.

--> if the user wants to make the operator “+” add two class objects, 
the user has to redefine the meaning of the “+” operator such that it adds two class objects. 
This is done by using the concept of “Operator overloading”.*/
class operator_overloading
{
    private:
        int real;
        int image;

    public:
        operator_overloading(int x,int y)
        {
            real = x;
            image = y; 
        }
        operator_overloading operator+(operator_overloading & obj)
        {
            operator_overloading res(0,0);
            res.real  =  real  + obj.real;
            res.image =  image + obj.image;
            return res;
        }
        void print()
        {
            cout<<real<<"+i"<<image<<endl;
        }
};

class functors
{
    private:
        int x;
    public:
        functors(int x)
        {
            this->x = x;
        }

        int operator () (int add)
        {
            return this->x+ add;
        } 
};

int main()
{
function_overlaod fo;
fo.print(4);
fo.print(4.2);
fo.print('c');

operator_overloading oo1(10,5);
operator_overloading oo2(12,7);
operator_overloading oo3 = oo1 + oo2;
oo3.print();

int arr[5] = {10,3,4,2,5};
transform(arr,arr+5,arr,functors(10));
for (int i =0;i<5;i++)
{
    cout<<arr[i];
}

}






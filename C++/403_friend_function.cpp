#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;


// with the help of friend class and friend function we can 
// accessprivate and protected the member of other class. 


class Geeks 
{   
    private:
    std::string private_variable="default";
    public:
    Geeks()
    {
        std::cout << "constructor\n";
    }
    std::string GeeksName;
    void printname()
    {
        std::cout<<"inside the function "<<GeeksName<<"\n";
    }
    void printnameoutsideclass();
    friend class frindclass;
};
class frindclass
{
    public:
    void friendclassfun(Geeks& value)
    {
        std::cout<< "This is Friend class function";
        value.private_variable="New_value";
        std::cout<< "value of private variable from class Geeks: "<<value.private_variable<<"\n";
    }
};
void Geeks :: printnameoutsideclass()
{
    std::cout<<"outside the class print function "<<GeeksName<<"\n"; 
}
int main(void)
{   
    Geeks G1;
    G1.GeeksName="Abhi";
    G1.printname();
    G1.printnameoutsideclass();
    frindclass Fc1;
    Fc1.friendclassfun(G1);
    return 0;
}

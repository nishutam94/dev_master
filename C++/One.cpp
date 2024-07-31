#include<iostream>
#include<stdio.h>
#include<fstream>

struct syst;
struct syst
{
};

template <typename T> 

T mymax(T x, T y)
{
    return (x>y)?x:y;
}

class base
{   public:
    virtual void function()
    {
        std::cout<<"this is base function call\n";
    }
    void function2()
    {
        std::cout<<"this is base function2 call\n";
    }
};
class drived:public base
{   
    public:
    void function()
    {
        std::cout<<"this is drived function call\n";
    }
    void function2()
    {
        std::cout<<"this is drived function2 call\n";
    }
};
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
    using namespace std;
    cout << "Hello,world\n";
    printf("%s","hello,World\n");
    Geeks G1;
    G1.GeeksName="Abhi";
    G1.printname();
    G1.printnameoutsideclass();
    frindclass Fc1;
    Fc1.friendclassfun(G1);
    base * baseptr1 = new base();
    baseptr1->function();
    baseptr1->function2();
    base * baseptr2 = new drived();//base calss pointer is accesing the 
    baseptr2->function();
    baseptr2->function2();
    
    
    string line;
    fstream fout;
    fout.open("sample.txt");
    if (!fout.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    while (fout)
    {
        getline(cin,line);
        if (line == "-1")
        {
            break;
        }
        fout << line << endl;
    }
    fout.close();

    ifstream fin;
    fin.open("sample.txt");

    while (getline(fin, line)) 
    {
        cout << line << endl;
    }
 
    fin.close();

    cout << mymax<int>(3,4)<<endl;
    return 0;
}

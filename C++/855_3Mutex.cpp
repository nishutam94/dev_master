#include<vector>
#include<thread>
#include<mutex>
#include <iostream>
using namespace std;

mutex mtxA;
mutex mtxB;
mutex mtxC;



void funA()
{
    while(true)
    {    
        mtxA.lock();
        cout<<"A ->"<<"\n";
        mtxB.unlock();
    }
}
void funB()
{
    while(true)
    {   mtxB.lock(); 
        cout<<"B ->"<<"\n";
        mtxC.unlock(); 
    }
}
void funC()
{
    while(true)
    {   mtxC.lock(); 
        cout<<"C ->"<<"\n";
        mtxA.unlock(); 
    }
}



int main()
{
    mtxB.lock();
    mtxC.lock();
    
    thread t1 = thread(funA);
    thread t2 = thread(funB);
    thread t3 = thread(funC);

    t1.join();
    t2.join();

    return 0;
}

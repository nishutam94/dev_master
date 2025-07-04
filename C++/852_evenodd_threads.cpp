#include<vector>
#include<thread>
#include<mutex>
#include <iostream>
using namespace std;

mutex mtx;
int turn = 0;

void odd()
{

for(int i=0; i<100000000; i++)
{   
    if(i%2==0)
    {
        lock_guard<mutex> lock(mtx);
        cout<<"odd -> "<<i<<"\n";
    }

}

}

void even()
{
    for(int i=0;i<100000000;i++)
    {
    if(i%2!=0)
    {
        lock_guard<mutex> lock(mtx);
        cout<<"even -> "<<i<<"\n";
    }
    
    }
}

int main()
{

    thread t1 = thread(odd);
    thread t2 = thread(even);

    t1.join();
    t2.join();

    return 0;
}

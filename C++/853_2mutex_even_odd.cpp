#include<vector>
#include<thread>
#include<mutex>
#include <iostream>
using namespace std;

mutex mtx;
int turn = 0;

void odd()
{

while(true)
{   
    if(turn%2==0)
    {
        mtx.lock();
        cout<<"odd -> "<<turn<<"\n";
        turn++;
        mtx.unlock();
    }

}

}

void even()
{
    while(true)
    {
    if(turn%2!=0)
    {
        mtx.lock();
        cout<<"even -> "<<turn<<"\n";
        turn++;
        mtx.unlock();
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

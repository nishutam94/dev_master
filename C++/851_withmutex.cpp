#include<thread>
#include<vector>
#include<iostream>
#include<mutex>
#define N 10

using namespace std;
vector<bool> flag(N,false);
mutex A ;
mutex B ;

void cs(int id)
{
    A.lock();
    B.lock();
    cout<<id<<"\n";
    A.unlock();
    B.unlock();
   
}


int main()
{
    thread threads[N];
    for(int i=0;i<N;i++)
    {
        threads[i]=thread(cs,i);
    }

    for(int i=0;i<N;i++)
    {
        threads[i].join();
    }

    return 0;
}
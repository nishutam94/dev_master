#include<iostream>
#include<vector>
#include<semaphore>
#include<condition_variable>
#include<thread>
#include<mutex>
#define N 10
using namespace std;

mutex mtx;
condition_variable cvfull;
condition_variable cvempty;
int count;

void producer(int id)
{
    unique_lock<mutex> lock(mtx);
    cvfull.wait(lock,[](){return count < N;});//while count == N
    count++;
    cout<<"\nproducer with"<<id<<" count"<<count;
    cvempty.notify_one();
    lock.unlock();
    
}
void consumers(int id)
{
    unique_lock<mutex> lock(mtx);
    cvempty.wait(lock,[](){return count > 0;});//while count < 0;
    count--;
    cout<<"\nconsumer with"<<id<<" count"<<count;
    cvfull.notify_one();
    lock.unlock();

}



int main()
{
    thread rthread[N];
    thread wthread[N];

    for(int i=0;i<N;i++)
    {
        rthread[i]=thread(producer,i);
        wthread[i]=thread(consumers,i*2);
    }
    for(int i=0;i<N;i++)
    {
        rthread[i].join();
        wthread[i].join();
    }
    return 0;
}

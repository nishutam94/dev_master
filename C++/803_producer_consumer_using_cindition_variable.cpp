#include<iostream>
#include<mutex>
#include<condition_variable>
#include<semaphore>
#include<thread>

using namespace std;
const int n = 10;
int buffer[n];
int in =0;
int out = 0;
int count = 0;

mutex mtx;
condition_variable full;
condition_variable cvempty;

void producer(int id)
{
   while(true)
   {
    unique_lock<mutex> lock(mtx);
    full.wait(lock,[]() { return count < n;});
    buffer[in] = id;
    in = (in+1)%n;
    cout<<"produced "<<id<<"\n";
    count = count+1;
    cvempty.notify_one();
   }

}

void consumer(int id)
{
   while(true)
   {
    unique_lock<mutex> lock(mtx);
    cvempty.wait(lock,[]() { return count > 0;});
    int val =buffer[out];
    out = (out+1)%n;
    cout<<"consumed "<<val<<"\n";
    count = count-1;
    full.notify_one();
    
   }
}

int main()
{
thread t1(producer,1);
thread t2(consumer,2);

t1.join();
t2.join();
return 0;
}

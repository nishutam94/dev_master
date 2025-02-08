#include<iostream>
#include<fstream>
#include<mutex>
#include<condition_variable>
#include<thread>
using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void notify()
{
    lock_guard<mutex> lock(mtx);
    ready = true;
    cv.notify_all();
}
void thread_function(int id)
{
    unique_lock<mutex> lock(mtx,defer_lock);
    lock.lock();
    while(!ready)
    {
        cv.wait(lock);
    }
    cout<<"this is thread"<<id<<"\n";
    lock.unlock();
}

int main()
{
    thread threads[10];

    for(int i =0;i<10;i++)
    {
         threads[i]=thread(thread_function,i);
    }
    this_thread::sleep_for(chrono::seconds(2));
    notify();
    for(int i=0;i<10;i++)
    {
        threads[i].join();
    }

    return 0;
}
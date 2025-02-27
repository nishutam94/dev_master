#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<condition_variable>
#define N 10

using namespace std;

mutex mtx;
mutex db;
condition_variable var;
int r = 0;
int w = 0;



void reader(int id)
{   
    while(true)
    {
        
        mtx.lock();
        r++;
        if (r==1)
            db.lock();
        mtx.unlock();

        cout<<"Readers "<<r<<" writer :"<<w<<id<<"\n";
    
        mtx.lock();
        r=r-1;
        if (r==0)
            db.unlock();
        mtx.unlock();

        break;

    }
}

void writer(int id)
{   
    while(true)
    {
        unique_lock<mutex> lock(mtx);
        w++;
        if (w == 1)
            var.wait(lock,[](){return r == 0;});
        db.lock();
        cout<<"Readers "<<r<<" writer :"<<w<<id<<"\n";
        db.unlock();
        w--;
        if(w==0)
            var.notify_all();

        break;
    }
}

int main()
{
thread rthread[N];
thread wthread[N];

for(int i=0;i<N;i++)
{
    rthread[i]=thread(reader,i);
    wthread[i]=thread(writer,i*2);
}
for(int i=0;i<N;i++)
{
    rthread[i].join();
    wthread[i].join();
}

return 0;
}
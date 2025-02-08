#include<iostream>
#include<vector>
#include<semaphore>
#include<thread>
//#include<counting_semaphore>
#define N 100

using namespace std;
int count = 0;

//counting_semaphore<N> sfull(0);
//counting_semaphore<N> sempty(N);
//binary_semaphore bin(1);
int trun=0;

void producer(int id)
{
    while(true)
    {
    while(count == N);
    while(turn == 1);
    cout<<"its producing "<<id <<"\n";
    count=count+1;
    turn = 0;
    }
}

void consumer(int id)
{
    while(true)
    {
    while(true)
    {
    while(count == 0);
    while(turn == 0);
    cout<<"its producing "<<id <<"\n";
    count=count+1;
    turn = 1;
    }

    }
    
}

int main()
{
   
    thread pthreads[N];
    thread cthreads[N];

    for(int i=0;i<N;i++)
    {
        pthreads[i]=thread(producer,i);
    }
    for(int i=0;i<N;i++)
    {
        cthreads[i]=thread(consumer,i);
    }

    for(int i=0;i<N;i++)
    {
        pthreads[i].join();
        cthreads[i].join();
    }


}


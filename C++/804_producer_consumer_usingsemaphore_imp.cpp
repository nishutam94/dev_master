#include<iostream>
#include<vector>
#include<semaphore>
#include<thread>
//#include<counting_semaphore>
#define N 100

using namespace std;

counting_semaphore<N> sfull(0);
counting_semaphore<N> sempty(N);
binary_semaphore bin(1);


void producer(int id)
{
    while(true)
    {
    sempty.acquire();
    bin.acquire();
    cout<<"its producing "<<id <<"\n";
    bin.release();
    sfull.release();
    break;

    }
}

void consumer(int id)
{
    while(true)
    {
    sfull.acquire();
    bin.acquire();
    cout<<"its consuming ---- "<<id <<"\n";
    bin.release();
    sempty.release();
    break;

    }
    
}

int main()
{
   
    thread pthreads[N];
    thread cthreads[N];

    for(int i=0;i<N;i++)
    {
        pthreads[i]=thread(producer,i);
        cthreads[i]=thread(consumer,i);
    }


    for(int i=0;i<N;i++)
    {
        pthreads[i].join();
        cthreads[i].join();
    }


}


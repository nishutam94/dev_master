#include<iostream>
#include<fstream>
#include<semaphore>
#include<vector>
#include<thread>

using namespace std;

binary_semaphore semaphore(1);
void writetofile(int threadid)
{
    semaphore.acquire();
    ofstream file("output3.txt",ios::app);

    if (file.is_open())
    {
        file<<threadid;   
    }
    file.close();
    semaphore.release();
}

int main()
{   
    thread threads[10];
    for(int i =0;i<10;i++)
    {
        threads[i]=thread(writetofile,i);
    }

    for(int i =0;i<10;i++)
    {
        threads[i].join();
    }


}
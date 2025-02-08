#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<fstream>
using namespace std;

mutex file_mutex;
void writetofile(int threadId)
{
lock_guard<mutex> lock(file_mutex);
ofstream file("output.txt",ios::app);
if (file.is_open())
{
    file<<threadId;
    file.close();
}
else
{
    cout<<"error open a file";
}

}

int main()
{
    thread threads[10];

    for(int i=0;i<10;i++)
    {
        threads[i] = thread(writetofile,i+1);
    }

    for(int i=0;i<10;i++)
    {
        threads[i].join();
    }
    
    
    return 0;
}
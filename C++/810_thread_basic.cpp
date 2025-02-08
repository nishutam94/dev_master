#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;
mutex mtx;

void write(int id)
{
    lock_guard<mutex> lock(mtx);
    cout << "threadID: " << id << "\n";
}

int main()
{
    int n = 10;
    thread threads[n];
    
    for (int i = 0; i < n; i++)
        threads[i]=thread(write, i);
    
    for (int i = 0; i < n; i++)
        threads[i].join();
    
    return 0;
}
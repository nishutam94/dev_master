#include<iostream>
#include<thread>
#include<vector>
#define N 10
using namespace std;

vector<bool> flag(10,false);
int turn = 0;

void cs(int id)
{
    cout<<"this is cs with id :"<<id<<"\n";
}

void function(int id)
{
    while(true)
    {
    int other = (id+1)%N;
    flag[id] = true;
    turn = other ;

    while (turn == other && flag[other]);
    cs(id);
    flag[id] = false;
    break;
    }
}

int main()
{
    int n = 10;

    thread threads[N];
    for (int i =0;i<N;i++)
    {
        threads[i] = thread(function,i);
    }
    for (int i =0;i<N;i++)
    {
        threads[i].join();
    }
    return 0;
}
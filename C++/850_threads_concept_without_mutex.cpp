#include<thread>
#include<vector>
#include<iostream>
#define N 10

using namespace std;
vector<bool> flag(N,false);
int turn = 0;

void cs(int id)
{
    cout<<id<<"\n";
}

void shared(int id)
{     
    while(true)
    {
        int other = (id+1)/N;
        turn = other;
        flag[id] = true;
        while(flag[other] == true && other == turn);
        cs(id);
        flag[id] = false;
        break;
    }
}

int main()
{
    thread threads[N];
    for(int i=0;i<N;i++)
    {
        threads[i]=thread(shared,i);
    }

    for(int i=0;i<N;i++)
    {
        threads[i].join();
    }

    return 0;
}
#include<iostream>
#include<thread>
using namespace std;

bool flag[2] ={false,false};
int turn = 0;
int other = 0;


void cs(int id )
{
    cout<<"id :"<<id<<"\n";
}

void peterson(int id)
{
    int other = 1 - id;
    while (true)
    {
    flag[id] = true;
    turn = other;
    while(flag[other] && turn == other);
    cs(id);
    flag[id] = false;
    }
}

int main()
{
    thread t1(peterson,0);
    thread t2(peterson,1);


    t1.join();
    t2.join();
}



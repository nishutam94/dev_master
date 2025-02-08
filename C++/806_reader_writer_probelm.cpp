#include<iostream>
#include<vector>
#include<thread>
#define N 10

void reader()
{

}

void writer()
{

}

int main()
{
thread rthread[N];
thread wthread[N];

for(int i=0;i<N;i++)
{
    rthread[i]=thread(reader,i);
    wthread[i]=thread(writer,i);
}
for(int i=0;i<N;i++)
{
    rthread[i].join();
    wthread[i].join();
}

return 0;
}
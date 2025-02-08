#include<semaphore>
#include<iostream>
using namespace std;

void function()
{
    cout<<"fucntion exicuted.";
}

int main()
{
    sem_t sem;
    sem_init(&sem,0,1);
    sem_wait(&sem);
    sem_post(&sem);
    return 0;
}
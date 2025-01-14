#include<stdio.h>

//how to pass arguments to c main program.
int main(int argc,char* argv[])
{

    for (int i ;i <argc;i++)
        printf("%s\n",argv[i]);

    return 0;
}
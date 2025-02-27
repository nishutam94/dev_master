#include<stdio.h>

int main()
{
    int a[10][10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            a[i][j]=0;
        }
    }


    int *ptr = (int*)malloc(sizeof(int)*10);
    int **ptr = (int**)malloc(sizeof(int*)*10);




    return 0;
}
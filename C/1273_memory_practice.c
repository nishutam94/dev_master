#include<stdio.h>
int main()
{
    int* arr = (int *)malloc(10*sizeof(int));
    
    
    int m =10;
    int n=10;
    int** arr2 = (int **)malloc(sizeof(int*)*m*n);
    for(int i=0;i<m;i++)
    {
        arr2[i]=(int *)malloc(n*sizeof(int));
    }


    return 0;
}
#include<stdio.h>
int main()
{   
    int m =3;
    int n = 4;

    int ** ptr = (int **)malloc(sizeof(int*)*m*n);
    for (int i =0;i<m;i++)
    {
        ptr[i]=(int *)malloc(sizeof(int)*n);
    }

    int value = 100;
    for (int i =0;i<m;i++)
    {
        for (int j =0;j<n;j++)
        {
            ptr[i][j]=value++;
        }       
    }
    for (int i =0;i<m;i++)
    {
        for (int j =0;j<n;j++)
        {
            printf(" %d ",ptr[i][j]);
        }       
        printf("\n");
    }
    printf("%u",sizeof(*ptr));



    free(ptr);

    return 0;
}
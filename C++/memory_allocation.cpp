//this code is basically for malloc,calloc,realloc,new,free

#include<bits/stdc++.h>
using namespace std;
class base
{  
    public:
    void malloc_fuction1()
    {
        int *ptr_var;
        ptr_var=(int*)malloc(10*sizeof(int)); // allocate memory for integer
        for (int i = 0;i<10;i++)
        {
            cout<<ptr_var[i]<<" "; // returns 0
        }

        if (ptr_var == NULL)
            cout<<"Not allocated \n";
        else
            cout<<" ------- integer ptr ------ \n";

        free(ptr_var); // if free is not done then there is memory leak.

        int n = 10;
        int *ptr_arr;
        ptr_arr=(int*)malloc(n*sizeof(int)); // allocate memory for integer array of size n
        
        for (int i = 0;i<n;i++)
        {
            ptr_arr[i] = i;
        }
        cout<<" ------- 1D array -------- \n";
        for (int i = 0;i<n;i++)
        {
            cout<<ptr_arr[i]<<" ";
        }
        cout<<"\n";
        free(ptr_arr);

        int m = 4;
        n = 3;
        int **ptr_arr2d;
        ptr_arr2d=(int**)malloc(n*sizeof(int*)); // allocate memory for integer array of size n
        
        for (int i = 0;i<n;i++)
        {
            ptr_arr2d[i] = (int*)malloc(m*sizeof(int));
        }
        cout<<" ------- 2D array -------- \n";
        for (int i = 0;i<n;i++)
        {
            for (int j = 0;j<m;j++)
            {
                ptr_arr2d[i][j]=i+j;
            }
        
        }
        for (int i = 0;i<n;i++)
        {
            for (int j = 0;j<m;j++)
            {
                cout<<ptr_arr2d[i][j]<< " ";
            }
            cout<<"\n";   
        }
        cout<<"\n";
        free(ptr_arr2d);
    }
    void calloc_function1()
    {
        int *ptr_var;
        ptr_var = (int *)calloc(10,sizeof(int));
        for (int i = 0;i<10;i++)
        {
            cout<<ptr_var[i]<<" ";
        }
        cout<<"\n";
        free(ptr_var);
    }
    void realloc_function1()
    {
        int *ptr_var;
        ptr_var = (int *)malloc(10*sizeof(int));
        for (int i = 0;i<10;i++)
        {
            cout<<ptr_var[i]<<" ";//returns 0
        }
        cout<<"\n";
        ptr_var = (int *)realloc(ptr_var,20*sizeof(int)); // for existing pointer you can assigne the new memory to it using realloc
        for (int i = 0;i<40;i++)
        {
            cout<<ptr_var[i]<<" ";//returns 0
        }
        free(ptr_var);
        cout<<"\n";
    }
    void new_function1()
    {
        int *ptr_var = new int(25);
        delete ptr_var;

        int *ptr_var2 = new int[20];
        *ptr_var2 = 10;
        *(ptr_var2+1) = 20;
        delete ptr_var2;

        cout<<"\n 1D- array using new \n";
        int *ptr_arr = new int[10];
        for (int i = 0;i<10;i++)
        {   ptr_arr[i]=i;
            cout<<ptr_arr[i]<<" ";
        }
        delete[] ptr_arr ;
       


        cout<<"\n 2D- array using new \n";
        int **ptr_arr2 = new int*[10];

        for (int i = 0;i<10;i++)
        {
            ptr_arr2[i] = new int[10];
        }

        for (int i = 0;i<10;i++)
        {
            for (int j = 0;j<10;j++)
            {
                //ptr_arr2[i][j] = 10*i + j;
                cout<<ptr_arr2[i][j]<<" ";
            }
            cout<<"\n";
        }

        for (int i = 0;i<10;i++)
        {
            delete[] ptr_arr2[i];
        }
        delete[] ptr_arr2;
        cout<<"\n";      
    }

};
class drived : public base
{

};

int main()
{
    base base1;
    base1.malloc_fuction1();
    base1.calloc_function1();
    base1.realloc_function1();

    base *base2 = new base;
    base2->realloc_function1();
    base2->new_function1();

    return 0;
}
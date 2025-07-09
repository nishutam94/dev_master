#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int reverse_bit(int n)
{
    int rev = 0;
    int temp = n;
    int b=0;
    while(temp)
    {   
        b++;
        temp=temp>>1;
    }        
    for(int i=0;i<32;i++)
    {
        rev = rev << 1;
        if (n & 1)
            rev = rev | 1;        
        n =  n >> 1;
    }
    return rev;
}


int find_duplicate_number_in_array(int a[],int n)
{   int answer = 0;

    for(int i=0;i<n;i++)
    {
        answer = answer ^ a[i];
    }

    for(int i=1;i<n;i++)
    {
        answer = answer ^ i;
    }

    return answer;
}



int set_right_most_unset_bit(int n)
{   
    for(int i=32;i>0;i--)
    {   
        if((n & 1<<i) == 0)
        {
            break;
        }
        n=n | 1;
    }
    return n;
}

int check_kth_bit_status(int n,int k)
{
    if(n&1<<k)
        return 1;
    return 0;
}

int count_no_of_ones(int n)
{   int count = 0;
    for(int i=32; i>0; i--)
    {
        if(n&1<<i)
            count++;
    }
    return count;
}

int main()
{   
    int a[] = {1,2,3,4,4};
    int n = 5;

    cout<<count_no_of_ones(7);
    cout<<check_kth_bit_status(8,2);
    cout<<find_duplicate_number_in_array(a,n);
    return 0;
}
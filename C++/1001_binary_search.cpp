#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int target,int n )
{   
   
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int mid = (i+j)/2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid]<target)
        {
            i=mid+1;
        }
        else
        {
            j=mid-1;
        }
    }
    return -1;


}


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binary_search(arr,8,n);


    return 0;
}
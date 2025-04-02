#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int target,int l,int h)
{   
   int mid = (l+h)/2;
   if (arr[mid]==target)
    return mid;

    if (arr[mid]<target)
        return binary_search(arr,target,mid+1,h);
    return binary_search(arr,target,l,mid-1);

    return -1;
}


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binary_search(arr,8,0,n-1);


    return 0;
}
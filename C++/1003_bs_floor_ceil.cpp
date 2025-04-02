#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int target,int n )
{   
   
    int i=0;
    int j=n;
    int ceil=-1;
    int floor=-1;
    while(i<=j)
    {
        int mid = (i+j)/2;

        if (arr[mid] <= target)
        {   
            floor=mid;
            i=mid+1;
        }
        else
        {
            ceil=mid;
            j=mid-1;
        }
    }
    return ceil;


}


int main()
{
    int arr[7] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binary_search(arr,8,n);


    return 0;
}
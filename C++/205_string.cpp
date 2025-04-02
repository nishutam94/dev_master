#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "geeksforgeeks";
    int n =  str.size();
    for(int i=0;i<n;i++)
    {
        cout<<str.substr(0,i)<<" "<<str.substr(i)<<"\n";
    }

    return 0;
}
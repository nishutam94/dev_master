#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> arr = {10,23,45,54,19,100,90,30,23};

    if (find(arr.begin(),arr.end(),23)!=arr.end())
        cout<<"its presnt";
    else
        cout<<"not present";


    unordered_set<string> sset ={"this","is","my","new","code","this","hello"}; 

    string stringtofind= "hellogeeks";
    for(int i=0;i<sset.size();i++)
    {
        if (find(sset.begin(),sset.end(),stringtofind.substr(0,5))!=sset.end())
            cout<<"its presnt";
        else
            cout<<"not present";
    }


    return 0;
}
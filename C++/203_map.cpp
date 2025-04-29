#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

void map_function(vector<char> &arr)
{
    unordered_map<char,int> map;

    for(int i=0;i<arr.size();i++)
    {
        map[arr[i]]+=1;
    }

    cout<<map['A'];
    cout<<map.size();
    for(auto i=map.begin();i!=map.end();i++)
    {
        cout<<i->first<<i->second;
    }

    for(int i=0;i<map.size();i++)
    {
        cout<<map[i];
    }
}

int main()
{
    vector<char> arr;
    for(char i='a';i<'z';i++)
    {
        arr.push_back(i);
    }
    
    map_function(arr);
}
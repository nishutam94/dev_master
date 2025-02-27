#include<bits/stdc++.h>
using namespace std;
int main()
{
priority_queue<int,vector<int>,greater<int>> minheap;
minheap.push(10);


while(minheap.size()<5)
{
minheap.push(minheap.top()+1);
}

while(minheap.size()>1)
{
cout<<minheap.top();
minheap.pop();
}
return 0;
}
#include<string>
#include<iostream>
#include<sstream>

using namespace std;
int main()
{
    string s = "this is the string where worlds need to be count";
    string word;
    int count=1;
    for(int i;i<s.size();i++)
    {
        if (s[i]==' ')
            count=count+1;
    }
    cout<<"\n"<<count;
    istringstream stream(string);
    while(stream >> word)
    {
        cout<<word;
    }

    return 0;
}
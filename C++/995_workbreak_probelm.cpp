#include <bits/stdc++.h>
using namespace std;

bool wordbreaksolve(vector<string>& dictionary, string target)
{
   
    if (target.size() == 0)
        return true;


    for (int i = 1; i <= target.size(); i++) 
    {
        if (find(dictionary.begin(), dictionary.end(), target.substr(0, i)) != dictionary.end()) 
        {
            if (wordbreaksolve(dictionary, target.substr(i)))
                return true;
        }
    }

    return false;
}

int main()
{
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string word = "ilike";
    cout<<wordbreaksolve(dictionary, word); 

    return 0;
}

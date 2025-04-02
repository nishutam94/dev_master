#include <bits/stdc++.h>
using namespace std;

bool wordbreaksolve(vector<string>& dictionary, string target,vector<int> &dp)
{
   
    int n = target.size();
    dp[0]=1;
    
    for (int i = 1; i <= n; i++) 
    {
        for(int j=0;j<i;j++)
        {
            if (find(dictionary.begin(), dictionary.end(), target.substr(j,i-j)) != dictionary.end()) 
            {
                if (dp[j]==1)
                {
                    dp[i]=1;
                    break;
                }

            }
        }

    }

    return dp[n];
}

int main()
{
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string word = "ilike";
    int n = word.size();
    vector<int> dp(n+1,0);
    cout<<wordbreaksolve(dictionary, word,dp); 

    return 0;
}

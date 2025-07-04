#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) 
{
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> pv = {{2, 3}, {7, 8}, {9, 4}};

    sort(pv.begin(), pv.end(), compare);


    for (const auto& p : pv) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}

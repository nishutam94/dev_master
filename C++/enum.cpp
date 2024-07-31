#include<bits/stdc++.h>
using namespace std;

enum class color {black,red,blue};

enum value_enum { satya = 10,balu = 20};
int main()
{
    enum value_enum obj;
    obj = satya;
    cout<<obj;

    color x = color :: red;
    cout<<int(x);
}
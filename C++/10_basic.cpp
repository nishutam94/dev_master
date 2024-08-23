#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int x;
std::cin>>x;
std::string s1;
s1= "Hello, I am nishant";
std::cout<< "staring :" << s1 << " int value : "<<x <<"\n" ;
string s2 ;
getline(cin,s2);

//int, long, long long, short int, float,double.
//string getline()
//char 
int age;
cin>>age;

if (age>18)
    {   
    cout<<"Adult \n";
    }
else if (age == 18)
    {
    cout<<"You are Adult Equal";
    }
else
    {
    cout<<"You are Adult Not Equal";
    }

switch(age)
    {
case 1: 
    cout<<"Print case 1";
    break;
case 2:
    cout<<"Print case 2";
    break;
default:
    cout<<"Print case 3";
    break;
}
cout << "check";


int arr[10]; //char short int float double long int , long long int , long double

for(int i =0; i < 3; i++)
{
    cin>>arr[i];
}

for(int i =0; i < 10; i++)
{
    cout<<arr[i]<<"\n";
}

string s3 = "Hi, I am a good person";
int length =  s3.size();
cout<<"length of string "<<s3 <<" == "<< length <<"\n";
}


#include<bits/stdc++.h>
using namespace std;

class LinklistNode
{
    public:
    int data ;
    LinklistNode * next;
    LinklistNode(int data)
    {
        this->data = data;
        this->next = NULL; 
    }
};
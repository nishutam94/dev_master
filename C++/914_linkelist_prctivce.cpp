#include<bits/stdc++.h>

using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void printlist(Node * &head)
{
    Node * temp = head;
    while(temp!=nullptr)
    {
        cout<<"\n "<<temp->data;
        temp=temp->next;

    }
        
}

Node * addnodefromlast(Node * &head,int data)
{
    Node *newnode = new Node(10);
    if (head == nullptr)
        head = newnode;

    else
    {   Node * temp = head;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
    
    temp->next =  newnode;
    }
    
    return head;
}

int main()
{

Node * head = nullptr;
addnodefromlast(head,10);
addnodefromlast(head,10);
addnodefromlast(head,10);
addnodefromlast(head,10);
addnodefromlast(head,10);
printlist(head);


}
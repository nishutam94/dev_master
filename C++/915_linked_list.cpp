#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node * next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void add_node_in_last_position(Node * &head,int value)
{
    Node * new_node = new Node(value);
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node * temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void add_node_in_first_position(Node * &head,int value)
{
    Node * new_node = new Node(value);
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node * temp = head;
    new_node->next = head;
    head = new_node;

}

void add_node_in_specific_position(Node * &head,Node * &middle,int value)
{
    Node * new_node = new Node(value);
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node * temp = head;

    while(temp->next!=middle)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = middle;

}

Node * find_middle_the_middle_element(Node * &head)
{
    Node * slow = head; 
    Node * slow_prev = head; 
    Node * fast = head;

    if(head == NULL)
        return head;
    
    while(fast != NULL && fast->next!=NULL)
    {
   
        slow = slow->next;
        fast=fast->next->next;
    }

    return slow;
    
}

void printlist(Node * &head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }

}

int main()
{
    Node * head = NULL;
    add_node_in_last_position(head,10);
    add_node_in_last_position(head,20);
    add_node_in_last_position(head,30);
    add_node_in_last_position(head,40);
    add_node_in_first_position(head,2);
    add_node_in_last_position(head,10);
    add_node_in_last_position(head,20);
    add_node_in_last_position(head,30);
    add_node_in_last_position(head,40);
    

    Node  * ans  = find_middle_the_middle_element(head);
    cout<<ans->data;

    add_node_in_specific_position(head,ans,100);
    printlist(head);
}

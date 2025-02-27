#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insert_end(struct node* &head,int data)
{
    struct node * newnode = new node(data);

    if (head == NULL)
    {
        head=newnode;
        return;
    }
    struct node * temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    
};

void insert_front(struct node * head,int data)
{
    struct node * newnode = new node(data);
    if (head==NULL)
    {
        head = newnode;
        return ;
    }

    struct node * temp = head;
    head=newnode;
    newnode->next = temp;
  
}

void printlist(struct node* &head)
{
    if(head == NULL)
        return ;

    struct node * temp = head;
    while (temp->next!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;

    }
    //cout<<temp->data<<"\n"<<" this";

}
int main()
{
    struct node * head=NULL;
    insert_end(head,10);
    insert_end(head,40);
    printlist(head);
    insert_front(head,20);
    insert_front(head,20);
    insert_front(head,30);
    printlist(head);
    return 0;
}




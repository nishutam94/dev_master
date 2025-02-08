#include<iostream>
using namespace std;

struct bst 
{
    int data;
    struct bst * left;
    struct bst * right;

    bst(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

struct bst * insert(struct bst * &root, int value)
{
    struct bst * newnode = new bst(value);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    if (value<(root->data))
    {
        root->left =  insert(root->left,value);
    }
    else
    {
         root->right =  insert(root->right,value);
    }
return root;
}

void inorder(struct bst * &root)
{
    if (root==NULL)
        return ;
    
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    
}

int main()
{
    struct bst * root = NULL;
    insert( root, 4);
    insert(root, 10);
    insert( root, 6);
    insert( root, 3);
    insert( root, 1);
    inorder(root);


    return 0;
}
#include<iostream>
#include<cstdio>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int sizeOfTree(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        return sizeOfTree(root->left)+sizeOfTree(root->right)+1;
    }
}

int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);

  printf("Size of the tree is %d", sizeOfTree(root));

    return 0;
}

#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
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

int height(struct node *root)
{
    int left,right;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        left = height(root->left);
        right = height(root->right);
    }
    return left>right?left+1:right+1;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    printf("height is %d\n",height(root));
    return 0;
}

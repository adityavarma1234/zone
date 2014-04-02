#include<cstdio>
#include<iostream>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_tree(struct node *root,int data)
{
  struct node *temp;
  temp = new node;
  temp->data = data;
  temp->next = NULL;
  temp->right = NULL;
  struct node *traverse;
  traverse = root;
  while(traverse)
    {
      
    }
}

int main()
{
  
  return 0;
}

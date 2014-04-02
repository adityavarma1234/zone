#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printLevelOrder(struct node *root)
{
    queue<struct node**>qu;
    struct node *temp_node = root;
    struct node **temp;
    while(temp_node)
    {
        printf("%d ",temp_node->data);
//        if(temp_node->data==5)
//            break;
        if(temp_node->left)
            qu.push(&temp_node->left);
        if(temp_node->right)
            qu.push(&temp_node->right);
        if(qu.size()>0)
        temp = qu.front();
        temp_node = *temp;
        if(qu.size()>0)
        qu.pop();
        else
        break;
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal is \n");
    printLevelOrder(root);
    return 0;
}



























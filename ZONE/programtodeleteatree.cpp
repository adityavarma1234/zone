#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void _deleteTree(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        _deleteTree(root->left);
        _deleteTree(root->right);
        cout << root->data << endl;
        free(root);
    }
}

void deleteTree(struct node **root)
{
    _deleteTree(*root);
    *root = NULL;
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    deleteTree(&root);
    if(root) cout << "No\n";
    else cout << "yes\n";
    return 0;
}

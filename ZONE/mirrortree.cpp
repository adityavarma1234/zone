#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void mirrorTree(struct node *root)
{
    if(root==NULL)
        return ;
    mirrorTree(root->left);
    mirrorTree(root->right);
    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Inorder before mirror\n";
    inorder(root);
    mirrorTree(root);
    cout << "\nInorder after mirror\n";
    inorder(root);
    return 0;
}

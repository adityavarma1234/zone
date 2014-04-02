#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node *create(int data)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
}

void inorderStack(node *root)
{
    if(root==NULL)
        return;
    stack<node *>mystack;
    node *current = root;
    bool done = false;
    while(!done)
    {
        if(current!=NULL)
        {
            mystack.push(current);
            current = current->left;
        }
        else
        {
            if(!mystack.empty())
            {
                current = mystack.top();
                mystack.pop();
                cout << current->data << " ";
                current = current->right;
            }
            else
            {
                done = true;
            }
        }
    }
}

int main()
{
    node *root = create(1);
    root->left = create(2);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right = create(3);
    inorderStack(root);
    return 0;
}

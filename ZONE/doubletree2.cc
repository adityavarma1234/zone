void doubletree(struct node *root)
{
  if(root==NULL)
    return;
  doubletree(root->left);
  doubletree(root->right);
  struct node *oldleft;
  oldleft = root->left;
  root->left = newnode(root->data);
  root->left->left = oldleft;
}

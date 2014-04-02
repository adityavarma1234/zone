bool childSum(struct node *root)
{
  int left_data=0,right_data = 0;
  if(root==NULL || (root->left==NULL && root->right==NULL))
    return true;
  if(root->left)
    left_data = root->left->data;
  if(root->right)
    right_data = root->right->data;
  if((root->data==left_data+right_data) && childSum(root->left) && childSum(root->right))
    return 1;
  else 
    return 0;
}

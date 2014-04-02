int isbst(struct node *root,int min,int max)
{
  if(root==NULL)
    return 1;
  if(root->data<min || root->data>max)
    return 0;
  return isbst(root->left,min,root->data-1) && isbst(root->right,root->data+1,max);
}


bool isBST(struct node *root)
{
  static struct node *prev=NULL;
  
  if(root)
    {
      if(!isBST(root->left))
	return false;
      if(prev!=NULL && root->data<=prev->data)
	return false;
      prev = root;
      isBST(root->right);
    }
  return true;
}

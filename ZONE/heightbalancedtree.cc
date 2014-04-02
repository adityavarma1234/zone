int  heightbalanced(struct node *root,int *height)
{
  if(root==NULL)
    {
      *height = 0;
      return 1;
    }
  int l=0,r=0;
  int lh = 0,rh=0;
  l = heightbalanced(root->left,&lh);
  r = heightbalanced(root->right,&rh);
  *height = max(lh,rh)+1;
  if(abs(lh-rh)>=2)
    return 0;
  else 
    return l&&r;
}

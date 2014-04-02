bool identicalTrees(struct node *root1,struct node *root2)
{
  if(root1==NULL && root2==NULL)
    return true;
  else
    return 
      (
       root1->data==root2->data &&
       identicalTrees(root1->left,root2->left) &&
       identicalTrees(root1->right,root2->right);
       );
  else 
    return 0;
}

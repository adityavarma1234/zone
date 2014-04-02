struct node *buildtree(char in[],char pre[],int start,int end)
{
  if(start>end)
    return NULL;
  static int preIndex = 0;
  struct node *tnode = newnode(pre[preIndex++]);
  if(start==end)
    return tnode;
  int Inindex = search(in,start,end,tnode->data);
  tnode->left = buildtree(in,pre,start,Inindex-1);
  tnode->right = buildtree(in,pre,Inindex+1,end);
  return tnode;
}

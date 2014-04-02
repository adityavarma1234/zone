#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<climits>
typedef long long LL;
using namespace std;

const LL maxx = 10000000;
LL seg[maxx],arr[maxx];

LL construct_seg_tree(LL ss,LL se,LL si)
{
  if(ss==se)
    {
      seg[si] = arr[ss];
      return arr[ss];
    }
  LL mid = ss+(se-ss)/2;
  seg[si] = min(construct_seg_tree(ss,mid,si*2+1),construct_seg_tree(mid+1,se,si*2+2));
  return seg[si];
}
LL RMQ_min(LL ss,LL se,LL qs,LL qe,LL index)
{
  if(qs<=ss && qs>=se)
    return seg[index];
  if(se<qs || ss>qe)
    return INT_MAX;
  LL mid = ss + (se-ss)/2;
  return min(RMQ_min(ss,mid,qs,qe,2*index+1),RMQ_min(mid+1,se,qs,qe,2*index+2));
}
LL RMQ_max(LL ss,LL se,LL qs,LL qe,LL index)
{
  if(qs<=ss && qs>=se)
    return seg[index];
  if(se<qs || ss>qe)
    return INT_MAX;
  LL mid = ss + (se-ss)/2;
  return max(RMQ_max(ss,mid,qs,qe,2*index+1),RMQ_max(mid+1,se,qs,qe,2*index+2));
}
LL getsum(LL ss,LL se,LL qs,LL qe,LL index)
{
  if(qs<=ss && qe>=se)
    return seg[index];
  if(se<qs || ss>qe)
    return 0;
  LL mid = ss+(se-ss)/2;
  return getsum(ss,mid,qs,qe,2*index+1)+getsum(mid+1,se,qs,qe,2*index+2);
}
/* 
A recursive function to update the nodes which have the given index in
their range. The following are parameters
i    --> index of the element to be updated. This index is in input array.
diff --> Value to be added to all nodes which have i in range 
*/
void update(LL ss,LL se,LL i,LL diff,LL index)
{
  if(i<ss || i>se)
    return;
  seg[index] = seg[index]+diff;
  if(se!=ss)
    {
      LL mid = ss+(se-ss)/2;
      update(ss,mid,i,diff,index*2+1);
      update(mid+1,se,i,diff,index*2+2);
    }
}

int main()
{
  
  return 0;
}

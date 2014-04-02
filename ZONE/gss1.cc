/*********************************************************
                                                
         mmmm      #          mmmm   mmmm   mmmm 
  mmm   m"  "m  mmm#   mmm   "   "# "   "# "   "#
 #"  "  #  m # #" "#  #"  #      m"     m"     m"
 #      #    # #   #  #""""    m"     m"     m"  
 "#mm"   #mm#  "#m##  "#mm"  m#mmmm m#mmmm m#mmmm
                                                 
*************************************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

//defines
#define MOD 1000000009LL
#define SIZE 100000009
#define MAXX 100000009
#define LL long long
#define ULL unsigned long long
#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define SD(x) inp(x)
#define SD2(n,m) SD(n);SD(m)
#define SLL(n) scanf("%lld",&n)
#define SLU(n) scanf("%llu",&n)
#define SS(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(__typeof(n) i=0;i<(n);i++)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<(b);++i)
#define FORE(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b,d) for(__typeof(b) i=(a);i<(b);i+=(d))
#define FORR(i,n,e) for(__typeof(n) i=(n);i>=(e);--i)
#define FORRD(i,n,e,d) for(__typeof(n) i=(n);i>=(e);i-=(d))
#define REP_IT(it,m) for(it=m.begin();it!=m.end();it++)
#define FORI(it,s) for(__typeof((s).begin()) (it)=(s).begin();(it)!=(s).end();(it)++)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(a,b) memset(a,b,sizeof(a))
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define checkbit(n,b) (((n)>>(b))&1)
#define PB push_back
#define MP make_pair
#define XX first
#define YY second
#define db(...) {}
#define dbt(...) {}
#define TEST int T;cin>>T;FORE(t,1,T)
#define getcx getchar_unlocked
//defines

template<typename T>inline void inp(T &n)
{
  n=0;
  int ch=getcx();
  int sign=1;
  while(ch<'0'||ch>'9')
    {
      if(ch=='-')sign=-1;
      ch=getcx();
    }
  while(ch>='0'&&ch<='9')
    {
      n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
    }
  n=n*sign;
}

using namespace std;
double _st;
void pre()
{
}
void doThis()
{ 
  
}
void end(){
#ifdef dexter
  fprintf(stdout,"\nTIME: %.3lf sec\n",(double)(clock()-_st)/(CLOCKS_PER_SEC));
#endif
}
const int maxx = 500000;
LL seg[maxx],arr[maxx];
LL construct_seg_tree(LL ss,LL se,LL si)
{
  if(ss==se)
    {
      seg[si] = arr[ss];
      return arr[ss];
    }
  LL mid = ss+(se-ss)/2;
  seg[si] = max(construct_seg_tree(ss,mid,si*2+1),construct_seg_tree(mid+1,se,si*2+2));
  return seg[si];
}
LL RMQ_min(LL ss,LL se,LL qs,LL qe,LL index)
{
  if(qs<=ss && qs>=se)
    return seg[index];
  if(se<qs || ss>qe)
    return MAXX;
  LL mid = ss + (se-ss)/2;
  return min(RMQ_min(ss,mid,qs,qe,2*index+1),RMQ_min(mid+1,se,qs,qe,2*index+2));
}
LL RMQ_max(LL ss,LL se,LL qs,LL qe,LL index)
{
  if(qs<=ss && qe>=se)
    return seg[index];
  if(se<qs || ss>qe)
    return -MAXX;
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
#ifdef dexter
  freopen("/home/dexter/Desktop/Dropbox/ZONE/inout/input.txt","r",stdin);
  freopen("/home/dexter/Desktop/Dropbox/ZONE/inout/output.txt","w",stdout);
  _st = clock();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  LL N;
  cin >> N;
 // cout << N<<endl;
  REP(i,N)
    cin>>arr[i];
    //cout<<"dfghj";
  //REP(i,N)
    //cout<<arr[i]<<" ";
    //cout <<"sdfghj";
  LL temp = construct_seg_tree(0,N-1,0);
  
  LL q,x,y;
  cin >>q;
  //cout << q<<endl;
  REP(i,q)
    {
      cin>>x>>y;
      //cout << x<<y<<endl;
      x--;
      y--;
      //cout << x<<y<<endl;
     cout << RMQ_max(0,N-1,x,y,0)<<endl;
    }
  end();
  return 0;
}

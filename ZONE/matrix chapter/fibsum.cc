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
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

//defines
#define MOD 1000000007LL
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
typedef struct matrix
{
  LL mat[2][2][40];
}matrix;
matrix pow_2;
void mul(LL n)
{
  if(n==1)
    {
      pow_2.mat[0][0][1]=1;
      pow_2.mat[0][1][1]=1;
      pow_2.mat[1][0][1]=1;
      pow_2.mat[1][1][1]=0;
      return;
    }
  LL temp,i,j,k;
  for(i=0;i<2;i++)
    {
      for(j=0;j<2;j++)
        {
	  temp=0;
	  for(k=0;k<2;k++)
	    temp=(temp+pow_2.mat[i][k][n-1]*pow_2.mat[k][j][n-1])%MOD;
	  pow_2.mat[i][j][n]=temp;
        }
    }
}
void pre()
{
  LL int i;
  for(i=1;i<40;i++)
    mul(i);
}
LL cal(LL n)
{
  if(n==0)
    return 0;
  if(n==1||n==2)
    return 1;
  n-=2;
  LL temp_mat[2][1],temp_ans[2][1];
  temp_mat[0][0]=1;
  temp_mat[1][0]=1;
  int var=1;
  while(n)
    {
      if(n%2)
	{
	  temp_ans[0][0]=((temp_mat[0][0]*pow_2.mat[0][0][var])%MOD+(temp_mat[1][0]*pow_2.mat[0][1][var])%MOD)%MOD;
	  temp_ans[1][0]=((temp_mat[0][0]*pow_2.mat[1][0][var])%MOD+(temp_mat[1][0]*pow_2.mat[1][1][var])%MOD)%MOD;
	  temp_mat[0][0]=temp_ans[0][0];
	  temp_mat[1][0]=temp_ans[1][0];
	}
      var++;
      n>>=1;
    }
  return temp_mat[0][0];
}
LL sum(LL num)
{
  return (cal(num)-1)%MOD;
}
LL fib_n_sum(LL start,LL end)
{
  LL ans=(sum(end+2)-sum(start+2))%MOD;
  return ans;
}
void doThis()
{ 
  
}
void end(){
#ifdef dexter
  fprintf(stdout,"\nTIME: %.3lf sec\n",(double)(clock()-_st)/(CLOCKS_PER_SEC));
#endif
}
int main()
{
#ifdef dexter
  freopen("/home/dexter/Desktop/ZONE/inout/input.txt","r",stdin);
  freopen("/home/dexter/Desktop/ZONE/inout/output.txt","w",stdout);
  _st = clock();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  LL t;
  scanf("%lld",&t);
  while(t--)
    {
      LL start,end;
      scanf("%lld%lld",&start,&end);
      LL sum=fib_n_sum(start-1,end);
      if(sum<0)
        {
	  sum+=MOD;
	  sum=sum%MOD;
        }
      printf("%lld\n",sum);
    }  

  end();
  return 0;
}

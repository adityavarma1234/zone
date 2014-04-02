/*
  If it were easy then everyone would do it
*/

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
#define TEST int T;SD(T);FORE(t,1,T)
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

void pre()
{

}
void doThis()
{ 

}
int flag[2000009],ans[2000009][2];
int main()
{
#ifdef dexter
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false);
  pre();
  int N,K;
  SD2(N,K);
  int temp;
  REP(j,N)
    {
      int i;
      i=j;
      //      if((float)i>(float)N/2)
      //i = N - i;
      SD(temp);
      flag[temp]=1;
      if(ans[temp][0]==0)
	ans[temp][0] = i+1;
      else
	ans[temp][0] = min(ans[temp][0],i+1);
      if(ans[temp][1]==0)
	ans[temp][1] = N-i;
      else
	ans[temp][1] = min(N-i,ans[temp][1]);
      //      cout<< ans[temp][0] << endl;
    }
  int f=-1;
  REP(i,1000009)
    {
      if(flag[i] && K-i<=1000000 && flag[K-i] && i != K/2)
	{
	  int j,k;
	  j = min(ans[i][0],ans[i][1]);
	  k = min(ans[K-i][0],ans[K-i][1]);
	  if(f==-1)
	    f = 1000000009;
	  j = max(j,k);
	  f = min(f,j);
	  //	  f = min(f,k);
	}
    }
  cout << f << endl;
  return 0;
}

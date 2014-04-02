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

int cell[1005],B[1005][1005],C[1005][1005],flag[1005];

void pre()
{
  REP(i,1005)flag[i]=0;
}
typedef pair<int,int> pi;
vector<pi> v(2005);
bool comp(pi a,pi b)
{
  return a.first>b.first;
}
int main()
{
#ifdef dexter
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false);
  //  pre();
  TEST
    {
      int N,M,K;
      scanf("%d %d %d\n",&N,&M,&K);
      REP(i,N)
	{
	  scanf("%d",&cell[i]);
	  cell[i] -= 1;
	}
      REP(i,N)
	{
	  REP(j,M)
	    {
	      scanf("%d",&B[i][j]);
	    }
	}
      REP(i,N)REP(j,M)scanf("%d",&C[i][j]);
      v.clear();
      REP(i,N)
	{
	  int value = B[i][cell[i]];
	  int max_value = value;
	  REP(j,M)
	    {
	      max_value = max(B[i][j]-C[i][j],max_value);
	    }
	  v.PB(make_pair(max_value-value,i));
	}
      sort(v.begin(),v.end(),comp);
      int ans=0;
      REP(i,K)
	{
	  if(K>=N)continue;
	  int j = v[i].second;
	  ans += B[j][cell[j]] + v[i].first;
	  flag[j] = 1;
	}
      REP(i,N)
	{
	  if(flag[i]==0)
	    ans += B[i][cell[i]];
	  flag[i] = 0;
	}
      printf("%d\n",ans);
    }
  return 0;
}

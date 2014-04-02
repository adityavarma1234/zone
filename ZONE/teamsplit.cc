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
#define MOD 1000000
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
bool comp(int a,int b)
{
  return a>b;
}
void doThis()
{ 

}
LL S[10000007];
int main()
{
#ifdef dexter
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false);
  pre();
  TEST
    {
      LL N;
      SD(N);
      LL a,b,c,d;
      SD2(a,b);SD2(c,d);
      LL first=0,second=0;
      LL temp1=d,temp2;
      S[temp1]++;
      for(int i=1;i<N;i++)
	{
	  temp2 = (((a*temp1)%MOD*temp1)%MOD + (b*temp1)%MOD+c)%MOD;
	  temp1 = temp2;
	  cout << temp1 << endl;
	  S[temp1]++;
	}
      bool flag = true;
      for(int i=1000000;i>=0;i--)
	{
	  if(!S[i]) continue;
	  if(flag)
	    {
	      if(S[i]%2)
		{
		  first += i*(S[i]/2 + 1);
		  second += i/2;
		}
	      else
		{
		  first += i/2;
		  second += i/2;
		}
	    }	  
	  else
	    {
	      if(S[i]%2)
		{
		  second += i/2 + 1;
		  first += i/2;
		}
	      else
		{
		  first += i/2;
		  second += i/2;
		}
	    }
	  flag = !flag;
	  S[i]=0;
	}
      printf("%lld\n",abs(first-second));
    }
  return 0;
}

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
ULL a[20][20];
bool isok(int n)
{
  if(n>=0 && n<=19) return true;
  return false;
}
ULL value(int x1,int x2,int y1,int y2,int z1,int z2,int k1,int k2)
{
  if(isok(x1)&& isok(x2) && isok(y1)&& isok(y2) && isok(z1) && isok(z2) && isok(k1) && isok(k2))
    {
      return a[x1][x2]*a[y1][y2]*a[z1][z2]*a[k1][k2];
    }
  return 0;
} 
int main()
{
#ifdef dexter
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false);
  pre();
  REP(i,20)
    REP(j,20)
    cin >> a[i][j];
  REP(i,20)
    {
      REP(j,20)
	cout << a[i][j]<<" ";
      cout << endl;
    }
 ULL ans = 0;
  REP(i,20)
    {
      REP(j,20)
	{
	  //right
	  ans = max(ans,value(i,j,i,j+1,i,j+2,i,j+3));
	  //down
	  ans = max(ans,value(i,j,i+1,j,i+2,j,i+3,j));
	  //diagonally
	  ans = max(ans,value(i,j,i+1,j+1,i+2,j+2,i+3,j+3));
	  //left
	  ans = max(ans,value(i,j,i,j-1,i,j-2,i,j-3));
	  //up
	  ans = max(ans,value(i,j,i-1,j,i-2,j,i-3,j));
	  //diagonally
	  ans = max(ans,value(i,j,i+1,j-1,i+2,j-2,i+3,j-3));
	}
    }
  cout << ans;
  return 0;
}

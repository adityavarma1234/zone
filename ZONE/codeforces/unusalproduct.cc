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
#define SD(x) scanf("%d",&x)
#define SD2(n,m) scanf("%d %d",&n,&m)
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
#define TEST int T;SD(T);FORE(t,1,T)
//defines

using namespace std;

void pre()
{

}
int arr[1001][1001],sol[1001][1001];
void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int N;
    scanf("%d",&N);
    int ans = 0;
    REP(i,N)
      REP(j,N)
      scanf("%d",&arr[i][j]);
    REP(i,N)
      {
	REP(j,N)
	  {
	    if(arr[i][j]==1 && arr[j][i]==1)
	      {
		ans++;
		sol[i][j] = 1;
		sol[j][i] = 1;
	      }
	  }
      }
    int Q;
    scanf("%d",&Q);
    REP(i,Q)
      {
	int first,second;
	scanf("%d",&first);
	if(first==3)
	  {
	    if(ans<0)
	      ans = 0;
	    cout <
	    continue;
	  }
	if(ans<0)ans=0;
	cin>>second;
	if(first==1)
	  {
	    REP(j,N)
	      {
		arr[second-1][j] = !arr[second-1][j];
		if(sol[second-1][j]==1)
		  {
		    if(arr[second-1][j]==0 || arr[j][second-1]==0)
		      {
			if((second-1)!=j)ans--;
			ans--;
			sol[second-1][j] = 0;
			sol[j][second-1]=0;
		      }
		  }
		else
		  {
		    if(arr[second-1][j]==1 && arr[j][second-1]==1)
		      {
			if((second-1)!=j)ans++;
			ans++;
			sol[j][second-1]=1;
			sol[second-1][j] = 1;
		      }
		  }
	      }
	  }
	else
	  {
	    REP(j,N)
	      {
		int k = second-1;
		arr[j][k] = !arr[j][k];
		if(sol[j][k]==1)
		  {
		    if(arr[j][k]==0 || arr[k][j]==0)
		      {
			sol[j][k] = 0;
			sol[k][j] = 0;
			if(j!=k)ans--;
			ans--;
		      }
		  }
		else 
		  {
		    if(arr[j][k]==1 && arr[k][j]==1)
 		      {
			sol[j][k] = 1;
			sol[k][j] = 1;
			if(j!=k)ans++;
			ans++;
		      }
		  }
	      }
	  }
      }
    return 0;
}

/*
    If it were easy then everyone would do it
    template : codechef.com/users/thecodegame
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
#define db(...) {}
#define dbt(...) {}
#define TEST int T;SD(T);FORE(t,1,T)
//defines


using namespace std;
int arr[1005][1005];
void pre()
{
    REP(i,1005)
    {
        REP(j,1005)
        {
            arr[i][j] = 0;
        }
    }
}
bool isSafe(int i,int j,int N)
{
    if(i<0 || j<0 || i>=N || j>=N)
        return false;
    else if(arr[i][j])
        return false;
    return true;

}
void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    int x[]= {1,-1,0,0};
    int y[] = {0,0,1,-1};
    int N;
    cin >> N;
    //SD(N);
    LL ans=0;
    REP(i,N)
    {
        REP(j,N)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=1;
                REP(m,4)
                {
                    if(isSafe(i+x[m],j+y[m],N))
                        arr[i+x[m]][j+y[m]]=-1;
                }
                ans++;

            }
        }
    }
    cout << ans;
    pnl;
    REP(i,N)
    {
        REP(j,N)
        {
            if(arr[i][j]==1)
                printf("C");
            else
                printf(".");
        }
        pnl;
    }
    return 0;
}




















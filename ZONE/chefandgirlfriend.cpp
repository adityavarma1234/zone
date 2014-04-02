/*
    (._.) ( l: ) (.-.) ( :l ) (._.)
    they see me rollin,, they hatin
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
#define LL long long
#define ULL unsigned long long
#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define SD(n) scanf("%d",&n)
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
//defines

#ifndef ONLINE_JUDGE
    #define getcx getchar
#else
    #define SD(x) inp(x)
    #define getcx getchar_unlocked
#endif

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

void doThis(){ }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    pre();
    int T;
    for(SD(T);T>0;T--)
    {
        char a[6],b[6];
        SS(a);
        SS(b);
        int dist;
        SD(dist);
        int time1,time2;
        time1 = (a[0]*10+a[1])*60 + (a[3]*10+a[4]);
        time2 = (b[0]*10+b[1])*60 + (b[3]*10+b[4]);
        long double ans1,ans2;
        ans1 = time1 - time2 + dist;
        int diff = time1 - time2;
        if(diff>=2*dist)
            ans2 = diff;
        else
        {
            time2 += dist;
            int temp = time1 - time2;
            ans2 = temp + ((double)dist-temp)/2 + dist;
        }
        printf("%.1Lf %.1Lf\n",ans1,ans2);
    }
    return 0;
}




















/****
    (._.) ( l: ) (.-.) ( :l ) (._.)
    they see me rollin,, they hatin
    template : codechef.com/users/thecodegame
*****/

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
#define db(...) {}
#define dbt(...) {}
#define SIZE 100000009
#define MAXX 100000009
//defines

#ifdef PAIN
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

//typedefs
ypedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> >VPII;
//typedefs

using namespace std;

void pre()
{

}

void doThis()
{

}
int main()
{
#ifdef PAIN
    freopen("input.txt","r",stdin);
#endif
    pre();
    int T;
    for(SD(T);T--;)
    {
        int N;
        SD(N);
        int a[N],b[N];
        REP(i,N)
        {
            SD2(a[i],b[i]);
        }
        int count=0;
        string ans = "";
        /**
            L always comes before R and + before -
            Carefull when L=R
        **/
        REP(i,N-1)
        {
            count += ABS(a[i]-a[i+1]) + ABS(b[i]-b[i+1]);
            while(true)
            {
                if(a[i]==a[i+1] && b[i]==b[i+1])
                {
                    break;
                }
                else if(a[i]<=a[i+1] && b[i]>=b[i+1])
                {
                    db(simple when no L=R possible);
                    while(a[i]!=a[i+1])
                    {
                        ans += "L+";
                        a[i]++;
                    }
                    while(b[i]!=b[i+1])
                    {
                        ans += "R-";
                        b[i]--;
                    }
                }
                else if(a[i]>=a[i+1] && b[i]<=b[i+1])
                {
                    db(simple when no L=R possible);
                    while(a[i]!=a[i+1])
                    {
                        ans += "L-";
                        a[i]--;
                    }
                    while(b[i]!=b[i+1])
                    {
                        ans += "R+";
                        b[i]++;
                    }
                }
                else if(a[i]<=a[i+1] && b[i]<= b[i+1])
                {
                    db(when L=R possible);
                    while(a[i]+1<b[i] && a[i]!=a[i+1])
                    {
                        ans += "L+";
                        a[i]++;
                    }
                    if(b[i]!=b[i+1])
                    {
                        ans += "R+";
                        b[i]++;
                    }
                }
                else if(a[i]>=a[i+1] && b[i]>=b[i+1])
                {
                    db(when L=R possible);
                    while(a[i]!=a[i+1])
                    {
                        ans += "L-";
                        a[i]--;
                    }
                    if(b[i]-1>a[i] && b[i]!=b[i+1])
                    {
                        ans += "R-";
                        b[i]--;
                    }
                }
            }
        }
         cout << count << endl << ans << endl;
    }
    return 0;
}



















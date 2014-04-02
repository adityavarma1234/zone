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
#define TEST int T;SD(T);FORE(t,1,T)
//defines

#ifdef dexter
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
int a[200000000];//b[500000000];

int subsetsum(int arr[],int start,int end)
{
    FILL(a,0);
    //FILL(b,0);
    for(int i=start;i<end;i++)
    {
        unsigned long long value = 0;
        for(int j=i;j<end;j++)
        {
            value += arr[j];
            if(value<=200000000)
            {
                a[value-1] = 1;
            }
        }
    }
    for(int i=0;i<200000000;i++)
    {
        if(!a[i])
            return i+1;
        a[i]=0;
    }
    for(int i=start;i<end;i++)
    {
        unsigned long long value = 0;
        for(int j=i;j<end;j++)
        {
            value += arr[j];
            if(value>200000000 && value<=400000000)
            {
                a[value-200000001] = 1;
            }
        }
    }
    for(int i=0;i<200000000;i++)
    {
        if(!a[i])
            return i+200000001;
        a[i]=0;
    }
    for(int i=start;i<end;i++)
    {
        int value = 0;
        for(int j=i;j<end;j++)
        {
            value += arr[j];
            if(value>400000000 && value<=600000000)
            {
                a[value-400000001] = 1;
            }
        }
    }
    for(int i=0;i<200000000;i++)
    {
        if(!a[i])
            return i+400000001;
        a[i] = 0;
    }
    for(int i=start;i<end;i++)
    {
        int value = 0;
        for(int j=i;j<end;j++)
        {
            value += arr[j];
            if(value>600000000 && value<=800000000)
            {
                a[value-600000001] = 1;
            }
        }
    }
    for(int i=0;i<200000000;i++)
    {
        if(!a[i])
            return i+600000001;
        a[i] = 0;
    }
    for(int i=start;i<end;i++)
    {
        int value = 0;
        for(int j=i;j<end;j++)
        {
            value += arr[j];
            if(value>800000000 && value<=1000000000)
            {
                a[value-800000001] = 1;
            }
        }
    }
    for(int i=0;i<200000000;i++)
    {
        if(!a[i])
            return i+800000001;
    }
    return 1000000001;
}

void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    int N,M;
    SD(N);
    int A[N];
    REP(i,N)
    {
        SD(A[i]);
    }
    SD(M);
    REP(i,M)
    {
        int x,y;
        SD2(x,y);
        printf("%d\n",subsetsum(A,x-1,y));
    }
    return 0;
}




















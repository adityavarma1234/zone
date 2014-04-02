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
#define YES printf("YES\n")
#define NO printf("NO\n")
//defines

#ifdef dexter
#define getcx getchar
#else
#define SD(x) inp(x)
#define getcx getchar_unlocked
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
#endif



using namespace std;

struct node
{
    int a,b;
};
vector<node>v;
int seen[105];
void pre()
{

}
void doThis() { }

int chooseBest()
{
    if(v.size()==0) return 0;
    FOREACH(it,v)
    {
        if(((*it).a)==1 || ((*it).b)==1 || ((*it).b)%((*it).a)==0)
        {
//            cout << (*it).a <<" "<<(*it).b; pnl;
            (*it).a = 1;
            (*it).b = 1;
//            cout << "changed to"<<(*it).a <<" "<<(*it).b; pnl;
            return 1;
        }
    }
    FOREACH(it,v)
    {
        int temp = ((*it).b)%((*it).a);
        if(temp!=1)
        {
            if((temp+(*it).a)!=(*it).b)
            {
                (*it).b = temp + (*it).a;
            }
            else
            {
                int x = (*it).a;
                (*it).a = ((*it).b)%((*it).a);
                (*it).b = x;
            }
            return 1;
        }
//         cout << (*it).a <<" "<<(*it).b; pnl;

    }
     return 0;
}

void erase(int n)
{
    REP(i,n)
    {
        if(seen[i]!=1 && v[i].a==v[i].b)
        {
            seen[i]=1;
        }
    }
    REP(i,n)
    {
        if(seen[i]==1)
        {
            v.erase(v.begin()+i);
            seen[i]++;
        }
    }
}

int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    TEST
    {
        int N;
        SD(N);
        v.clear();
        REP(i,105) seen[i]=0;
        REP(i,N)
        {
            int a,b;
            SD2(a,b);
            node temp;
            temp.a = a<b?a:b;
            temp.b = a<b?b:a;
            v.PB(temp);
        }
        int steps=0;
        bool flag = true;
//        cout << "case " << t ;pnl;
        while(true)
        {
            if(chooseBest())
            {
                erase(N);
                steps++;
//                cout << "steps " << steps ;pnl;
            }
            else
            {
                if(steps%2==0)
                    flag = false;
                break;
            }
        }
        if(flag) YES;
        else NO;
    }
    return 0;
}




















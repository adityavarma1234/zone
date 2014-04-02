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

void pre()
{

}
struct node{
int start,end;
};
void doThis() { }
bool comp(int a,int b)
{
    return a<b;
}
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    TEST
    {
        int N,K;
        SD2(N,K);
        int start[N],end[N];
        vector<node> v;
        REP(i,N)
        {
            SD2(start[i],end[i]);
            node temp;
            temp.start = start[i];
            temp.end = end[i];
            v.PB(temp);
        }
        sort(start,start+N,comp);
        sort(end,end+N,comp);
//        REP(i,N)
//        {
//            cout << start[i] <<" ";
//        }
//        pnl;
//        REP(i,N)
//        {
//            cout << end[i] <<" ";
//        }
//        pnl;
        int ans = 0,groups=0,prev=0,current=1;
        int i=0,j=0;
        while(i<N && j<N)
        {
            if(start[i]>end[j])
            {
                ans--;
                prev = current;
                current = j;
                j++;
            }
            //i++;
            ans++;
            i++;
            if(ans>=K)
                groups++;
        }
//        if(groups!=0){
        if(ans==K) groups--;
        cout << groups ;pnl;
//        cout << "ans is "<< ans ;pnl;
//        if(ans<K){
//            printf("0\n");
//
//            continue;
//        }
//
//        else
//        {
//            printf("%d\n",ans-K+1);
//        }
    }
    return 0;
}



















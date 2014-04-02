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

void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    int N,M,K,Q;
    SD(N);SD(M);SD(K);
//    cout << N <<" "<< M << " "<< K << endl;
    int matrix[N+1][M+1],query[N+1][N+1];
    int count,max_count,area;
    REP(i,N+1)
    {
        REP(j,M+1)
        {
            if(i==0 || j==0)
            matrix[i][j] = 0;
            else
            matrix[i][j] = 1;
        }
    }
//    REP(i,N+1)
//    {
//        REP(j,N+1)
//        {
//            query[i][j]=0;
//        }
//    }
    FORE(i,1,K)
    {
        int x,y;
        SD2(x,y);
        //cout << x << " " << y << endl;
        matrix[x][y] = 0;
    }
    FOR(i,1,N+1)
    {
        count = 0;
        max_count = 0;
        FOR(j,1,M+1)
        {
            if(matrix[i][j]==0)
            {
                count = 0;
            }
            else
            {
                count++;
            }
            if(max_count<count)
            {
                max_count = count;
            }
        }
        query[i][i] = max_count;
    }
//    REP(i,N+1)
//    {
//        REP(j,N+1)
//        {
//            cout << query[i][j] << " ";
//        }
//        pnl;
//    }
    for(int k=N-1;k>=1;k--)
    {
//        cout<< "k is---" << k ;pnl;
        FOR(i,1,k+1)
        {
            count = 0;
            max_count = 0;
            FOR(j,1,M+1)
            {
                matrix[i][j] = matrix[i][j] & matrix[i+1][j];
                if(matrix[i][j]==0)
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                if(max_count<count)
                {
                    max_count = count;
                }
            }
            area = max_count*(N-k+1);
//            cout << "area---" << area<<"i and j "<< i << " " << N-k+i;pnl;
           // query[i][N-K+1] = max(area,query[i][N-k+1],query[i+1][N-k+1]);
           query[i][N-k+i] = max(area,query[i][N-k+i-1]);
           query[i][N-k+i] = max(query[i][N-k+i],query[i+1][N-k+i]);
        }
    }
//    cout <<"-------"<<endl;
//    REP(i,N+1)
//    {
//        REP(j,N+1)
//        {
//            cout << query[i][j] << " ";
//        }
//        pnl;
//    }
    SD(Q);
//    cout << "q---" << Q << endl;
    REP(i,Q)
    {
        int x,y;
        SD2(x,y);
        printf("%d\n",query[x][y]);
    }

    return 0;
}




















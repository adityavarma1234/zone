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
typedef pair<LL,LL> key;
map<key,LL> subset;
map<key,LL> result;
bool isSubsetSum(int set[], int start,int n, int sum)
{
//bool subset[sum+1][n+1];
    for (int i = 0; i <= n; i++)
        subset[make_pair(0,i)] = true;
    for (int i = 1; i <= sum; i++)
        subset[make_pair(i,0)]=false; //subset[i][0] = false;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = start; j <= n; j++)
        {
            subset[make_pair(i,j)]=subset[make_pair(i,j-1)];//subset[i][j] = subset[i][j-1];
            if (i >= set[j-1])
                subset[make_pair(i,j)] = subset[make_pair(i,j)] || subset[make_pair(i-set[j-1],j-1)];
//subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
        }
    }
    return subset[make_pair(sum,n)];//subset[sum][n];
}

//
//bool isSubsetSum(int set[], int start,int n, int sum)
//{
// if (sum == 0)
// return true;
// if (n <start && sum != 0)
// return false;
//
// if (set[n-1] > sum)
// return isSubsetSum(set, n-1, sum);
// return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
//}

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
        if(A[i]!=1)
        {
            result[make_pair(i+1,i+1)] = 1;
        }
        else
        {
            result[make_pair(i+1,i+1)] = 2;
        }
    }
    SD(M);
    REP(i,M)
    {
        int start,end,temp;
        SD2(start,end);
        LL j=1,k=1;
        temp = 1111111111;
        FORE(x,start-1,end-1)
        {
            if(temp>A[x]) temp = A[x];
        }
        if(temp!=1)
        {
            printf("1\n");
            continue;
        }
        if(result.find(make_pair(start,end))!=result.end())
        {
            printf("%d\n",result[make_pair(start,end)]);
            continue;
        }

        while(1)
        {
//subset.clear();
            if(isSubsetSum(A,start,end,j))
            {
                if(j==1)j++;
                j += 2;
            }
            else
            {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}

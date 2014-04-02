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
int S[21][20007];
int hash1[20007];
bool ok[21][21];
bool seen[21];
void pre()
{

}
void doThis()
{
}
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    //pre();//doThis();
    int pow2[22] = {1,2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
    int ans=0;
    int N,M;
    SD2(N,M);
    REP(i,M)
    {
        int K;
        SD(K);
        S[i][0]=K;
        REP(j,K)
        {
            int temp;
            SD(temp);
            S[i][j+1] = temp;
        }
    }
    REP(i,M)
    {
        REP(k,S[i][0])
            hash1[S[i][k+1]]=1;
        FOR(j,i+1,M)
        {
            bool flag = true;
            REP(k,S[j][0])
            {

                if(hash1[S[j][k+1]]==1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ok[i][j] = true;
                ok[j][i] = true;
            }
        }
        if(i!=M-1)
        REP(k,S[i][0])
            hash1[S[i][k+1]]=0;
    }
    
    REP(i,pow2[M])
    {
        int j= i;
        int count=0,tempans = 0;
        bool flag = true;
        while(j)
        {
            int temp = j%2;
            if(temp)
            {
                REP(k,21)
                if(seen[k])
                {
                    if(!ok[k][count])
                    {
                    	//cout << k <<" " << count << " collide\n";
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    seen[count] = true;
                    tempans++;
                }
                if(!flag)
                    break;
            }
            count++;
            j = j/2;
        }
        //cout << "ans "<< ans << endl;
        //REP(k,21)cout << seen[k] << " ";cout << endl;
        REP(k,21)seen[k]=0;
        if(flag)
            ans = max(ans,tempans);
    }
    cout << ans << endl;
    return 0;
}

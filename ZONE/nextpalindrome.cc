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
#define TEST for(SD(T);T--;)
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

bool isall9(string a)
{
    int len = a.size();
    int count = 0;
    REP(i,len)
    {
        if(a[i]=='9')
            count++;
        else
            break;
    }
    return len==count?true:false;
}

bool ispalin(string a)
{
    int len = a.size();
    int start,end;
    start = 0;
    end = len-1;
    while(start<=end)
    {
        if(a[start]==a[end])
        {
            start++;
            end--;
        }
        else
            break;
    }
    return start>end?true:false;
}
void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    int T;
    TEST
    {
        string a;
        cin >> a;
        int len = a.size();
        if(isall9(a))
        {
            cout << 1;
            REP(i,len-1) cout << 0;
            cout << 1;
        }
        else if(ispalin(a))
        {
            int i,j;
            if(len%2)
            {
                i = len/2 - 1;
                j = len/2 + 1;
                if(a[len/2]=='9')
                {
                    a[len/2] = '0';
                    if(a[i]=='9')
                    {
                        while(a[i]=='9')
                        {
                            a[i] = '0';
                            i--;
                            a[j] = '0';
                            j++;
                        }
                    }
                    a[i]++;
                    a[j]++;
                }
                else
                {
                    a[len/2]++;
                }
            }
            else
            {
                i = len/2 - 1;
                j = len/2;
                if(a[i]=='9')
                {
                    while(a[i]=='9')
                    {
                        a[i] = '0';
                        i--;
                        a[j] = '0';
                        j++;
                    }
                }
                a[i]++;
                a[j]++;
            }
            cout << a;
        }
        else
        {
            int i,j;
            if(len%2)
            {
                i = len/2-1;
                j = len/2+1;
            }
            else
            {
                i = len/2 - 1;
                j = len/2;
            }
            while(a[i]==a[j])
            {
                i--;
                j++;
            }
            if(a[i]>a[j])
            {
                while(i>=0)
                {
                    a[j] = a[i];
                    i--;
                    j++;
                }
            }
            else
            {
                if(len%2)
                {
                    i = len/2-1;
                    j = len/2+1;
                }
                else
                {
                    i = len/2 - 1;
                    j = len/2;
                }
                if(len%2)
                {
                    int k = len/2;
                    while(k>=0)
                    {
                        if(a[k]=='9')
                        {
                            a[k]='0';
                        }
                        else
                        {
                            a[k]++;
                            break;
                        }
                        k--;
                    }
                    while(i>=0)
                    {
                        a[j] = a[i];
                        i--;
                        j++;
                    }
                }
                else
                {
                    int k = len/2 - 1;
                    while(k>=0)
                    {
                        if(a[k]=='9')
                        {
                            a[k]='0';
                        }
                        else
                        {
                            a[k]++;
                            break;
                        }
                        k--;
                    }
                    while(i>=0)
                    {
                        a[j]=a[i];
                        i--;
                        j++;
                    }
                }
            }
            cout << a;
        }
        pnl;
    }
    return 0;
}




















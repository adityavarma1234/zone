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
int strtoint(int start,int end,char a[])
{
    int num=0,temp;
    while(start<=end)
    {
        temp = a[start]-'0';
        num = num*10 + temp;
        //cout << "num " << num << endl;
        start++;
    }
    return num;
}
void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
#endif
    pre();
    char a[1000],b;
    int T;
    scanf("%d\n",&T);
    REP(t,T)
    {
        gets(a);
        b=getchar();
        int len = strlen(a);
        //cout << a  << endl;
        int i,j,x,y,z;
        REP(k,len) if(a[k+2]=='+')
        {
            i=k;
            //cout << "i is "<< i << endl;
            break;
        }
        FOR(k,i+4,len) if(a[k+2]=='=')
        {
            j=k;
           // cout << "j is" << j << endl;
            break;
        }
        db(x + y = z);
        int flag = 0;
        REP(k,i) if(a[k]<'0' || a[k]>'9')
        {
            flag = 1;
            //cout << "x" << endl;
            break;
        }
        if(flag)
        {
            y = strtoint(i+4,j,a);
            z = strtoint(j+4,len-1,a);
            x = z - y;
        }
        else
        {
            x = strtoint(0,i,a);
            FOR(k,i+4,j) if(a[k]<'0' || a[k]>'9')
            {
                flag = 1;
                //cout << "y" << endl;
                break;
            }
            if(flag)
            {
                z = strtoint(j+4,len-1,a);
                y = z - x;
            }
            else
            {
                y = strtoint(i+4,j,a);
                z = x + y;
                //cout << "z" << endl;
            }
        }

        cout << x << " + " << y << " = " << z << endl;
    }
    return 0;
}




















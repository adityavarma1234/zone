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
#define SD(x) scanf("%d",&x)
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
#define TEST int T;SD(T);FORE(t,1,T)
//defines

using namespace std;

void pre()
{

}

void doThis() { }
int main()
{
#ifdef dexter
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,k;
    cin>>n>>k;
    int arr[n],a[n];
    REP(i,n)
    {
        cin>>arr[i];
        ans[i]=arr[i];
    }
//    ans a[1000];
    int maxcount = 0;
    int fixedindex = 0;
    REP(i,n-1)
    {
        int j = i-1;
        while(j>=0)
        {
            int a1 = arr[j+1];
            int b = arr[j];
            if(b-a1==k)
                ;
            else if(b-a1<k)
            {
//                a[].flag = false;
//                a[count].j = i+2;
                int temp = k-b+a1;
                a[j]+=temp;
                count++;
            }
            else
            {
//                a[count].flag = true;
//                a[count].j=i+2;
                int temp = b-a1-k;
                arr[j]-=a[count].x;
                count++;
            }
            j--;
        }
    }
    cout << count << endl;
    REP(i,count)
    {
        if(a[i].flag)
            cout << "- ";
        else
            cout << "+ ";
        cout << a[i].j << " "<< a[i].x<<endl;
    }

    return 0;
}

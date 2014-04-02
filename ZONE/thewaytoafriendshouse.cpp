/*
Dear future me i am really sorry for what i am doing right now
Hope you can find it in your self to forgive me
%%%%%%%%%%%%%  AUTHOR %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%  ADITYA %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%   VARMA %%%%%%%%%%%%%%%%%%%
Tell me and I will forget. Show me and I will remember. Involve me and I will understand.
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

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORL(i,a,b) for(int i=a;i<=b;i++)
#define FORI(i,a,b,inc) for(int i=a;i<b;i=i+inc)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define LL long long
#define MAX 1003002
#define pb push_back
#define MOD 1000000007

using namespace std;

struct point{
    int x,y;
};

bool myfunction(point a,point b)
{
    if(a.x<b.x) return true;
    else if(a.x==b.x && a.y>b.y) return true;
    else return false;
}

long double distance(int x1,int x2,int y1,int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void pre()
{

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    pre();
    int T;
    for(scanf("%d",&T);T>0;T--)
    {
        int N;
        scanf("%d",&N);
        char c;
        scanf("%c",&c);
        point a[N];
        FOR(i,0,N) scanf("%d%d",&a[i].x,&a[i].y);
        scanf("%c",&c);
        sort(a,a+N,myfunction);
        long double ans=0;
        FOR(i,0,N-1) ans += distance(a[i].x,a[i+1].x,a[i].y,a[i+1].y);
        printf("%.2Lf\n",ans);
    }
    return 0;
}




















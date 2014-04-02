/*
Dear future me i am really sorry for what i am doing right now
Hope you can forgive me
%%%%%%%%%%%%%  AUTHOR %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%  ADITYA %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%   VARMA %%%%%%%%%%%%%%%%%%%
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

using namespace std;

//inline int max(int a,int b){return a>b?a:b;}

void pre()
{

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    pre();
    int T,N,a[102][102];
    for(scanf("%d",&T);T>0;T--)
    {
        scanf("%d",&N);
        int dp[102][102],ans=0;
        for(int i=0;i<102;i++)for(int j=0;j<102;j++)dp[i][j]=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        dp[0][0] = ans = a[0][0];
        for(int i=1;i<N;i++){
            dp[i][0] = dp[i-1][0]+a[i][0];
            if(dp[i][0]>ans)
                ans = dp[i][0];
        }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
                if(dp[i][j]>ans)
                    ans = dp[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}




















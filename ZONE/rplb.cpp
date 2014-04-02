/*
    (._.) ( l: ) (.-.) ( :l ) (._.)
    they see me rollin,, they hatin
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

int blueberries(int arr[],int N,int K)
{
    if(N<=0 || K<=0)
        return 0;
    else if(arr[N-1]>K)
        return blueberries(arr,N-1,K);
    else
        return max(blueberries(arr,N-1,K),arr[N-1]+blueberries(arr,N-2,K-arr[N-1]));
}

int blueberriesdp(int weight[],int N,int K)
{
    int dp[N+1][K+1];
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=K;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weight[i-1]<=j)
            {
                if(i==1)
                {
                    dp[i][j] = weight[i-1];
                }
                else
                {
                    dp[i][j] = max(weight[i-1]+dp[i-2][j-weight[i-1]],dp[i-1][j]);
                }
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][K];
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
    int T,N,K;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        scanf("%d %d",&N,&K);
        int arr[N];
        FOR(i,0,N) scanf("%d",&arr[i]);
        printf("Scenario #%d: %d\n\n",x,blueberriesdp(arr,N,K));
    }
    return 0;
}




















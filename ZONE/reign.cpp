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

typedef long long int ll;
using namespace std;

void pre()
{

}

inline ll max(ll x, ll y)
{ return (y > x)? y : x; }

vector<ll> max_sum_left(int N, vector<ll> arr)
{
    vector<ll> res(N);
    for(int i = 0; i < N; i++)
    {
        res[i] = 0;
    }
    res[0] = arr[0];
    LL currMax = arr[0];
    for(int i = 1; i < N; i++)
    {
        currMax = max(arr[i],arr[i]+currMax);
        res[i] = max(res[i-1], currMax);
    }
    return res;
}

vector<LL> min_sum_left(int N, vector<LL> arr)
{
    vector<LL> res(N);
    for(int i = 0; i < N; i++)
    {
        res[i] = 0;
    }
    res[0] = arr[0];
    LL currMin = arr[0];
    for(int i = 1; i < N; i++)
    {
        currMin = min(arr[i],arr[i]+currMin);
        res[i] = min(res[i-1], currMin);
    }
    return res;
}

vector<ll> max_sum_right(int N, vector<ll> arr)
{
    vector<ll> res(N);
    for(int i = 0; i < N; i++)
    {
        res[i] = 0;
    }
    res[N-1] = arr[N-1];
    ll currMax = arr[N-1];
    for(int i = N-2; i >= 0; i--)
    {
        currMax = max(arr[i],arr[i]+currMax);
        res[i] = max(res[i+1], currMax);
    }
    return res;
}

vector<LL> min_sum_right(int N, vector<LL> arr)
{
    vector<LL> res(N);
    for(int i = 0; i < N; i++)
    {
        res[i] = 0;
    }
    res[N-1] = arr[N-1];
    LL currMin = arr[N-1];
    for(int i = N-2; i >= 0; i--)
    {
        currMin = min(arr[i],arr[i]+currMin);
        res[i] = min(res[i+1], currMin);
    }
    return res;
}

LL compute(int N, vector<LL> arr,int K)
{
    LL maxSum = arr[0];
    LL minSum = arr[0];
    vector<LL> leftMax = max_sum_left(N,arr);
    vector<LL> leftMin = min_sum_left(N,arr);
    vector<LL> rightMax = max_sum_right(N,arr);
    vector<LL> rightMin = min_sum_right(N,arr);

    LL diff1,diff2;
    for(int i = 0; i+K < N-1; i++)
    {
        diff1 = leftMax[i]+rightMax[i+K+1];
        if(diff1 >= maxSum)
            maxSum = diff1;

        diff2 = rightMin[i+K+1]+leftMin[i];
        if(diff2 <= minSum)
            minSum = diff2;
    }
    if(minSum<0 || maxSum<0)
    return abs(maxSum)>abs(minSum)?maxSum:minSum;
    return maxSum;
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
        ll N,K,temp;
        scanf("%lld%lld",&N,&K);
        vector<ll> arr;
        FOR(i,0,N) scanf("%lld",&temp),arr.pb(temp);
        ll ans = compute(N,arr,K);
        printf("%lld\n",ans);
    }
    return 0;
}




















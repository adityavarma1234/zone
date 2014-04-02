/*
I don't know WTF i am doing
%%%%%%%%%%%%%  AUTHOR %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%  ADITYA %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%   VARMA %%%%%%%%%%%%%%%%%%%

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

void pre()
{

}

vector<LL> max_sum_left(int N,vector<LL> arr)
{
    vector<LL> res(N,0);
    res[0] = arr[0];
    LL currMax = arr[0];
    FOR(i,1,N)
    {
        currMax = max(arr[i],arr[i]+currMax);
        res[i] = max(res[i-1],currMax);
    }
    return res;
}

vector<LL> min_sum_left(int N,vector<LL> arr)
{
    vector<LL> res(N,0);
    LL currMin = arr[0];
    FOR(i,1,N)
    {
        currMin = min(arr[i],arr[i]+currMin);
        res[i] = min(res[i-1],currMin);
    }
    return res;
}

vector<LL> max_sum_right(int N,vector<LL> arr)
{
    vector<LL> res(N,0);
    res[N-1] = arr[N-1];
    LL currMax = arr[N-1];
    for(int i=N-2;i>=0;i--)
    {
        currMax = max(arr[i],arr[i]+currMax);
        res[i] = max(res[i+1],currMax);
    }
    return res;
}

vector<LL> min_sum_right(int N,vector<LL> arr)
{
    vector<LL> res(N,0);
    res[N-1] = arr[N-1];
    LL currMin = arr[N-1];
    for(int i=N-2;i>=0;i--)
    {
        currMin = min(arr[i],arr[i]+currMin);
        res[i] = min(res[i+1],currMin);
    }
    return res;
}

LL compute(int N,vector<LL> arr)
{
    LL maxDiffAbs = arr[0] - arr[1];
    vector<LL> leftMax = max_sum_left(N,arr);
    vector<LL> leftMin = min_sum_left(N,arr);
    vector<LL> rightMax = max_sum_right(N,arr);
    vector<LL> rightMin = min_sum_right(N,arr);

    LL diff;
    for(int i = 0; i < N-1; i++)
    {
        diff = leftMax[i]-rightMin[i+1];
        if(diff >= maxDiffAbs)
            maxDiffAbs = diff;

        diff = rightMax[i+1]-leftMin[i];
        if(diff >= maxDiffAbs)
            maxDiffAbs = diff;
    }
    return maxDiffAbs;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    pre();
    int t,dim;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d",&dim);
        vector<LL> arr;
        for(int j = 0; j < dim; j++)
        {
            LL elem;
            scanf("%lld",&elem);
            arr.push_back(elem);
        }
        LL ans = compute(dim,arr);
        printf("%lld\n",ans);
    }

    return 0;
}




















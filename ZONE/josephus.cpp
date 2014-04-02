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

void pre()
{

}

int josephus(int n,int k)
{
    if(n==1)
        return 1;
    return (josephus(n-1,k)+k)%n;

}

int josephusloop(int n,int k)
{
    int r = 0;
    int i =1;
    while(i<=n)
    {
        r = (r+k)%i;
        i++;
    }
    return r+1;
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
        int n;
        scanf("%d",&n);
        int ans = josephus(n,2);
        cout << ans << endl;
    }
    return 0;
}

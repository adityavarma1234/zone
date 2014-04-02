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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    pre();
    int T,ans,maxans;
    for(scanf("%d",&T); T>0; T--)
    {
        int N;
        scanf("%d",&N);
        int i,a[N],b[N],j;
        for(i=0; i<N; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        sort(a,a+N);
        sort(b,b+N);
        ans = maxans=0;
        i= j =0;
        while(i<N && j<N)
        {
            if(a[i]<=b[j])
            {
                i++;
                ans++;
            }
            else
            {
                j++;
                ans--;
            }
            maxans = ans>maxans?ans:maxans;
        }
        printf("%d\n",maxans);
    }
    return 0;
}




















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

void pre()
{

}
bool consider(pair<int,int> a){ return a.second>1;}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    pre();
    map<int,int>mymap;
    map<int,int>::iterator it;
    int a,b,c,d;
    for(scanf("%d%d%d",&a,&b,&c),d=a+b+c;d>0;d--)
    {
        scanf("%d",&a);
        it = mymap.find(a);
        if(it==mymap.end())
        {
            mymap.insert(pair<int,int>(a,1));
        }
        else
        {
            it->second++;
        }
    }
    int ans = count_if(mymap.begin(),mymap.end(),consider);
    printf("%d\n",ans);
    for(it=mymap.begin();it!=mymap.end();it++) if(it->second>1)printf("%d\n",it->first);
    return 0;
}



















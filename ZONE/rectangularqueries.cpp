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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    pre();
    int N;
    scanf("%d",&N);
    int arr[N+5][N+5][11],temp;
    for(int i=0; i<=N; i++)
    {
        for(int k=1; k<=10; k++)
        {
            arr[i][0][k]=0;
        }
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            scanf("%d",&temp);
            for(int k=1; k<=10; k++)
            {
                arr[i][j][k] = arr[i][j-1][k];
                if(k==temp) arr[i][j][k]++;
            }
        }
    }
    int Q;
    scanf("%d",&Q);
    int x1,x2,y1,y2;
    for(int i=0;i<Q;i++)
    {
        int distinct = 0;int seen[11];
        for(int i=1;i<=10;i++) seen[i]=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++)
        {
            for(int k=1;k<=10;k++)
            {
                if(arr[i][y2][k]-arr[i][y1-1][k]>0&& seen[k]==0) seen[k]=1, distinct++;
            }
        }
        printf("%d\n",distinct);
    }

    return 0;
}




















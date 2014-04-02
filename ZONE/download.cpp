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


struct Interval
{
    int start;
    int end;
};

bool compareInterval(Interval a,Interval b)
{
    return (a.start>b.start)?false:true;
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
    vector<Interval> intervals;
    vector<int> visited;
    visited.assign(100007,0);
    intervals.reserve(100007);

    int N,Q,K,S,E,t;

    scanf("%d",&N);//The number of intervals
    for(int i=0; i<N; i++)
    {
        scanf("%d%d",&S,&E);//input start and end intervals
        intervals[i].start = S;
        intervals[i].end = E;
    }

    //sort according to the start
    sort(intervals.begin(),intervals.begin()+N,compareInterval);
//    for(int i=0; i<N; i++)
//    {
//        printf("%d %d\n",intervals[i].start,intervals[i].end);
//    }

    scanf("%d",&Q);//Input the number of groups
    for(int j=0; j<Q; j++)
    {
        scanf("%d",&K);//number of members per group
        int downloads = 0;//number of downloads
        for(int i=0; i<K; i++)
        {
            scanf("%d",&t);//arrival time

            for(int z=0; z<N; z++)
            {
                if(intervals[z].start<=t && t<=intervals[z].end && !visited[z])
                {
                    downloads++;
                    visited[z]=1;
                }
            }
        }
        printf("%d\n",downloads);
        visited.assign(100007,0);
    }

    return 0;
}




















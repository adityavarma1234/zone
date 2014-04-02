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
    freopen("output.txt","w",stdout);
#endif
    pre();
    int T,N,temp,P,K,C;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        scanf("%d%d%d",&N,&K,&C);
        if(N==1)
        {
            P = C;
        }
        else if(K<N)
        {
            P = C + N - K;
        }
        else if(K==N || K%N==0)
        {
            P = C;
        }
        else
        {
            if(C<=N)
            {
                P = C;
            }
            else
            {
                temp = K/N;
                if(temp>=C || (unsigned long long int)temp*N>=C)
                {
                    P = C;
                }
                else
                {
                    P = C + K%N;
                }
            }
        }
        printf("Case #%d: %d\n",i,P);
    }
    return 0;
}




















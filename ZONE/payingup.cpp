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

void pre()
{

}

bool isSubSetSum(int set[],int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0 && sum!=0)
        return false;
    if(set[n-1]>sum)
        return isSubSetSum(set,n-1,sum);
    return isSubSetSum(set,n-1,sum)||isSubSetSum(set,n-1,sum-set[n-1]);
}

int main()
{
    pre();
    int T,N,M;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        int arr[25];
        for(int i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        if(isSubSetSum(arr,N,M))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}





















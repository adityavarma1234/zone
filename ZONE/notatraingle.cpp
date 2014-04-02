/*
Dear future me i am really sorry for what i am doing right now
Hope you can find it in yourself to forgive me
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    pre();
    int N,arr[2005];
    scanf("%d",&N);
    while(N!=0)
    {
        FOR(i,0,N)
            scanf("%d",&arr[i]);
        sort(arr,arr+N);
        int count = 0;
        FORD(i,N-1,1)
        {
            int left,right;
            left = 0;
            right = i-1;
            while(left<right)
            {
                if(arr[left]+arr[right]<arr[i])
                {
                    count += right-left;
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        printf("%d\n",count);
        scanf("%d",&N);
    }
    return 0;
}



















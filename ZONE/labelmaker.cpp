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

unsigned long long n,i,j,l,k,m,t,kk,last;
char arr[66];

void printer(unsigned long long v,unsigned long long kk)
{
    if(kk>0)
    {
        printer(v/l,kk-1);

        printf("%c",arr[v%l]);
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>t;
    for(unsigned long long z=1; z<=t; z++)
    {
        scanf("%s %llu",arr,&m);
        l=strlen(arr);

        k=l;
        n=m;
        kk=1;
        last=k;
        while(n>k)
        {
            n-=k;

            k*=l;
            kk++;
            if(k<last)
                break;
        }
        n--;

        printf("Case #%llu: ",z);
        printer(n,kk);
        printf("\n");
    }

    return 0;

}

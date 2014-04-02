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

int main()
{
    int T,d,remainder,quotient;
    float p,q,a,numerator,denominator;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%f%f%f%d",&a,&p,&q,&D);
        numerator = (p*a*(1-a))+q*a;
        denominator = (1-a)*(1-a);
        quotient = numerator/denominator;
        printf("%d.",quotient);
        remainder = (int)numerator%(int)denominator;
        for(int i=0;i<D;i++)
        {
            remainder *= 10;
            quotient = remainder/denominator;
            printf("%d",quotient);
            remainder = remainder%denominator;
        }
        printf("\n");
    }

    return 0;
}



















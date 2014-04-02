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

using namespace std;

int arr[1000007];

int pre()
{
    int remainder = 103993%33102;
    for(int i=0; i<1000005; i++)
    {
        remainder *= 10;
        quotient = remainder/33102;
        arr[i] = quotient;
        remainder = remainder%denominator;
    }
}

int main()
{
    int T,K;
    scanf("%d",&T;
          while(T--)
{
    scanf("%d",&K);
        if(K==0)
            printf("3\n");
        else
        {

            printf("3.");
            for(int i=0;i<K;i++)
            printf("%d",arr[i]);
            printf("\n");
        }
    }
    return 0;
}


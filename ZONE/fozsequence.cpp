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
    vector<int> arr;
    int cd,a,b,c,d,i;
    int n = arr.size();
    if(n<5)
        return "NO";
    else
    {
        i=0;
        cd = arr[i+1]-arr[i];
        if(cd<1)
        {
            return "NO";
        }
        else
        {
            while(i<n-2 && cd==arr[i+1]-arr[i])
            {
                i++;
            }
            a = i;
            if(a==0)
            {
                return "NO";
            }
            else
            {
                if(a==n-2)
                return "NO";
                else
                cd = arr[i+1]-arr[i];
                if(cd>1)
                    return "NO";
                else
                {
                    while(i<n-1 && cd==arr[i+1]-arr[i])
                    {
                        i++;
                    }
                    b = i;
                    if(a==b)
                    {
                        return "NO";
                    }
                    else
                    {
                        cd = arr[i];
                        while(i<n && cd==arr[i])
                        {
                            i++;
                        }
                        c = i;
                        if(i<n-2){
                        cd = arr[i+1]-arr[i];
                        if(cd<1)
                            return "NO";
                        }
                        else
                        return "NO";
                        while(i<n-1 && cd==arr[i+1]-arr[i])
                            i++;
                        d = i;
                        if(i<=n-2)
                            cd = arr[i+1]-arr[i];
                        else
                        return "NO";
                        while(i<=n-2 && cd==arr[i+1]-arr[i])
                            i++;
                        if(i==n-1)
                            return "YES"
                        else
                            return "NO";
                    }
                }
            }
        }

    }

    return 0;
}



















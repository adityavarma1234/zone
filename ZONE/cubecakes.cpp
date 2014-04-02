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
    int T,N,P;
    for(cin>>T; T>0; T--)
    {
        int i,j,k;
        cin >> N >> P;
        char a[N][N][N],b[N][N][N];
        for(i=0; i<N; i++) for(j=0; j<N; j++) for(k=0; k<N; k++) cin>>a[i][j][k];
//        for(i=0; i<N; i++) for(j=0; j<N; j++) for(k=0; k<N; k++) cout<<a[i][j][k];
//        cout << endl;
        for(i=0; i<N; i++) for(j=0; j<N; j++) for(k=0; k<N; k++) cin>>b[i][j][k];
//        for(i=0; i<N; i++) for(j=0; j<N; j++) for(k=0; k<N; k++) cout<<b[i][j][k];
//        cout << endl;
        int l,count=-1,S=0;
        for(i=N-1;i>=0;i++)
        {

            for(j=N-1;j>=0;j++)
            {
                for(k=N-1;k>=0;k++)
                {
                    if(a[i][j][k]==b[i][j][k])
                    {
                        count++;
                    }
                }
            }
        }
    }
    return 0;
}




















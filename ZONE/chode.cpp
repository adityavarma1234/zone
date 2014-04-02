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

struct SS
{
    char a;
    int rep;
};

bool myfunction(SS c,SS d)
{
     if(c.rep<d.rep) return true;
     else if(c.rep==d.rep) return c.a<d.a;
     else return false;
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
    int T;
    for(scanf("%d",&T); T>0; T--)
    {
        char freq[30];
        int ascii;
        char cipher[150010];
        scanf("%s",freq);
        reverse(freq,freq+strlen(freq));
        char adf = getchar();
        gets(cipher);
        map<char,int>mymap;
        map<char,int>::iterator it;
        int len = strlen(cipher);
        char lower[30];
        for(int i=0; i<26; i++) lower[i]=i+97;
        mymap.clear();
        for(int i=0; i<len; i++)
        {
            if(('A'<=cipher[i] && cipher[i]<='Z') || ('a'<=cipher[i] && cipher[i]<='z'))
            {
                char amy = cipher[i];
                if('A'<=amy && amy<='Z') amy = amy + 32;
                it = mymap.find(amy);
                if(it==mymap.end())
                {
                    mymap.insert(pair<char,int>(amy,1));
                }
                else
                {
                    it->second++;
                }
            }
        }
        vector<SS> v;
        v.clear();
        SS temp;
        for(it=mymap.begin(); it!=mymap.end(); it++)
        {
            temp.a = it->first;
            temp.rep = it->second;
            v.pb(temp);
        }
        sort(v.begin(),v.end(),myfunction);
        vector<SS>::iterator itv;
//        for(itv=v.begin(); itv!=v.end(); itv++)
//        {
//            cout << itv->a << " " << itv->rep << endl;
//        }
        int j=0;
        vector<SS>::reverse_iterator rit;
        for(rit=v.rbegin();rit!=v.rend(); rit++,j++)
        {
            ascii = rit->a;
            lower[ascii-97] = freq[j%26];
        }
        for(int i=0; i<len; i++)
        {
            if('A'<=cipher[i] && cipher[i]<='Z')
            {
                ascii = cipher[i];
                printf("%c",toupper(lower[ascii-65]));
            }
            else if('a'<=cipher[i] && cipher[i]<='z')
            {
                ascii = cipher[i];
                printf("%c",lower[ascii-97]);
            }
            else
            {
                printf("%c",cipher[i]);
            }
        }
        printf("\n");
    }
    return 0;
}




















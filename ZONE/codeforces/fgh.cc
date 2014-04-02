#include<iostream>
#include<string>
using namespace std;
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORL(i,a,b) for(int i=a;i<=b;i++)
#define FORI(i,a,b,inc) for(int i=a;i<b;i=i+inc)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define MAX 1003002
#define pb push_back
#define MOD 1000000007

ULL fact(int a);
int getNumber(string S)
{
    int res;
    int len = S.size();
    ULL ans = fact(len);
    cout << ans<< endl;
    int a[50];
    FOR(i,0,50)
    {
        a[i] = 0;
    }
    FOR(i,0,len)
    {
        int temp = S[i]-'A';
        cout << temp<<endl;
        if(a[temp]==0)
        {
            int count = 0;
            a[temp]=1;
            FOR(j,0,len)
            {
                if(S[j]==S[i])
                {
                    count++;
                }
            }
            ans = ans/fact(count);
            cout << ans<<endl;
        }
    }
    return ans;
}
ULL fact(int a)
{
    ULL ans =1;
    if(a==0)
        return ans;
    FORL(i,1,a)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
 cout <<getNumber("AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ");
 return 0;
}

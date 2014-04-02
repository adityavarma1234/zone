#include<iostream>

using namespace std;

int main()
{
    long long t,n,sum;
    cin >> t;
    while(t--)
    {
        cin>>sum;
        n = 1;
        while(1)
        {
            if(sum<=n*(n+1)/2) break;
            n++;
        }
        int curr = n*(n-1)/2 + 1;
        int a,b;
        if(n%2){ a=n;b=1;
        while(curr<sum)
        {
            a--;
            b++;
            curr++;
        }}
        else
        {
            a = 1;
            b = n;
            while(curr<sum)
            {
                a++;
                b--;
                curr++;
            }
        }
        cout << "TERM " << sum << " IS " << a << "/" << b << endl;
    }
    return 0;
}

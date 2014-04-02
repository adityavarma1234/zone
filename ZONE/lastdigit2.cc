#include<iostream>
#include<cstdio>
using namespace std;
int exp(int a,int b,int mod)
{
    if(b==0)return 1;
    int ans = 1;
    while(b)
    {
        if(b%2)
        ans *= a;
        a *= a;
        b /= 2;
        a %=10;
        ans %=10;
    }
    return ans%10;
}
int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",exp(a,b,10));
    }
    return 0;
}


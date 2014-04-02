#include<stdio.h>

typedef long long int ll;
inline ll max(ll a,ll b)
{
    return a>b?a:b;
}

int main()
{
    //freopen("input.txt","r",stdin);
    ll T,i,index,N,K;
    for(scanf("%lld",&T); T>0; T--)
    {
        ll arr[100007],left[100007],right[100007];
        scanf("%lld%lld",&N,&K);
        for(i=0; i<N; i++)
            scanf("%lld",&arr[i]);
        right[N-1] = arr[N-1];
        ll currMax = arr[N-1];
        for(i = N-2; i >= 0; i--)
        {
            currMax = max(arr[i],arr[i]+currMax);
            right[i] = max(right[i+1], currMax);
        }
        left[0] = arr[0];
        currMax = arr[0];
        for(i = 1; i < N; i++)
        {
            currMax = max(arr[i],arr[i]+currMax);
            left[i] = max(left[i-1], currMax);
        }
        ll maxSum = arr[0];

        ll diff1;
        int index=0;
        for(i = 0; i+K < N-1; i++)
        {
            diff1 = left[i]+right[i+K+1];
            if(diff1 >= maxSum)
            {
                maxSum = diff1;
                index = i;
            }
        }

        maxSum = left[index] + right[index+K+1];
        printf("%lld\n",maxSum);
    }

    return 0;
}



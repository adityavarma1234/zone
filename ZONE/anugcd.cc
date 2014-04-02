#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXARRAY 100005
#define MAXTREE 400005

using namespace std;

typedef long long int lli;

typedef struct segmentTree
{
    vector<lli> data, prefixSum;
} segmentTree;
lli ans,nooftimes;
void buildSegmentTree(int currentNode, int low, int high);
lli querySegmentTree(int currentNode, int low, int high, int a, int b, int sum);

segmentTree S[MAXTREE];
lli arr[MAXARRAY];

lli gcd(lli a,lli b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    ans = -1;
    nooftimes=-1;
    lli n,i,q,l,r,G,newSum;
    scanf("%lld %lld",&n,&q);
    for(i=0; i<n; i++) scanf("%lld",&arr[i]);
    buildSegmentTree(0, 0, n-1);
    for(i=0; i<q; i++)
    {
        scanf("%lld%lld%lld",&G,&l,&r);
        l--,r--;
        newSum = querySegmentTree(0, 0, n-1, l, r, G);
        printf("%lld %lld\n",ans,nooftimes);
        ans = -1;
        nooftimes = -1;
    }
    return 0;
}

void buildSegmentTree(int currentNode, int low, int high)
{
    int i,leftNode, rightNode, mid;
    leftNode = 2*currentNode + 1;
    rightNode = 2*currentNode +2;
    mid = (low+high)/2;

    for(i=low; i<=high; i++)
    {
        S[currentNode].data.push_back(arr[i]);
    }
    sort(S[currentNode].data.begin(), S[currentNode].data.end());
    if(low != high)
    {
        buildSegmentTree(leftNode, low, mid);
        buildSegmentTree(rightNode, mid+1, high);
    }
}

lli querySegmentTree(int currentNode, int low, int high, int a, int b, int G)
{
    int leftNode, rightNode, mid,i;
    leftNode = 2*currentNode + 1;
    rightNode = 2*currentNode +2;
    mid = (low+high)/2;

    if(a>high || b<low) return 0;
    else if(a<=low && b>=high)
    {
        for(i=S[currentNode].data.size()-1; i>=0; i--)
        {
//        cout << S[currentNode].data[i]<< " ";
            if(ans==-1)
            {
                int temp = gcd(G,S[currentNode].data[i]);
                if(temp>1)
                {
                    ans = S[currentNode].data[i];
                    nooftimes = 1;
                }
            }
            else if(S[currentNode].data[i]==ans)
                nooftimes++;
            else if(S[currentNode].data[i]>ans )
            {
                if(gcd(G,S[currentNode].data[i])>1)
                {
                    ans = S[currentNode].data[i];
                    nooftimes = 1;
                }
            }
            else
                return 0;
        }
//        cout << endl;
        return 0;
    }
    return querySegmentTree(leftNode, low, mid, a, b, G) + querySegmentTree(rightNode, mid+1, high, a, b, G);
}

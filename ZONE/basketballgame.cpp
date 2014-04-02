#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,t,T,P,N,M,shotPercentage[35],height[35],name[35][20];
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d %d",&N,&M,&P);
        for(i=0; i<N; i++)
        {
            scanf("%s %d %d",&name[i],&shotPercentage[i],&height[i]);
        }

    }
    return 0;
}

/*
%%%%%%%%%%%%%  AUTHOR %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%  ADITYA %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%   VARMA %%%%%%%%%%%%%%%%%%%
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

inline int min(int a,int b,int c,int d)
{
    a = a>b?b:a;
    a = a>c?c:a;
    a = a>d?d:a;
    return a;
}

int main()
{
    int N,a[4],b[4],c[4],d[4],temp,cmin,jmin;
    scanf("%d",&N);

    for(int i=0; i<4; i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);

    temp = min(a[0],a[1],a[2],a[3]);
    cmin = min(c[0],c[1],c[2],c[3]);
    cmin = cmin>temp?temp:cmin;

    temp = min(b[0],b[1],b[2],b[3]);
    jmin = min(d[0],d[1],d[2],d[3]);
    jmin = jmin>temp?temp:jmin;

    temp = cmin>jmin?jmin:cmin;

    if(2*temp<=N)
    {
        if((a[0]==cmin || b[0]==jmin) && (c[0]==cmin || d[0]==jmin))
        {
            cmin = temp;
            printf("1 %d %d",cmin,N-cmin);
        }
        else if((a[1]==cmin || b[1]==jmin) && (c[1]==cmin || d[1]==jmin))
        {
            cmin = temp;
            printf("2 %d %d",cmin,N-cmin);
        }
        else if((a[2]==cmin || b[2]==jmin) && (c[2]==cmin && d[2]==jmin))
        {
            cmin = temp;
            printf("3 %d %d",cmin,N-cmin);
        }
        else if((a[3]==cmin || b[3]==jmin) && (c[3]==cmin || d[3]==jmin))
        {
            cmin = temp;
            printf("4 %d %d",cmin,N-cmin);
        }
    }
    else
    {
        printf("-1");
    }
    return 0;
}



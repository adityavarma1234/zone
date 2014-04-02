#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>

inline int max(int a,int b)
{
    return a>b?a:b;
}

using namespace std;

int main()
{
    int r,c,matrix[52][52],a[3000],b[3000],c[3000],i,j,k,temp,count,ans,x,y;
    scanf("%d%d",&r,&c);
    count = k = 0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d%d",&matrix[i][j]);
            if(matrix[i][j])
            {
                count++;
                a[k] = i;
                b[k] = j;
                k++;
            }
        }
    }
    if(count<2)
    {
        printf("0\n");
    }
    else if(count==2)
    {
        printf("%d\n",max(abs(a[0]-a[1]),abs(b[0]-b[1]));
    }
    else
    {
        ans = 999999999;
        for(j=0;j<count;j++) c[j]=0;
        for(i=0;i<count;i++)
        {
            c[i]=1;
            x = a[i];
            y = b[i];
            temp = 0;
            for(j=0;j<count;j++)
            {
                if(!c[j])
                {
                    temp += max(abs(x-a[j]),abs(y-b[j]));
                }
            }
            if(temp<ans)
            {
                ans = temp;
            }
            c[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    long long sum,t,x,y,w,z,x1,y1,z1;
    int i,j,k,m=0,n,m1;
    int arr[1001][5];
    char str[15];
//printf("helo ");
    scanf("%lld",&t);
    while(t--)
    {

        m=0;
        scanf("%d%d",&n,&m1);
        for(j=0; j<m1; j++)
        {
            scanf("%s",str);
            if(str[0]=='U')
            {
                scanf("%d%d%d%d",&x,&y,&z,&w);
                for(i=0; i<m; i++)
                {
                    if(arr[i][1]==x && arr[i][2]==y && arr[i][3]==z)
                    {
                        arr[i][4]=w;
                        break;
                    }
                }
                if(i==m)
                {
                    arr[i][1]=x;
                    arr[i][2]=y;
                    arr[i][3]=z;
                    arr[i][4]=w;
                    m++;
                }
//arr[x][y][z]=w;

            }
            else if(str[0]=='Q')
            {
                sum=0;
                scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1);
                for(i=0; i<m; i++)
                {
                    if( x<= arr[i][1] && arr[i][1] <=x1 && y <=arr[i][2] && arr[i][2] <=y1 && z<= arr[i][3] && arr[i][3] <=z1 )
                        sum+=(long long)arr[i][4];
                }
                printf("%lld\n",sum);
            }

        }
    }
    return 0;
}

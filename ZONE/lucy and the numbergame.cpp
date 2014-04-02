#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int T,N,i,j,A[100005],cnt,flag,B[100005];
    char names[100005][6];
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        flag = 0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%s %d",names[i],&A[i]);
            B[i]=A[i];
        }
        sort(A,A+N);
        //8cout << endl;
        for(i=0;i<N;i++)
        {
            cnt = count(A,A+N,A[i]);
            //printf("cnt is %d for %d\n",cnt,A[i]);
            if(cnt==1)
            {
                flag = 1;
                for(j=0;j<N;j++)
                {
                    if(B[j]==A[i])
                    {
                        printf("%s\n",names[j]);
                        break;
                    }

                }
                break;
            }
        }
        if(flag==0)
        {
            printf("Nobody wins.\n");
        }
    }
    return 0;
}

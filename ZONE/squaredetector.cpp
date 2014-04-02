#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T,t,N,length,x1,y1,x2,y2,x3,y3,x4,y4,x,y,count,sqcount;
    char a[22][22],temp;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d",&N);
        length = 0;
        count = 0;
        sqcount = 0;
        for(int i=0; i<N; i++)
        {
            scanf("%s",a[i]);
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(a[i][j]=='#')
                {
                    count++;
                }
            }
        }
        printf("count is %d\n",count);
        if(count==0)
        {
            goto A;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(a[i][j]=='#')
                {
                    //Search bottom from 1->2
                    x1=i;
                    y1=j;
                    while(x1<N && a[x1][y1]=='#')
                    {
                        length++;
                        x1++;
                        sqcount++;
                    }
                    //Search right from 2->3
                    x2 = x1-1;
                    x1=i;//reintialising x1 to i
                    y2 = j;
                    for(int k=0; k<length; k++)
                    {
                        if(a[x2][y2+k]=='#')
                        {
                            sqcount++;
                            continue;

                        }
                        else
                        {
                            goto A;
                        }
                    }
                    //For top from 3->4
                    x3 = x2;
                    y3 = y2 + length - 1;
                    for(int k=0; k<length; k++)
                    {
                        if(a[x3-k][y3]=='#')
                        {
                            sqcount++;
                            continue;
                        }
                        else
                        {
                            goto A;
                        }
                    }
                    //For left from 4->1
                    x4 = x1;
                    y4 = y1 + length - 1;
                    for(int k=0; k<length; k++)
                    {
                        if(a[x4][y4-k]=='#')
                        {
                            sqcount++;
                            continue;
                        }
                        else
                        {
                            goto A;
                        }
                    }
                    sqcount = sqcount-4;
                    //searching inside the square all the elements must be # or else false


                    temp = '#';

                    while(length>3)
                    {
                        //search bottom 1->2
                        for(int k=0; k<length-2; k++)
                        {
                            if(a[x+k][y]==temp)
                            {
                                sqcount++;
                                continue;
                            }
                            else
                            {
                                goto A;
                            }
                        }
                        //search left 2->3
                        x = x2-1;
                        y = y2 + 1;
                        for(int k=0; k<length-2; k++)
                        {
                            if(a[x][y+k]==temp)
                            {
                                sqcount++;
                                continue;
                            }
                            else
                            {
                                goto A;
                            }
                        }
                        //search top 3->4
                        x = x3-1;
                        y = y3 - 1;
                        for(int k=0; k<length-2; k++)
                        {
                            if(a[x-k][y]==temp)
                            {
                                sqcount++;
                                continue;
                            }
                            else
                            {
                                goto A;
                            }
                        }
                        //search left 4->1
                        x = x4+1;
                        y = y4-1;
                        for(int k=0; k<length-2; k++)
                        {
                            if(a[x][y-k]==temp)
                            {
                                sqcount++;
                                continue;
                            }
                            else
                            {
                                goto A;
                            }
                        }
                        sqcount = sqcount-4;
                        length = length - 2;//decrement of length
                        x1++;
                        y1++;
                        x2--;
                        y2++;
                        x3--;
                        y3--;
                        x4++;
                        y4--;
                    }
                    if(length==3)
                    {
                        if(a[x1+1][y1+1]==temp)
                            sqcount++;
                        else
                            goto A;
                    }
                    printf("sqcount is %d\n",sqcount);
                    if(sqcount==count)
                    {
                        goto B;
                    }
                    else
                    {
                        goto A;
                    }
                }
            }
        }
B:
        printf("Case #%d: YES\n",t);
        continue;
A:
        printf("Case #%d: NO\n",t);
    }
    return 0;
}

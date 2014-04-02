#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>

#define MAX(a,b) (a>b)?a:b
using namespace std;

struct SS{
    int x,y;
};

//struct SSComp{
//    bool operator()(SS a,SS b)
//    {
//        if(MAX(abs(a.x-b.x)>))
//    }
//};
int main()
{
    int r,c,a[52][52],count,i,j;
    count = 0;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
            {
                count++;
            }
        }
    }
    if(count<2)
    {
        printf("0\n");
    }
    else
    {
        vector<SS>a;
        SS temp;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(a[i][j])
                {
                    temp.x = i;
                    temp.y = j;
                    a.push_back(temp);
                }
            }
        }
    }
    return 0;
}

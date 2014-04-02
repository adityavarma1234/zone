#include <stdio.h>
#define inchar getchar_unlocked
inline int inIntPos()
{
    int n=0, ch;
    while((ch = inchar()) < '0');
    n=(ch-'0');
    while((ch=inchar())>='0') n=(n<<3)+(n<<1)+(ch-'0');
    return n;
}
#define MAX_N 1010
char a[MAX_N];
char f1[MAX_N];
char f2[MAX_N];
char f3[MAX_N];
int la, lf1,lf2,lf3;

int max(int a,int b)
{
    return a<b?b:a;
}
void update()
{
    int i,n,r;
    n=max(lf1,lf2)+1;
    r=0;
    for(i=0; i<=n; ++i)
    {
        f3[i]=r+f2[i]+f1[i];
        if(f3[i]>=10)
        {
            r=1;
            f3[i]-=10;
        }
        else r=0;
    }
    n=max(lf3,lf2)+1;
    for(i=0; i<=n; ++i)
    {
        f1[i]=f2[i];
        f2[i]=f3[i];
    }
    while(f1[lf1]!=0) ++lf1;
    while(f2[lf2]!=0) ++lf2;
    while(f3[lf3]!=0) ++lf3;
}

int comp()
{
    int i;
    if(lf3<la) return 1;
    if(lf3>la) return -1;

    for(i=la-1; i>=0; --i)
    {
        if(a[i]!=f3[i])
        {
            return a[i]>f3[i] ? 1 : -1;
        }
    }
    return 0;
}

int main()
{
    int t,i,j,ch,res;

    t=inIntPos();
    while(t--)
    {
        la=0;
        while((ch = inchar()) < '0');
        a[la++]=ch-'0';
        while((ch=inchar())>='0') a[la++]=ch-'0';

        if(la==1)
        {
            if(a[0]==0 || a[0]==1 || a[0]==2 || a[0]==3 || a[0]==5 || a[0]==8)
                printf("YES\n");
            else printf("NO\n");
            continue;
        }

        for(i=0; i<=la+1; ++i) f1[i]=f2[i]=f3[i]=0;
        a[la]=0;
        for(i=0,j=la-1; i<j; ++i,--j)
        {
            ch=a[i];
            a[i]=a[j];
            a[j]=ch;
        }
        f1[0]=0;
        lf1=1;
        f2[0]=1;
        lf2=1;
        f3[0]=1;
        lf3=1;
        res=1;
        while(lf3<la || (lf3 == la && (res=comp()) == 1))
        {
            update();
        }
        if(res==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

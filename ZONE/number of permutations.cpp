//Prints all permutations of a string recursively

#include<cstdio>
#include<iostream>

using namespace std;

void swap(char *a,char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *a,int i,int n)
{
    int j;
    if(i==n)
    {
        printf("%s\n",a);
    }
    else
    {
        for(j=i;j<=n;j++)
        {
            swap((a+i),(a+j));
            permute(a,i+1,n);
            swap((a+i),(a+j));//Back track
        }
    }
}

int main()
{
    char a[] = "ABC";
    permute(a,0,2);
    return 0;
}

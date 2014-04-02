#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void swap(char * a,char *b)
{
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void printallpermute(char *a,int i,int n)
{
  if(i==n)
    printf("%s\n",a);
  else
    {
      for(int j=i;j<=n;j++)
	{
	  swap(a+i,a+j);
	  printallpermute(a,i+1,n);
	  swap(a+i,a+j);//backtrack
	}
    }
}
int main()
{
  char a[]="ABCDE";
  printallpermute(a,0,4);
  return 0;
}

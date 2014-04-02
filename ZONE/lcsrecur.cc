#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int lcs(char a[],char b[],int n,int m)
{
  if(n==0 || m==0)
    return 0;
  if(a[n-1] == b[m-1])
    return 1+lcs(a,b,n-1,m-1);
  else 
    return max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}

int main()
{
  char a[]="aditya";
  char b[]="adtiya";
  int n = strlen(a);
  int m = strlen(b);
  cout << a<<endl;
  cout << b<<endl;
  cout << lcs(a,b,n,m)<<endl;
  return 0;
}

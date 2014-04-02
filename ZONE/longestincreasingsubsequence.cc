#include<cstdio>
#include<iostream>

using namespace std;

int _lis(int arr[],int n,int *max)
{
  int res,max_ending_here=1;
  for(int i=1;i<n;i++)
    {
      res = _lis(arr,i,max);
      if(arr[i-1]<arr[n] && res+1>max_ending_here)
	{
	  max_ending_here = res+1;
	}
    }
  if(max_ending_here>*max)
    {
      *max = max_ending_here;
    }
  return max_ending_here;
}

int lis(int arr[],int n)
{
  int max = 1;
  _lis(arr,n,&max);
  return max;
}

int main()
{
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << lis(arr,n)<<endl;
  return 0;
}

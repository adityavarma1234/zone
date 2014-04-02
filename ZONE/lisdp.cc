#include<iostream>

using namespace std;

int lis(int arr[],int n)
{
  int *lis = new int[n];
  //intialising for each element
  for(int i=0;i<n;i++)
    lis[i] = 1;
  
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<i;j++)
	{
	  if(arr[j]<arr[i] && lis[i]<lis[j]+1)
	    {
	      lis[i] = lis[j] + 1;
	    }
	}
    }
  return lis[n-1];
}

int main()
{
  int arr[]={4,3,2,15,6,78,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << lis(arr,n)<<endl;
  return 0;
}

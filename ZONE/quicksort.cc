#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int partition(int arr[],int si,int ei)
{
  int x = arr[ei];
  int i=(si-1);
  
  for(int j=si;j<ei;j++)
    {
      if(arr[j]<=x)
	{
	  i++;
	  swap(arr[i],arr[j]);
	}
    }
  swap(arr[i+1],arr[ei]);
  return i+1;
}

void quickSort(int arr[],int si,int ei)
{
  int mid = (si+ei)/2;
  if(si<ei)
    {
      int pi = partition(arr,si,ei);
      quickSort(arr,si,pi-1);
      quickSort(arr,pi+1,ei);
    }
}

int main()
{
  int arr[]={3,5,4,6,7,8,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr,0,n-1);
  cout << "sorted elements are\n";
  for(int i=0;i<n;i++)
    {
      cout << arr[i]<<" ";
    }
  cout << endl;
  return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

void printLeaders(int arr[],int size)
{
  int max_from_right = arr[size-1];
  int i;

  cout << max_from_right << " ";

  for(i=size-2;i>=0;i--)
    {
      if(max_from_right<arr[i])
	{
	  cout << arr[i] << " ";
	  max_from_right = arr[i];
	}
    }
  cout << endl;
}

int main()
{
  int arr[]={16,17,4,3,5,2};
  printLeaders(arr,6);

  return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

void segregate01(int arr[],int size)
{
  int left=0,right=size-1;

  while(left<right)
    {
      while(arr[left]==0 && left<right)
	left++;
      while(arr[right]==1 && left<right)
	right--;
      if(left<right)
	{
	  arr[left++]=0;
	  arr[right--]=1;
	}
    }
}

int main()
{
  int arr[]={0,1,0,1,1,1};
  int arr_size = 6,i=0;
  segregate01(arr,arr_size);
  cout << "Array after segregation\n";
  for(int i=0;i<6;i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}

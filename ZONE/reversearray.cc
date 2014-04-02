#include<cstdio>
#include<iostream>
using namespace std;
void rvereseArray(int arr[],int start,int end)
{
  int temp;
  while(start<end)
    {
      temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
}

void reverseArrayRecursive(int arr[],int start,int end)
{
  int temp;
  if(start>=end)
    return;
  temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  reverseArrayRecursive(arr,start+1,end-1);
}
void printArray(int arr[],int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      cout << arr[i]<<" ";
    }
  cout << endl;
}

int main()
{
  int arr[]={1,2,3,4,5,6};
  printArray(arr,6);
  reverseArrayRecursive(arr,0,5);
  //  rvereseArray(arr,0,5);
  printf("Reversed array is \n");
  printArray(arr,6);
  return 0;
}

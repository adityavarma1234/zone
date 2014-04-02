#include<iostream>
#include<cstdio>

using namespace std;

int findPivot(int[],int,int);
int binarySearch(int[],int,int,int);

int pivotedBinarySearch(int arr[],int arr_size,int no)
{
    int pivot = findPivot(arr,0,arr_size-1);

    if(pivot==-1)
        return binarySearch(arr,0,arr_size-1,no);
    if(arr[pivot]==no)
        return pivot;
    if(arr[0]<=no)
        return binarySearch(arr,0,pivot-1,no);
    else
        return binarySearch(arr,pivot+1,arr_size-1,no);
}


int findPivot(int arr[],int low,int high)
{
    if(high<low) return -1;
    if(high==low) return low;
    int mid = (low+high)/2;

    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
    if(mid>low && arr[mid]<arr[mid-1])
        return mid-1;
    if(arr[low]>=arr[mid])
        return findPivot(arr,low,mid-1);
    else
        return findPivot(arr,mid+1,high);
}

int binarySearch(int arr[],int low,int high,int no)
{
    if(high<low)
        return -1;
    int mid = (low+high)/2;
    if(no==arr[mid])
        return mid;
    if(no>arr[mid])
        return binarySearch(arr,mid+1,high,no);
    else
        return binarySearch(arr,low,mid-1,no);
}

int main()
{
    int arr1[]= {5,6,7,8,9,10,1,2,3};
    int arr_size=sizeof(arr1)/sizeof(arr1[0]);
    int no=3;
    printf("Index of the element is %d\n",pivotedBinarySearch(arr1,arr_size,no));
    int arr2[]= {3,4,5,1,2};
    arr_size = sizeof(arr2)/sizeof(arr2[0]);
    printf("Index of the element is %d\n",pivotedBinarySearch(arr2,arr_size,no));
    no=4;
    printf("Index of the element is %d\n",pivotedBinarySearch(arr2,arr_size,no));
// Let us search 0 in below array
    int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
    no = 0;
    arr_size = sizeof(arr3)/sizeof(arr3[0]);
    printf("Index of the element is %d\n",  pivotedBinarySearch(arr3, arr_size, no));

    // Let us search 3 in below array
    int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
    no = 3;
    arr_size = sizeof(arr4)/sizeof(arr4[0]);
    printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));

    // Let us search 2 in above array
    no = 2;
    printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));

    // Let us search 3 in below array
    int arr5[] = {1, 2, 3, 4};
    no = 3;
    arr_size = sizeof(arr5)/sizeof(arr5[0]);
    printf("Index of the element is %d\n",  pivotedBinarySearch(arr5, arr_size, no));

    return 0;
}














#include <stdio.h>

//bool hasOnlyOneChild(int pre[], int size)
//{
//    int nextDiff, lastDiff;
//
//    for (int i=0; i<size-1; i++)
//    {
//        nextDiff = pre[i] - pre[i+1];
//        lastDiff = pre[i] - pre[size-1];
//        if (nextDiff*lastDiff < 0)
//            return false;;
//    }
//    return true;
//}

int hasOnlyOneChild(int pre[],int size)
{
    int min,max;
    if(pre[size-1]>pre[size-2])
    {
        max = pre[size-1];
        min = pre[size-2];
    }
    else
    {
        max = pre[size-2];
        min = pre[size-1];
    }
    for(int i=size-3;i>=0;i--)
    {
        if(pre[i]<min)
        {
            min = pre[i];
        }
        else if(pre[i] > max)
        {
            max = pre[i];
        }
        else
        {
            return false;
        }
    }
    return true;
}

// driver program to test above function
int main()
{
    int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild(pre, size) == true )
        printf("Yes");
    else
        printf("No");
    return 0;
}

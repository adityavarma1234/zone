// Program to show segment tree operations like construction, query and update
#include <stdio.h>
#include <math.h>

// A utility function to get the middle index from corner indexes.
unsigned long long int getMid(unsigned long long int s, unsigned long long int e)
{
    return s + (e -s)/2;
}

/* A recursive function to get the sum of values in given range of the array.
The following are parameters for this function.
st --> Pounsigned long long inter to segment tree
index --> Index of current node in the segment tree. Initially 0 is
passed as root is always at index 0
ss & se --> Starting and ending indexes of the segment represented by
current node, i.e., st[index]
qs & qe --> Starting and ending indexes of query range */
unsigned long long int getSumUtil(unsigned long long int *st, unsigned long long int ss, unsigned long long int se, unsigned long long int qs, unsigned long long int qe, unsigned long long int index)
{
// If segment of this node is a part of given range, then return the
// sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];

// If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;

// If a part of this segment overlaps with the given range
    unsigned long long int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

/* A recursive function to update the nodes which have the given index in
their range. The following are parameters
st, index, ss and se are same as getSumUtil()
i --> index of the element to be updated. This index is in input array.
diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(unsigned long long int *st, unsigned long long int ss, unsigned long long int se, unsigned long long int i, unsigned long long int diff, unsigned long long int index)
{
// Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

// If the input index is in range of this node, then update the value
// of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        unsigned long long int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(unsigned long long int arr[], unsigned long long int *st, unsigned long long int n, unsigned long long int i, unsigned long long int new_val)
{
// Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

// Get the difference between new value and old value
    unsigned long long int diff = new_val;

// Update the value in array
    arr[i] += new_val;

// Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

// Return sum of elements in range from index qs (quey start) to
// qe (query end). It mainly uses getSumUtil()
unsigned long long int getSum(unsigned long long int *st, unsigned long long int n, unsigned long long int qs, unsigned long long int qe)
{
// Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
unsigned long long int constructSTUtil(unsigned long long int arr[], unsigned long long int ss, unsigned long long int se, unsigned long long int *st, unsigned long long int si)
{
// If there is one element in array, store it in current node of
// segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

// If there are more than one elements, then recur for left and
// right subtrees and store the sum of values in this node
    unsigned long long int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
             constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
unsigned long long int *constructST(unsigned long long int arr[], unsigned long long int n)
{
// Allocate memory for segment tree
    unsigned long long int x = (unsigned long long int)(ceil(log2(n))); //Height of segment tree
    unsigned long long int max_size = 2*(unsigned long long int)pow(2, x) - 1; //Maximum size of segment tree
    unsigned long long int *st = new unsigned long long int[max_size];

// Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

// Return the constructed segment tree
    return st;
}

// Driver program to test above functions
int main()
{
    unsigned long long int n,Q;
//freopen("input.txt","r",stdin);
    scanf("%llu%llu",&n,&Q);
//prunsigned long long intf("%d %d\n",n,Q);
    long long int arr[n];
    for(unsigned long long int i=0; i<n; i++) scanf("%llu",arr[i]);
// Build segment tree from given array
    unsigned long long int *st = constructST(arr, n);
    for(unsigned long long int i=0; i<Q; i++)
    {
        char a;
        unsigned long long int b,c;
        a = getchar();
        a = getchar();
        scanf("%llu%llu",&b,&c);
//prunsigned long long intf("%c %d %d\n",a,b,c);
        if(a=='S')
            printf("%llu\n", getSum(st, n, b, c));

// Update: set arr[1] = 10 and update corresponding segment
// tree nodes
        else if(a=='G')
            updateValue(arr, st, n, b, c);

// Find sum after the value is updated
        else if(a=='T')
            updateValue(arr, st, n, b, -c);
    }
    return 0;
}

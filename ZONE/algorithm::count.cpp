//returns the number of elements in the range[first,last) that compare to val

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int myInts[] = {10,20,30,30,20,10,10,20};
    vector<int> a(myInts,myInts+8);
    cout << count(a.begin(),a.end(),10);
    return 0;
}

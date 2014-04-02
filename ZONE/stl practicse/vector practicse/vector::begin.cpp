//Returns an iterator pointing to the first element in the vector

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> myVector;
    for(int i=0;i<5;i++) myVector.push_back(i);
    for(vector<int>::iterator it=myVector.begin();it!=myVector.end();it++)
    {
        cout << *it << " ";
    }
    return 0;
}

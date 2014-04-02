#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> myVector;
    for(int i=0;i<5;i++)myVector.push_back(i);
    for(auto it = myVector.cbegin();it!=myVector.cend();it++)
    {
        cout << " " << *it;
    }
    return 0;
}

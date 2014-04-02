//resizes the vector so that it contains specified number of elements

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<=10;i++)a.push_back(i);
    a.resize(5);
    a.resize(8,100);
    a.resize(12);
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

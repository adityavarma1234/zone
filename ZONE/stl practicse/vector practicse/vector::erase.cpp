//removes from vector either a single element or range[first,last)

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<=10;i++)a.push_back(i);
    a.erase(a.begin()+5);
    a.erase(a.begin(),a.begin()+3);
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

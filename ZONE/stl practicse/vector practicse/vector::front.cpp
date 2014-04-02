//returns a reference to the first element in the vector

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<=5;i++) a.push_back(i);
    cout << a.front() << endl;
    a.erase(a.begin());
    cout << a.front();
    return 0;
}

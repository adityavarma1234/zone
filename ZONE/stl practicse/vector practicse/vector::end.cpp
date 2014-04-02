//returns an iterator referring to past_the_end element in the vector

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<5;i++) a.push_back(i);
    for(vector<int>::iterator it = a.begin();it!=a.end();it++)
    {
        cout << *it <<" ";
    }
    return 0;
}

//returns a reverse iterator pointing to the last element in the vector

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<=5;i++) a.push_back(i);
    for(vector<int>::reverse_iterator it = a.rbegin();it!=a.rend();it++)
    {
        cout << *it << " ";
    }
    return 0;
}

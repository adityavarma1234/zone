//returns whether the vector is empty or not

#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
    vector<int> a;
    int sum=0;
    for(int i=0;i<5;i++) a.push_back(i);
    while(!a.empty())
    {
        sum += a.back();
        a.pop_back();
    }
    cout << sum << endl;
    return 0;
}

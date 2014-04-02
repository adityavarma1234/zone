#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    unsigned int i;
    vector<int> first;
    vector<int> second(4,100);
    vector<int> third(second.begin(),second.end());
    vector<int> fourth(third);

    int myInts[] = {5,3,2,41,1};
    vector<int> fifth(myInts,myInts+sizeof(myInts)/sizeof(int));
    for(vector<int>::iterator it = fifth.begin();it!=fifth.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

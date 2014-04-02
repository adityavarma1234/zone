#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> myVector;
    myVector.push_back(10);
    while(myVector.back()!=0)
    {
        myVector.push_back(myVector.back()-1);
    }
    cout << "myvector contains" << endl;
    for(int i=0;i<myVector.size();i++)
    {
        cout << myVector[i] << " ";
    }
    return 0;
}

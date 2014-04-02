//Removes all the elements of the vector

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
    myVector.clear();
    myVector.push_back(81823712);
    myVector.push_back(123);
    cout << endl;
    for(vector<int>::iterator it=myVector.begin();it!=myVector.end();it++)
    {
        cout << *it << " ";
    }
    return 0;
}

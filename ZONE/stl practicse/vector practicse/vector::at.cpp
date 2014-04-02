#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> myVector (7); //Intialises first seven values to zero

    for(int i=0;i<myVector.size();i++)
    {
        myVector.at(i)=i;
    }
    cout << "My vector contains values:"<< endl;
    for(int i=0;i<myVector.size();i++)
    {
        cout << myVector.at(i) <<" ";
    }
    cout << endl;
    for(vector<int>:: iterator it=myVector.begin();it!=myVector.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(vector<int>:: iterator it=myVector.begin();it!=myVector.end();it++)
    {
        cout << *it << " ";
    }
    return 0;
}

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign(7,100);
    vector<int>::iterator it;
    it = first.begin()+1;

    second.assign(it,first.end()-1);

    int myInts[] = {2,5,3,1};

    third.assign(myInts,myInts+4);

    cout << "Size of first:" << first.size() << endl;
    cout << "Size of second" << second.size() << endl;
    cout << "Size of third:" << third.size() << endl;
    for(vector<int>::iterator i=first.begin();i!=first.end();i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    for(vector<int>::iterator j = second.begin();j!=second.end();j++)
    {
        cout << *j << " ";
    }
    cout << endl << third.front();
    return 0;
}

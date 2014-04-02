//request a change in capacity

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int>::size_type sz;
    vector<int> foo;
    cout << "Making foo grow\n";
    sz = foo.capacity();
    for(int i=0;i<=100;i++)
    {
        foo.push_back(i);
        if(sz!=foo.capacity())
        {
            sz = foo.capacity();
            cout << "capacity changed to " << sz << endl;
        }
    }

    vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);
    cout<< "Making foo grow"<< endl;
    for(int i=0;i<100;i++)
    {
        bar.push_back(i);
        if(sz!=bar.capacity())
        {
            sz = bar.capacity();
            cout << "capacity changed to " << sz << endl;
        }
    }
    return 0;
}

//Return the size of the storage space currently allocated for the vector

#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
    vector<int> myVector;
    for(int i=1;i<100;i++)myVector.push_back(i);
    cout << "size of myVector is:" << myVector.size() << endl;
    cout << "Capacity of myVector is:" << myVector.capacity() << endl;
    cout << "Maximum capacity of myVector is :" << myVector.max_size() << endl;
    return 0;
}

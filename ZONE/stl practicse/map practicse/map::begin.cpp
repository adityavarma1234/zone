//returns an iterator pointing to the first element in the map

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    map<char,int>::iterator it;
    mymap['b']=2;
    mymap['a']=1;
    mymap['c']=3;
    for(map<char,int>::iterator it = mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }
    return 0;
}

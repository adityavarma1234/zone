//removes all the elements present in the map container

#include<cstdio>
#include<map>
#include<iostream>

using namespace std;

int main()
{
    map<char,int>mymap;
    mymap['c']=3;
    mymap['a']=1;
    mymap['b']=2;
    for(map<char,int>::iterator it=mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }
    mymap.clear();
    mymap['d']=1234;
    mymap['f']=345;
    cout << "After clearing my map we get" << endl;
    for(map<char,int>::iterator it=mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }
    return 0;
}

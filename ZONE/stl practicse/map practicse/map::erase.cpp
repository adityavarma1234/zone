//removes from the map either a single element or a range of elements[first,last)

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    map<char,int>::iterator it;
    it = mymap.find('b');
    mymap.erase(it);//erasing by iterator
    mymap.erase('c');//erasing by key value
    it = mymap.find('e');
    mymap.erase(it,mymap.end());
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }
    return 0;
}

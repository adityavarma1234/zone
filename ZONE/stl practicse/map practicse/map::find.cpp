//returns an iterator to the element if found or else returns map::end

#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<char,int>mymap;
    map<char,int>::iterator it;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it = mymap.find('b');
    mymap.erase(it);
    mymap.erase(mymap.find('f'));

    cout << "Elements in map " << endl;
    cout << "a=>" << mymap.find('a')->second << endl;
    cout << "b=>" << mymap.find('c')->second << endl;

    return 0;
}

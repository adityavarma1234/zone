//extends the container by adding new elements

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    mymap.insert(pair<char,int>('a',100));
    mymap.insert(pair<char,int>('z',200));

    pair<map<char,int>::iterator,bool>ret;
    ret = mymap.insert(pair<char,int>('z',500));

    if(ret.second==false)
    {
        cout << "element z already exists\n";
        cout << "with a value of "<< ret.first->second << endl;
    }

    map<char,int>::iterator it = mymap.begin();
    mymap.insert(it,pair<char,int>('b',300));
    mymap.insert(it,pair<char,int>('c',400));

    map<char,int>anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    cout << "map contains" << endl;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }

    cout << "another map contains "<< endl;
    for(it=anothermap.begin();it!=anothermap.end();it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }

    return 0;
}

//returns a copy of the comparison object that is used by the container to compare the keys

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    cout << "mymap contains\n";

    char highest = mymap.rbegin()->first;

    map<char,int>::iterator it = mymap.begin();
    do{

        cout << it->first << "=>" << it->second << endl;

    }while(mycomp((*it++).first,highest));
    return 0;
}

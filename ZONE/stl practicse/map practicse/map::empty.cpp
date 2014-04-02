//returns whether a map is empty or not (its size is zero or not)

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    mymap['a']=10;
    mymap['c']=30;
    mymap['b']=20;
    while(!mymap.empty())
    {
        cout << mymap.begin()->first << "=>" << mymap.begin()->second << endl;
        mymap.erase(mymap.begin());
    }
    return 0;
}

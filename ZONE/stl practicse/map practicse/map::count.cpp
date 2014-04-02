//returns 1 if key is present or else 0

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<char,int>mymap;
    mymap['a']=1;
    mymap['c']=2;
    mymap['d']=3;
    mymap['f']=4;
    char c;
    for(c='a';c<'g';c++)
    {
        cout << c << " is ";
        if(mymap.count(c))
        {
            cout << "present in the map" << endl;
        }
        else
        {
            cout << "not present in the map" << endl;
        }
    }
    return 0;
}

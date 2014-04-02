//returns an iterator pointing to the first element in the container
//whose key is not considered to go before k (i,e, either it is equivalent or goes after)

#include<map>
#include<iostream>

using namespace std;

int main()
{
    map<char,int>mymap;
    map<char,int>::iterator itlow,itup;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;

    itlow = mymap.lower_bound('b');//itlow points to b
    itup = mymap.upper_bound('d');//itup point to e (!d)

    mymap.erase(itlow,itup);//erases from [itlow,itup)

    for(map<char,int>::iterator it=mymap.begin();it!=mymap.end();it++)
    {
        cout << it->first   << "=>" << it->second << endl;
    }
    return 0;
}

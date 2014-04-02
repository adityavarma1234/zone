#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string replaceSpace(string a)
{
    string result;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==' ')
            result += "%20";
        else
            result += a[i];
    }
    return result;
}

int main()
{
    cout << replaceSpace("i am bored\n");
    return 0;
}

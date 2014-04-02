#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool anagram(string a,string b)
{
    if(a.length()!=b.length())
        return false;
    int lettersa[300],lettersb[300];
    for(int i=0;i<300;i++)
        lettersa[i] = lettersb[i] = 0;
    for(int i=0;i<a.length();i++)
    {
        lettersa[a[i]]++;
    }
    for(int i=0;i<b.length();i++)
    {
        lettersb[b[i]]++;
    }
    bool flag = true;
    for(int i=0;i<300;i++)
    {
        if(lettersa[i]!=lettersb[i])
        {
            flag = false;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}

int main()
{
    string a="dogw ";
    string b="godw ";
    if(anagram(a,b))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

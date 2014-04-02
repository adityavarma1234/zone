#include<iostream>
#include<cstdio>

using namespace std;

void reverse(char *str)
{
    char *end = str;
    char tmp;
    if(str)
    {
        while(*end)
        {
            end++;
        }
        end--;
        while(str<end)
        {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    char a[] = "aditya";
    reverse(a);
    cout << a;
    return 0;
}

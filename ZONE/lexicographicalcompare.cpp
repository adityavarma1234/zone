#include<iostream>
#include<algorithm>
#include<cctype>
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

using namespace std;

int main()
{
    char l[] = "L+";
    char L[] = "L-";
    char r[] = "R+";
    char R[] = "R-";
    cout << lexicographical_compare(l,l+2,R,R+2);
}

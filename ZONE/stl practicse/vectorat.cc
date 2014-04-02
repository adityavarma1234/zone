#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  vector<int>v(10);//10 intialsied zeroes
  for(int i=0;i<v.size();i++)
    v.at(i) = i;
  for(unsigned i=0;i<v.size();i++)
    cout << v.at(i) << endl;
  return 0;
}

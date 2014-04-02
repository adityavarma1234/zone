#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  vector<int>v;
  for(int i=0;i<100;i++)
    v.push_back(i);
  sort(v.rbegin(),v.rend());
  for(int i=0;i<10;i++)
    cout << v[i]<< endl;
  return 0;
}

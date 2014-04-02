#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  vector<int>first;
  vector<int>second;
  vector<int>third;
  first.assign(7,100);
  vector<int>::iterator it;
  it = first.begin()+1;
  second.assign(it,first.end()-1);
  int myints[]={213,213,43};
  third.assign(myints,myints+3);
  cout << first.size()<<endl;
  cout << second.size()<<endl;
  cout << third.size()<<endl;
  return 0;
}

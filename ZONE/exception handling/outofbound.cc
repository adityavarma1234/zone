#include<iostream>

using namespace std;

const int ARR_SIZE = 10;

class array
{
private:
  int arr[ARR_SIZE];
public:
  class RANGE{};
  int & operator[](int i)
  {
    if(i<0 || i>=ARR_SIZE)
      {
	throw RANGE();
      }
    return arr[i];
  }
};

int main()
{
  array a;
  cout << "MAXIMUM array size allowed = " << ARR_SIZE << endl;
  try
    {
      cout << "Trying to refer a[1]......";
      a[1]=10;
      cout << "succeeded"<<endl;
      cout << "Trying to refer a[15]...";
      a[15]=10;
      cout << "succeded"<<endl;
    }
  catch(array::RANGE)
    {
      cout << "Out of range in Array Reference "<<endl;
    }
  return 0;
}

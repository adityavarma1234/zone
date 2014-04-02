#include<iostream>

using namespace std;

class number
{
private:
  int num;
public:
  void read()
  {
    cin >> num;
  }
  class DIVIDE{};
  int div(number num2)
  {
    if(num2.num==0)
      {
	throw DIVIDE();
      }
    else
      return num / num2.num;
  }
};

int main()
{
  number  num1,num2;
  int result;
  cout << "Enter Numeber 1: ";
  num1.read();
  cout << "Enter Number 2: ";
  num2.read();
  try
    {
      cout << "trying division operation...";
      result = num1.div(num2);
      cout << "succeeded"<<endl;
    }
  catch(number::DIVIDE)
    {
      cout << "failed"<<endl;
      cout << "Exception: Divide-By-Zero"<<endl;
      return 1;
    }
  cout << "num1/num2 = "<<result<<endl;
  return 0;
}

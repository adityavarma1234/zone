#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

bool mycomp (string c1, string c2,int len)
  {

    for(int i=0;i<len;i++)
      {
	int a,b;
	a = c1[i];
	b=c2[i];
	if(a>b)
	  return false;
	else if(a<b)return true;
      }
    return true;
  }
    string getMin(string S, int L)
    {
        string res=S;
	string temp = S;
	sort(res.begin(),res.begin()+L);
	cout << "result "<<res<<endl;
	for(int i=1;i<S.length()-L;i++)
	  {
	    sort(temp.begin()+i,temp.begin()+i+L);
	    cout << "temp after sorting "<<temp<<endl;
	    cout << "my comp is "<<mycomp(temp,res,temp.length())<<endl;
	    if(mycomp(temp,res,temp.length())){
	      res = temp;
	      cout << "result changed to "<< res<<endl;
	    }
	       temp = S;
	       cout << "temp changed to "<< temp<< endl;
	  }
	cout << "final result is "<<res<<endl;

        return res;
    }
    
int main()
{
  string a="ESPRIT";
  cout <<endl;
  getMin(a,3);
  return 0;
}

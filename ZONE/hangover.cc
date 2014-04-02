#include <iostream>
#include<cmath>
using namespace std;

int main() {
	double a,n;
	int count;
	cin >> a;
	while(a)
	{
		n = 2;
		count = 0;
		double sum = 0;
		while(1)
		{
			sum += 1/n;
			count++;n++;
			if(sum>=a) break;
		}
		cout << count << " card(s)" << endl;
		cin >> a;
	}
	return 0;
}

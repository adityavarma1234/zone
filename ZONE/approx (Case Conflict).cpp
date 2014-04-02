#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,i,n,tqi,tqn;

int main (int argc, char * const argv[]) {	
	scanf("%d",&tqn);  // total number of the test cases
	for(tqi=0;tqi<tqn;tqi++){
		scanf("%d",&n);
		a=103993,b=33102;a=(a%b)*10;
		if(n==0)printf("3");else printf("3."); // consider the special case when n=0
		for(i=1;i<=n;i++,a=(a%b)*10)putchar(a/b+'0'); // output the answer; standard approach
		puts(""); // and put a newline
	}
    return 0;
}

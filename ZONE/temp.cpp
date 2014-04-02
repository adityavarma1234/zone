#include<cstdio>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    char a[10][10][10],b[10][10][10];
    int i,j,k,N,P,T;
    for(cin>>T;T>0;T--){
    cin >> N >> P;
    for(i=0;i<N;i++) for(j=0;j<N;j++) for(k=0;k<N;k++) cin>>a[i][j][k];
    for(i=0;i<N;i++) for(j=0;j<N;j++) for(k=0;k<N;k++) cout<<a[i][j][k];
//    cin >> N;
    cout << endl;
    for(i=0;i<N;i++) for(j=0;j<N;j++) for(k=0;k<N;k++) cin>>b[i][j][k];
    for(i=0;i<N;i++) for(j=0;j<N;j++) for(k=0;k<N;k++) cout<<b[i][j][k];
    cout << endl;
    }
    return 0;
}

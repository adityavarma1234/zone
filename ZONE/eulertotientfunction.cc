/*********************************************************
                                                
         mmmm      #          mmmm   mmmm   mmmm 
  mmm   m"  "m  mmm#   mmm   "   "# "   "# "   "#
 #"  "  #  m # #" "#  #"  #      m"     m"     m"
 #      #    # #   #  #""""    m"     m"     m"  
 "#mm"   #mm#  "#m##  "#mm"  m#mmmm m#mmmm m#mmmm
                                                 
*************************************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

//defines
#define MOD 1000000009LL
#define SIZE 100000009
#define MAXX 100000009
#define LL long long
#define ULL unsigned long long
#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define SD(x) inp(x)
#define SD2(n,m) SD(n);SD(m)
#define SLL(n) scanf("%lld",&n)
#define SLU(n) scanf("%llu",&n)
#define SS(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(__typeof(n) i=0;i<(n);i++)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<(b);++i)
#define FORE(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b,d) for(__typeof(b) i=(a);i<(b);i+=(d))
#define FORR(i,n,e) for(__typeof(n) i=(n);i>=(e);--i)
#define FORRD(i,n,e,d) for(__typeof(n) i=(n);i>=(e);i-=(d))
#define REP_IT(it,m) for(it=m.begin();it!=m.end();it++)
#define FORI(it,s) for(__typeof((s).begin()) (it)=(s).begin();(it)!=(s).end();(it)++)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(a,b) memset(a,b,sizeof(a))
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define checkbit(n,b) (((n)>>(b))&1)
#define PB push_back
#define MP make_pair
#define XX first
#define YY second
#define db(...) {}
#define dbt(...) {}
#define TEST int T;cin>>T;FORE(t,1,T)
#define getcx getchar_unlocked
//defines

template<typename T>inline void inp(T &n)
{
  n=0;
  int ch=getcx();
  int sign=1;
  while(ch<'0'||ch>'9')
    {
      if(ch=='-')sign=-1;
      ch=getcx();
    }
  while(ch>='0'&&ch<='9')
    {
      n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
    }
  n=n*sign;
}

using namespace std;
const int n = 1000006;
double _st;
bool primes[n];
vector<LL>v;
vector<LL>::iterator it;
void sieve()
{
  int len = n;
  FOR(i,2,len)
    {
      if(primes[i]==false)
	{
	  v.PB(i);
	  FORD(j,2*i,1000006,i)
	    {
	      primes[j]=true;; 
	    }
	}
    }
}
void pre()
{
  sieve();
}
void totient(LL N)
{
  if(N==1)
    {
      cout << 1 << endl;
      return;
    }
  if(primes[N]==false)
    {
    cout << N-1 << endl;
    return ;
    }
  LL temp = N;
  REP(i,v.size())
    {
      if(v[i]*v[i]>N)
	{
	  cout << temp<<endl;
	  return;
	}
      if(N%v[i]==0)
	{
	  temp -=temp/v[i];
	}
    }
}
void doThis()
{ 
  
}
void end(){
#ifdef dexter
  fprintf(stdout,"\nTIME: %.3lf sec\n",(double)(clock()-_st)/(CLOCKS_PER_SEC));
#endif
}
int main()
{
#ifdef dexter
  freopen("/home/dexter/Desktop/ZONE/inout/input.txt","r",stdin);
  freopen("/home/dexter/Desktop/ZONE/inout/output.txt","w",stdout);
  _st = clock();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  TEST
    {
      LL N;
      cin>>N;
      totient(N);
    }
  end();
  return 0;
}

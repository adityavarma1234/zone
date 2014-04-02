/*
  If it were easy then everyone would do it
*/

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
#define MOD 1000000007LL
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
#define TEST int T;SD(T);FORE(t,1,T)
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

void pre()
{

}
void doThis()
{ 

}
 
LL lock[60005], furik,rubik,furik1,rubik1,rubik2;
LL degree[60000];

class Graph
{
    LL V;  
    list<LL> *adj;  
    LL DFSUtil(LL v, bool visited[]); 
public:
    Graph(LL V);
    void addEdge(LL v, LL w);
    void DFS(LL v);    
};
 
Graph::Graph(LL V)
{
    this->V = V;
    adj = new list<LL>[V];
}
 
void Graph::addEdge(LL v, LL w)
{
    adj[v].push_back(w);
}
LL Graph::DFSUtil(LL v, bool visited[])
{
  LL x=0,count =0;
  visited[v] = true;
  list<LL>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
      if(!visited[*i])
       	{
       	  x = DFSUtil(*i,visited);
       	  if(x==1)
      	    count++;
	}
    }
  if(lock[v]==1)
    furik++;
  rubik++;
  if((lock[v]==0 && degree[v]<=count+1) || (lock[v]==1 && degree[v]==count))
    {
      rubik1++;
      return 1;
    }
  else
    return 0;
}

void Graph::DFS(LL v)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int i=0;i<V;i++) 
      {
	furik=0;
	rubik=0;
	rubik1 =0;
      if(visited[i]==false && lock[i])
	{
	  
	  DFSUtil(i, visited);
	  furik1 += (furik*(furik-1))/2;
	  rubik2 += rubik - rubik1;
	}
      }
}
 

int main()
{
#ifdef dexter
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false);
  pre();
  LL N,M;
  SD2(N,M);
  REP(i,N)
    {
      SD(lock[i]);
    }
  Graph g(N);
  REP(i,M)
    {
      LL u,v;
      SD2(u,v);
      u--;v--;
      degree[u]++;
      degree[v]++;
      g.addEdge(u,v);
      g.addEdge(v,u);
    }
  g.DFS(0);
  cout << furik1 <<" "<<rubik2<<endl;
  return 0;
}

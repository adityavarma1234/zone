#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V;
  list<int> *adj;
  void BFSUtil(int v,bool visited[]);
public:
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            BFSUtil(i,visited);
        }
    }
}

void Graph::BFSUtil(int v,bool visited[])
{
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);
    list<int>::iterator i;
    while(!queue.empty())
    {
        int s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout << "Following is the BFS\n";
    g.BFS(2);
    return 0;
}











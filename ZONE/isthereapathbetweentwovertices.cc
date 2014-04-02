#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    bool isPath(int u,int v);
    void addEdge(int v,int w);
    Graph(int V);
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

bool Graph::isPath(int u,int v)
{
    if(u==v)
    {
        return true;
    }
    bool *visited;
    visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    list<int>::iterator i;
    visited[u] = true;
    queue.push_back(u);
    while(!queue.empty())
    {
        int s = queue.front();
        queue.pop_front();
        for(i=queue.begin();i!=queue.end();i++)
        {
            if(*i==v)
            {
                return true;
            }
            if(visited[*i]==false)
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
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

    int u = 3,v=1;
    if(g.isPath(u,v))
        cout << "\n There is a path between " << u << " " << v << endl;
    else
        cout << "\n Not reachable\n";
    return 0;
}
























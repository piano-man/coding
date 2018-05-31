//detect cycle in directed graph
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
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

bool dfs(bool *vis,int s,list<int> *adj)
{
    vis[s]=true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(vis[*i]==false)
        {
            dfs(vis,*i,adj);
        }
        else{
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        cout<<g->isCyclic()<<endl;
    }
}
bool Graph :: isCyclic()
{
    bool *vis = new bool[V];
    int i;
    for(i=0;i<V;i++)
    {
        vis[i]=false;
    }
    return dfs(vis,0,adj);
}
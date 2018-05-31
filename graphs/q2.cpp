//bfs traversal
//can't find error
#include<bits/stdc++.h>
using namespace std;
bool vis[1001];
vector<int> g[1001];
void bfs(int s,vector<int> adj[],bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        bfs(1,g,vis);
        cout<<endl;
    }
}
void bfs(int s,vector<int> adj[],bool vis[])
{
    list<int> q;
    vis[s]=true;
    q.push_back(s);
    while(!q.empty())
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop_front();
        int l = adj[s].size();
        int i;
        for(i=0;i<l;i++)
        {
            if(vis[adj[temp][i]]==false)
            {
               vis[adj[temp][i]]=true;
                q.push_back(adj[temp][i]);
            }
        }        
    }

}
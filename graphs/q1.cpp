//depth first traversal
#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int> g[],bool vis[]);
void dfsUtil()
{

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        bool vis[100001];
        vector<int> g[100001];
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,g,vis);
        cout<<endl;
    }
}
void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout << s << " ";
    int l = g[s].size();
    int i;
    for(i=0;i<l;i++)
    {
        if(vis[g[s][i]]==false)
        {
            dfs(g[s][i],g,vis);
        }
    }
 
}
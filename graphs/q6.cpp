//implementing djikstra
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   int t;
int V;
   cin>>t;
   while(t--){
cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}
int extract_min(int *dist,bool *mindist,int V)
{
    int i,min=INT_MAX,index;
    for(i=0;i<V;i++)
    {
        if(dist[i]<=min&&mindist[i]==false)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[MAX][MAX], int s,int V)
{
    int parent[V];
    int dist[V];
    bool mindist[V];
    int i;
    for(i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
        mindist[i]=false;
    }
    dist[s] = 0;
    parent[s] = s;
    for(i=0;i<V;i++)
    {
        int temp = extract_min(dist,mindist,V);
        if(dist[temp]==INT_MAX)
        {
            break;
        }
        mindist[temp] = true;
        int j;
        for(j=0;j<V;j++)
        {
            if(graph[temp][j]!=0&&mindist[j]==false&&dist[temp]+graph[temp][j]<dist[j])
            {
                dist[j]=dist[temp]+graph[temp][j];
            }
        }
    }
    for(i=0;i<V;i++)
    {
        cout << dist[i] << " ";
    }
}
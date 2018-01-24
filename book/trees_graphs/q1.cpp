//route between two nodes
#include<iostream>
#include<list>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
int isReachable(int s,int d,int v,vector<vector<int> >adj)
{
    //cout<<"here";
    //cout<<adj[1][0];
    if(s==d)
        return true;
    bool *visited = new bool[v];
    int i,k;
    int j = 0;
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }
    list<int> queue;
    queue.push_back(s);
    while(!queue.empty())
    {
        int curr = queue.front();
        queue.pop_front();
        visited[curr]=true;
        int l = adj[curr].size();
        for(k=0;k<l;k++)
        {
            if(adj[curr][k]==d)
            {
                return true;
            }
            if(visited[adj[curr][k]]==false)
            {
                queue.push_back(adj[curr][k]);
            }
        }
        
    }
    return false;
}
int main()
{
    //adjacency list creation
    vector< vector<int> > adj;
    int i;
    int v;
    cin >> v;
    for(i=0;i<v;i++)
    {
        adj.push_back(vector<int>());
    }
    for(i=0;i<v;i++)
    {
        char temp;
        do
        {
            int c;
            scanf("%d%c",&c,&temp);
            adj[i].push_back(c); 
        }while(temp!='\n');
  
    }
    int source,dest;
    cin >> source;
    //cout<< "here2";
    cin >> dest;
    //cout << "here";
    int f =  isReachable(source,dest,v,adj);
    cout << f;

} 
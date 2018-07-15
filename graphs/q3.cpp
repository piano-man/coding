//topological sort
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
int main()
{
int T;
cin>>T;
while(T--)
{
    memset(graph,0,sizeof graph);
    int N,E;
    cin>>E>>N;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int *res = topoSort(graph,N);
    bool valid =true;
    for(int i=0;i<N;i++)
    {
        int n=graph[res[i]].size();
        for(int j=0;j<graph[res[i]].size();j++)
        {
            for(int k=i+1;k<N;k++)
            {
                if(res[k]==graph[res[i] ] [j] )
                    n--;
            }
        }
        if(n!=0)
        {
            valid =false;
            break;
        }
    }
    if(valid==false)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}
}

void toposort_util(vector<int> graph[],int i,bool *visited,stack<int> &Stack)
{
    visited[i] = true;
    int l = graph[i].size();
    int j;
    for(j=0;j<l;j++)
    {
        if(visited[graph[i][j]]==false)
        {
            toposort_util(graph,j,visited,Stack);
        }
    }
    Stack.push(i);
}
int * topoSort(vector<int> graph[], int N)
{
   bool visited[N] = { false };
   int *result = (int *)malloc(N*sizeof(int));
   stack<int> Stack;
   int i;
   for(i=0;i<N;i++)
   {
       if(visited[i]==false)
       {
           toposort_util(graph,i,visited,Stack);
       }
   }
   for(i=0;i<N;i++)
   {
       result[i] = Stack.top();
       Stack.pop();
   }
   return result;
   
}
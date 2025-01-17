//floyd warshall
#include<bits/stdc++.h>
#define V 4
#define INF 99999
using namespace std;

void floydWarshall(int graph[V][V])
{
    int dist[V][V];
    int i,j,k;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=INT_MAX;
            }
        }
    }
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}
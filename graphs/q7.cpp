//prims MST
//try O(ElogV) approach
#include <stdio.h>
#include <limits.h>
 
// Number of vertices in the graph
#define V 5

int extract_min(int *dist,bool *mstSet)
{
    int min = INT_MAX ,vertex;
    int i;
    for(i=0;i<V;i++)
    {
        if(dist[i]<= min &&mstSet[i]==false)
        {
            min = dist[i];
            vertex = i;
        }
    }
    return vertex;
}
void printUtil(int *parent,int graph[V][V])
{
    printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
void printMST(int graph[V][V])
{
    bool mstSet[V];
    int dist[V];
    int parent[V];
    int i,j;
    for(i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        mstSet[i] = false;
    }
    dist[0] = 0;
    parent[0] = -1;
    for(i=0;i<V;i++)
    {
        int temp = extract_min(dist,mstSet);
        mstSet[temp] = true;
        for(j=0;j<V;j++)
        {
            if(graph[temp][j]!=0&&mstSet[j]==false&&graph[temp][j]<dist[j])
            {
                parent[j]=temp;
                dist[j] = graph[temp][j];
            }
        }
    }
    printUtil(parent,graph);

}
int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    printMST(graph);
 
    return 0;
}
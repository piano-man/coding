//finding number of islands
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int findIslands(int A[MAX][MAX], int N, int M);
int main()
{
    // your code goes here
    int T;
    cin >> T;
    int A[MAX][MAX];
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        memset(A, 0, sizeof A);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}
void dfs(int i, int j, int vis[MAX][MAX], int A[MAX][MAX])
{
    vis[i][j] = 1;
    int adjx, adjy;
    adjx = i + 1;
    adjy = j + 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i + 1;
    adjy = j;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i;
    adjy = j + 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i - 1;
    adjy = j - 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i;
    adjy = j - 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i - 1;
    adjy = j;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i - 1;
    adjy = j + 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {
        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
    adjx = i + 1;
    adjy = j - 1;
    if (adjx >= 0 && adjx < MAX && adjy >= 0 && adjy < MAX)
    {

        if (A[adjx][adjy] == 1 && vis[adjx][adjy] == 0)
        {
            dfs(adjx, adjy, vis, A);
        }
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    int i, j;
    int vis[MAX][MAX];
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            vis[i][j] = 0;
        }
    }
    int count = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (A[i][j] == 1 && vis[i][j] == 0)
            {
                
                count++;
                dfs(i, j, vis, A);
            }
        }
    }
    return count;
}
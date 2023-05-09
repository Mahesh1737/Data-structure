#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Adjacency matrix to store the graph
int adj[MAX][MAX];
// Function to add an edge to the graph
void add_edge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to perform DFS traversal of the graph
void dfs(int start, int visited[], int n)
{
    int i;
    visited[start] = 1;
    printf("%d ", start + 1);
    for (i = 0; i < n; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            dfs(i, visited, n);
        }
    }
}

int main()
{
    int n, e, u, v, i, start, j;
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (i = 0; i < e; i++)
    {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        add_edge(u - 1, v - 1);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    dfs(start - 1, visited, n);

    return 0;
}



/*

Output :

PS D:\backup -6-1-2023\Users\dell\.vscode\Adjacency matrix> cd "d:\backup -6-1-2023\Users\dell\.vscode\Adjacency matrix\" ; if ($?) { gcc practice.c -o practice } ; if ($?) { .\practice }
Enter the number of vertices : 6
Enter the number of edges : 7
Enter the  0 edge from vert to  vert (v1 v2) : 1 2
Enter the  1 edge from vert to  vert (v1 v2) : 1 4
Enter the  2 edge from vert to  vert (v1 v2) : 4 2
Enter the  3 edge from vert to  vert (v1 v2) : 2 5
Enter the  4 edge from vert to  vert (v1 v2) : 5 4
Enter the  5 edge from vert to  vert (v1 v2) : 3 5
Enter the  6 edge from vert to  vert (v1 v2) : 3 6
Adjacency matrix :
 0  1  0  1  0  0
 0  0  0  0  1  0
 0  0  0  0  1  1
 0  1  0  0  0  0
 0  0  0  1  0  0
 0  0  0  0  0  0

Enter the starting vertices  : 1
DFS Traversal :  1  2  5  4

*/
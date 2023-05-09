#include <stdio.h>
#define MAX 100

int adj[MAX][MAX],vert;                 // Adjacency matrix to store the graph
//int in[MAX], out[MAX], total[MAX]; // In-degree, out-degree and total degree of vertices
int visit[MAX];                    // Visit array to keep track of visited vertices during DFS
int stack[MAX];                    // Stack to store vertices in topological order
int top = -1;                      // Top index of the stack

void dfs(int v1)
{
   int i;
   visit[v1] = 1;

   for (i = 1; i <= vert; i++)
   {
      // If there is an edge from v1 to i and i has not been visited yet, recursively call DFS on i
      if (adj[v1][i] && !visit[i])
      {
         dfs(i);
      }
   }

   // Push the vertex to the stack once all its adjacent vertices have been visited
   stack[++top] = v1;
}

void topological_sort(int vert)
{
   int i;

   // Call DFS on all unvisited vertices
   for (i = 1; i <= vert; i++)
   {
      if (!visit[i])
      {
         dfs(i);
      }
   }

   printf("Topological order of the vertices: ");

   // Pop vertices from the stack to print them in topological order
   while (top != -1)
   {
      printf("%d ", stack[top--]);
   }
}

int main()
{
   int e, v1, v2, i, j;

   printf("Enter the number of vertices: ");
   scanf("%d", &vert);

   printf("Enter the number of edges: ");
   scanf("%d", &e);

   // Initialize the adjacency matrix
   for (i = 1; i <= vert; i++)
   {
      for (j = 1; j <= vert; j++)
      {
         adj[i][j] = 0;
      }
   }

   // Create the adjacency matrix by taking input for each edge
   for (i = 1; i <= e; i++)
   {
      printf("Enter the start and end vertices of edge %d: ", i);
      scanf("%d %d", &v1, &v2);

      adj[v1][v2] = 1;
   }
   printf("Adjacency matrix :\n");
   printf("  ");
   for (i=1;i<=vert;i++)
   {
      printf(" %d ",i);
   }
   for (i=1;i<=vert;i++)
   {
      printf("\n");
      printf("%d ",i);
      for (j=1;j<=vert;j++)
      {
         printf(" %d ",adj[i][j]);
      }
      //printf("\n");
   }

   printf("\n");
   topological_sort(vert);
   
   return 0;
}


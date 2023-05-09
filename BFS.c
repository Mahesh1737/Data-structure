#include <stdio.h>
#define max 100

int adj[max][max];
int visited[max];
int queue[max],f=-1,r=-1;

void BFS(int start, int n)
{
	int i;
	visited[start]=1;
	queue[r++]=start;
	while (f != r)
	{
		start=queue[f++];
		printf(" %d ",start+1);
		for (i=0;i<n;i++)
		{
			if(adj[start][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				queue[r++]=i;
			}
		}
	}

}

int main()
{
	int i,j,v1,v2,vert,edge,start;
	printf("Enter the number of vertices : ");
	scanf("%d",&vert);
	printf("Enter the number of edges : ");
	scanf("%d",&edge);
	for (i=0;i<vert;i++)
	{
		for (j=0;j<edge;j++)
		{
			adj[i][j]=0;
		}
	}
	for (i=0;i<edge;i++)
	{
		printf("Enter the edge from vert to vert (v1 v2) : ");
		scanf("%d %d",&v1,&v2);
		adj[v1-1][v2-1]=1;
	}
	printf("Adjacency Matrix : \n");
	printf("  ");
	for (i=0;i<vert;i++)
	{
		printf(" %d ",i+1);
	}
	printf("\n");
	for (i=0;i<vert;i++)
	{
		printf("%d ",i+1);
		for (j=0;j<vert;j++)
		{
			printf(" %d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("enter the starting vertices  : ");
	scanf("%d",&start);
	printf("BFS traversal : ");
	BFS(start-1, vert);
}



/*

Output :

Enter the number of vertices : 6
Enter the number of edges : 7
Enter the edge from vert to vert (v1 v2) : 1 2
Enter the edge from vert to vert (v1 v2) : 1 4
Enter the edge from vert to vert (v1 v2) : 4 2
Enter the edge from vert to vert (v1 v2) : 2 5
Enter the edge from vert to vert (v1 v2) : 5 4
Enter the edge from vert to vert (v1 v2) : 3 5
Enter the edge from vert to vert (v1 v2) : 3 6
Adjacency Matrix :
   1  2  3  4  5  6
1  0  1  0  1  0  0

2  0  0  0  0  1  0

3  0  0  0  0  1  1

4  0  1  0  0  0  0

5  0  0  0  1  0  0

6  0  0  0  0  0  0
enter the starting vertices  : 3
BFS traversal :  3  5  6  4  2 

*/
#include <stdio.h>
#define max 100
int adj[max][max],count=0;
int main()
{
	int vert,edge,v1,v2,i,j;
	printf("Enter the number of vertices  : ");
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
		printf("Enter the edge from vertices to vertices (v1 v2) : ");
		scanf("%d%d",&v1,&v2);
		adj[v1-1][v2-1]=1;
	}
	printf("Adjacency matrix : \n");
	printf("  ");
	for (i=0;i<vert;i++)
	{
		printf(" %d ",i+1);
	}
	for (i=0;i<vert;i++)
	{
		//int count=0;
		printf("\n%d ",i+1);
		for (j=0;j<vert;j++)
		{
			printf(" %d ",adj[i][j]);
			//if (adj[i][j]==1)
			  // count++;
		}
		//printf("Total Indegree : %d",count);
		printf("\n");
	}
}
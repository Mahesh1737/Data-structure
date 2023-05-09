#include <stdio.h>
#define max 100

int adj[max][max];
int in[max]={0},out[max]={0};

void printDegree(int v)
{
	int i,j;
	printf("\nvertex Indegree Outdegree Total Degree \n");
	for (i=0;i<v;i++)
	{
		in[i] = 0; // reset in-degree count
		out[i] = 0; // reset out-degree count
		for (j=0;j<v;j++)
		{
			if (adj[j][i]==1)
				in[i]++;
			if (adj[i][j]==1)
				out[i]++;
		}
		printf("   %d       %d         %d        %d      ",i+1,in[i],out[i],(in[i]+out[i]));
		printf("\n");
	}
}

void main()
{
	int i,j,v1,v2,vert,edge;
	printf("Enter the number of vertices : ");
	scanf("%d",&vert);
	printf("Enter the number of edges : ");
	scanf("%d",&edge);

	for (i=0;i<vert;i++)
	{
		for (j=0;j<vert;j++)
		{
			adj[i][j]=0;
		}
	}
	for (i=0;i<edge;i++)
	{
		printf("Enter the edge from vertex to vertex (v1 v2) :");
		scanf("%d%d",&v1,&v2);
		adj[v1-1][v2-1]=1; // corrected indexing
	}
	printf("Adjacency Matrix for graph with vertices %d & edges %d : \n",vert,edge);
	printf("  ");
	for (i=0;i<vert;i++)
	{
		printf(" %d ",i+1);
	}
	for (i=0;i<vert;i++)
	{
		printf("\n%d ",i+1);
		for (j=0;j<vert;j++)
		{
			printf(" %d ",adj[i][j]);
		}
		printf("\n");
	}
	printDegree(vert);
}


/*
Output :

PS D:\backup -6-1-2023\Users\dell\.vscode\Adjacency matrix> cd "d:\backup -6-1-2023\Users\dell\.vscode\Adjacency matrix\" ; if ($?) { gcc practice.c -o practice } ; if ($?) { .\practice }
Enter the number of vertices : 4
Enter the number of edges : 5
Enter the edge from vertex to vertex (v1 v2) :1 2
Enter the edge from vertex to vertex (v1 v2) :1 3
Enter the edge from vertex to vertex (v1 v2) :2 3
Enter the edge from vertex to vertex (v1 v2) :2 4
Enter the edge from vertex to vertex (v1 v2) :3 4
Adjacency Matrix for graph with vertices 4 & edges 5 :
   1  2  3  4
1  0  1  1  0

2  0  0  1  1

3  0  0  0  1

4  0  0  0  0

vertex Indegree Outdegree Total Degree
   1       0         2        2
   2       1         2        3
   3       2         1        3
   4       2         0        2

*/
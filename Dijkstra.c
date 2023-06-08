#include <stdio.h>
#include <stdlib.h>
#define N 10 
#define m 999

int mst[N],wt[N],adj[N][N],parent[N];
int n,s,v1,v2,i,j;

int min_key()
{
    int min,minimum=m,i;
    for (i=0;i<n;i++)
    {
        if(mst[i]==0 && wt[i]<minimum)
        {
            minimum=wt[i];
            min=i;
        }
    }
    return min;
}

void Dij(int s)
{
    for (i=0;i<n;i++)
    {
        wt[i]=m;
        mst[i]=0;
    }
    wt[s-1]=0;
    for (i=0;i<n;i++)
    {
        int u=min_key();
        mst[u]=1;
        for (j=0;j<n;j++)
        {
            if (mst[j]==0 && wt[u]!=m && adj[u][j] && wt[u]+adj[u][j]< wt[j])
            {
                wt[j]=wt[u]+adj[u][j];
            }
        }
    }
}
void print(int s)
{
    printf("\nShortest path for vertex %d : \n");
    for (i=0;i<n;i++)
    {
        if (s!=i)
           printf("\nshortest path %d-->%d  : %d",s,i+1,wt[i]);
        else
           printf("\nshortest path %d-->%d  : %d",s,i+1,wt[i]);
    }
    printf("\n");
}
void main()
{
    int wt;
    printf("Enter the number of vertex : ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j)
               adj[i][j]=0;
            else
               adj[i][j]=999;
        }
    }
    while(1)
    {
        printf("Enter the edges for weightd undirected graph : \n");
        printf("Enter (0,0) for exit : ");
        scanf("%d%d",&v1,&v2);
        if (v1==0 && v2==0)
           break;
        printf("Enter the weight for edge %d & %d : ",v1,v2);
        scanf("%d",&wt);
        adj[v1-1][v2-1]=wt;
        adj[v2-1][v1-1]=wt;
    }
    printf("Adjacency matrix for Undirected weighted graph : \n");
    printf("  ");
    for (i=0;i<n;i++)
        printf(" %d  ",i+1);
    for (i=0;i<n;i++)
    {
        printf("\n%d",i+1);
        for (j=0;j<n;j++)
        {
            printf(" %2d ",adj[i][j]);
        }
    }
    printf("\n");
    printf("Enter starting vertex : ");
    scanf("%d",&s);
    Dij(s);
    print(s);

}

/*

output :

Enter the number of vertex : 5
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 1 3
Enter the weight for edge 1 & 3 : 3
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 2 3
Enter the weight for edge 2 & 3 : 10
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 2 4
Enter the weight for edge 2 & 4 : 4
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 3 4
Enter the weight for edge 3 & 4 : 2
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 3 5
Enter the weight for edge 3 & 5 : 6
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 5 4
Enter the weight for edge 5 & 4 : 1
Enter the edges for weightd undirected graph :
Enter (0,0) for exit : 0 0
Adjacency matrix for Undirected weighted graph :
   1   2   3   4   5
1  0  999   3  999  999
2 999   0  10   4  999
3  3  10   0   2   6
4 999   4   2   0   1
5 999  999   6   1   0
Enter starting vertex : 3

Shortest path for vertex 1970759897 :

shortest path 3-->1  : 3
shortest path 3-->2  : 6
shortest path 3-->3  : 0
shortest path 3-->4  : 2
shortest path 3-->5  : 3
*/
#include<stdio.h>
#include<stdlib.h>
#define m 999
#define N 10
int parent[N],mst[N],adj[N][N],mw=0,wt[N],sol[N][N];
int n,s,v1,v2,i,j,k;


void fw()   
{
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            sol[i][j]=adj[i][j];
     for(k=0;k<n;k++)
     {
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)       
            {
                if(i==j)
                   sol[i][j]=0;
                if(sol[i][k]+sol[k][j]<sol[i][j])
                   sol[i][j]=sol[i][k]+sol[k][j];
            }
         }
     }                 
}


void print()
{
     
     printf("   ");
     
     for(i=0;i<n;i++)
         printf("  %d   ",i+1);
     printf("\n");
     for(i=0;i<n;i++)
     {
        printf("\n  %d",i+1);
        for(j=0;j<n;j++) 
            printf("%4d  ",sol[i][j]);
     }
     //printf("\n");               
}                        
   
void main()
{                                                                                                 
    int wt,mw=0;
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if(i==j)
               adj[i][j]=0;
            else     
              adj[i][j]=999;
        }      
    while(1)
     {
          printf("\nEnter the edge in (v1 v2) for directed graph : ");
          printf("\nEnter (0,0) to exit :");
          scanf("%d %d",&v1,&v2);
          
          if((v1==0) && (v2==0)) 
             break;
          if(v1>n || v2>n || v1<1 || v2<1)
          {
             
             break;
          }
          printf("Enter the weight of the edge between %d and %d : ",v1,v2);
          scanf("%d",&wt);
           adj[v1-1][v2-1]=wt;
          // adj[v2-1][v1-1]=wt;
     }
     printf("\nAdjacency matrix for directed graph is :\n");
     printf("  ");
     for(i=0;i<n;i++)
     {
        printf(" %d  ",i+1);
     }
     for(i=0;i<n;i++)
     {
       // ind[i]=0;
        printf("\n%d",i+1);
        for(j=0;j<n;j++)
        {
            printf(" %2d ",adj[i][j]);
            
        }
              
     }
     fw();
     printf("\nThe shortest path : \n");
     print();
     printf("\nShortest path : \n");
     for(i=0;i<n;i++)
     {
        printf("\nShortest Distance from %d vertex : \n",i+1);
        for(j=0;j<n;j++)
        {
           if(i!=j)
             printf("<%d,%d>=%d\n",i+1,j+1,sol[i][j]);
           else
             printf("<%d,%d>=%d\n",i+1,j+1,sol[i][j]);
        }  
     }         
        
}        


/* 

Output : 

Enter the no. of vertices : 5

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :1 3
Enter the weight of the edge between 1 and 3 : 3

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :3 2
Enter the weight of the edge between 3 and 2 : 10

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :3
4
Enter the weight of the edge between 3 and 4 : 2

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :3 5
Enter the weight of the edge between 3 and 5 : 6

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :5 4
Enter the weight of the edge between 5 and 4 : 1

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :4 2
Enter the weight of the edge between 4 and 2 : 4

Enter the edge in (v1 v2) for directed graph :
Enter (0,0) to exit :0 0

Adjacency matrix for directed graph is :
   1   2   3   4   5
1  0  999   3  999  999
2 999   0  999  999  999
3 999  10   0   2   6
4 999   4  999   0  999
5 999  999  999   1   0
The shortest path :
     1     2     3     4     5

  1   0     9     3     5     9
  2 999     0   999   999   999
  3 999     6     0     2     6
  4 999     4   999     0   999
  5 999     5   999     1     0
Shortest path :

Shortest Distance from 1 vertex :
<1,1>=0
<1,2>=9
<1,3>=3
<1,4>=5
<1,5>=9

Shortest Distance from 2 vertex :
<2,1>=999
<2,2>=0
<2,3>=999
<2,4>=999
<2,5>=999

Shortest Distance from 3 vertex :
<3,1>=999
<3,2>=6
<3,3>=0
<3,4>=2
<3,5>=6

Shortest Distance from 4 vertex :
<4,1>=999
<4,2>=4
<4,3>=999
<4,4>=0
<4,5>=999

Shortest Distance from 5 vertex :
<5,1>=999
<5,2>=5
<5,3>=999
<5,4>=1
<5,5>=0
*/
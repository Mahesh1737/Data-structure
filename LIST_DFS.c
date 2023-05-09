#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node 
{
    int vertex;
    struct node* next;
}*newnode1,*newnode2,*temp;
struct node* adj[MAX];
int visit[MAX]={0};
int vert;
void addedge(int v1, int v2) 
{
    newnode1 = (struct node*)malloc(sizeof(struct node));
    newnode1->vertex = v2;
    newnode1->next = adj[v1];
    adj[v1] = newnode1;
  
}

void displaylist() 
{
    int i,count[10]={0};
    printf("Adjacency list:\n");
    for (i = 1; i <= vert; i++) 
  {
        printf("%d : --> ", i);
        struct node* curr = adj[i];
        while (curr != NULL) 
    {
            printf("%d--> ", curr->vertex);
            curr = curr->next;
            count[i]++;
        }
        printf("NULL  : %d\n",count[i]);
    }
}


void dfs(int vertex) 
{
    int stack[MAX];
    int top = -1;//declare stack to NULL

    visit[vertex] = 1;
    stack[++top] = vertex;//push vertex onto stack

    while (top != -1) //until stack becomes NULL
  {
        int start = stack[top--];//popped top from satck
        printf("%d ", start);//print Top

        struct node *ptr = adj[start];//ptr points to the adjacent vertex of start
        while (ptr != NULL) {//until start adjacent not become NULL
            int v = ptr->vertex;//v assignes the value of start adjacent 
            if (!visit[v]) //if v is not visited
      {
                visit[v] = 1;//then visit it
                stack[++top] = v;//and push it into stack
            }
            ptr = ptr->next;//then check start adjecent's adjecent vertex's  
        }
    }
}

int main() 
{
    int e, i, v1, v2,start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the number of edges: ");
    scanf("%d", &e);
    
    for (i = 1; i <= e; i++) 
  {
        printf("Enter edge %d : (v1,v2) : ", i);
        scanf("%d%d", &v1, &v2);
        addedge(v1, v2);
        //addedge(v2, v1);
    }
    displaylist();
    printf("\nEnter the starting vertex of Directed graph : ");
    scanf("%d",&start);
    printf("\nDFS Treversal for Directed graph : ");
    dfs(start);
}


/*

Output :

Enter the number of vertices: 6
Enter the number of edges: 7
Enter edge 1 : (v1,v2) : 1 2
Enter edge 2 : (v1,v2) : 1 4
Enter edge 3 : (v1,v2) : 4 2
Enter edge 4 : (v1,v2) : 2 5
Enter edge 5 : (v1,v2) : 5 4
Enter edge 6 : (v1,v2) : 3 5
Enter edge 7 : (v1,v2) : 3 6
Adjacency list:
1 : --> 4--> 2--> NULL  : 2
2 : --> 5--> NULL  : 1
3 : --> 6--> 5--> NULL  : 2
4 : --> 2--> NULL  : 1
5 : --> 4--> NULL  : 1
6 : --> NULL  : 0

Enter the starting vertex of Directed graph : 3

DFS Treversal for Directed graph : 3 5 4 2 6 PS D:\backup -6-1-2023\Users\dell\.vscode\Adjacency List>

*/
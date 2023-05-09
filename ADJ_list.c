#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[MAX]; // array of pointers to linked list nodes
struct node *newnode;  // pointer to a new node
int vert;              // number of vertices in the graph

void addEdge(int v1, int v2)
{
    // Create a new node for v2 and add it to the linked list of v1
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = v2;
    newnode->next = adj[v1];//make connectivity between v1 and v2
    adj[v1] = newnode;//adjacent of v1 is store at adj[v1] array
}

void displayList()
{
    int i, count[10] = {0}; // counter array to store degree of each vertex
    printf("Adjacency list:\n");
    for (i = 1; i <= vert; i++)
    {
        printf("%d : --> ", i);
        struct node *curr = adj[i];
        while (curr != NULL)
        {
            printf("%d--> ", curr->vertex);
            curr = curr->next;
            count[i]++;
        }
        printf("NULL  : %d\n", count[i]);
    }
}

void degree(struct node **adj, int vert)
{
    int i, j;
    printf("\nVertex in_Degree Out_Degree Total_Dgree ::\n");
    for (i = 1; i <= vert; i++)
    {
        int in = 0;
        int out = 0;
        struct node *temp = adj[i];
        // count outgoing edges of vertex i
        while (temp)
        {
            out++;
            temp = temp->next;
        }
        // count incoming edges of vertex i
        for (j = 1; j <= vert; j++)
        {
            temp = adj[j];
            while (temp)
            {
                if (temp->vertex == i)
                {
                    in++;
                }
                temp = temp->next;
            }
        }
        // display degree information
        printf("    %d        %d        %d       %d\n", i, in, out, in + out);
    }
}

int main()
{
    int e, i, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &vert);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // add edges to the graph
    for (i = 1; i <= e; i++)
    {
        printf("Enter edge %d : (v1,v2) : ", i);
        scanf("%d%d", &v1, &v2);
        addEdge(v1, v2);
    }

    // display the adjacency list
    displayList();

    // calculate and display the degree of each vertex
    degree(adj, vert);

    return 0;
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
Enter edge 6 : (v1,v2) : 3 6
Enter edge 7 : (v1,v2) : 3 5
Adjacency list:
1 : --> 4--> 2--> NULL  : 2
2 : --> 5--> NULL  : 1
3 : --> 5--> 6--> NULL  : 2
4 : --> 2--> NULL  : 1
5 : --> 4--> NULL  : 1
6 : --> NULL  : 0

Vertex in_Degree Out_Degree Total_Dgree ::
    1        0        2       2
    2        2        1       3
    3        0        2       2
    4        2        1       3
    5        2        1       3
    6        1        0       1

*/
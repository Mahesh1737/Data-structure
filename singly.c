#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct node 
{ 
   int id; 
   char bname[50]; 
   char author[50]; 
   struct node *next; 
} *head = NULL, *temp, *newnode, *t; 

int pos,n,val; 

void search(int);
void createNode(int);
void display(void);
void insert(int); 
void delete(int);
void delete1(int);
void search(int);

 
void createNode(int n) 
{ 
   int i;
   struct node *prev = NULL; 

   for (i = 0; i < n; i++) 
   { 
       newnode = (struct node *)malloc(sizeof(struct node)); 
       newnode->next = NULL; 
       printf("Enter the book ID: "); 
       scanf("%d", &(newnode->id)); 
       getchar(); 

       printf("Enter the book name: "); 
       
       fgets(newnode->bname, sizeof(newnode->bname), stdin); 
       newnode->bname[strcspn(newnode->bname, "\n")] = '\0'; // Remove newline character 

       printf("Enter the book auhor: "); 
       fgets(newnode->author, sizeof(newnode->author), stdin); 
       newnode->author[strcspn(newnode->author, "\n")] = '\0'; // Remove newline character 

       if (head == NULL) 
       { 
           // newnode->next = NULL; 
           head = newnode; 
           temp = head; 
       } 
       else 
       { 
           temp->next = newnode; 
           // newnode->next = NULL; 
           temp = temp->next; 
       } 
       // prev = newnode; 
   } 
} 

void display() 
{ 
   temp = head; 
   printf("\nHead->"); 
   while (temp != NULL) 
   { 
       printf("[ %d :", temp->id); 
       printf(" %s :", temp->bname); 
       printf(" %s ]->", temp->author); 
       temp = temp->next; 
       // printf("\n"); 
   } 
   printf("Null\n"); 
} 

void insert(int pos) 
{
   newnode = (struct node *)malloc(sizeof(struct node)); 
   printf("Enter the book ID: "); 
   scanf("%d", &(newnode->id)); 
   getchar(); 

   printf("Enter the book name: "); 
   fgets(newnode->bname, sizeof(newnode->bname), stdin); 
   newnode->bname[strcspn(newnode->bname, "\n")] = '\0'; // Remove newline character 

   printf("Enter the book author: "); 
   fgets(newnode->author, sizeof(newnode->author), stdin); 
   newnode->author[strcspn(newnode->author, "\n")] = '\0'; // Remove newline character 

   if (pos == 1) 
   {
       newnode->next = head;  // Set new node's next to current head
       head = newnode;
       n++;         // Update head to new node
   } 
   else 
   {
       int i;
       t = head;
       // Traverse to the node just before the position
       for (i = 1; i < pos - 1 && t != NULL; i++) 
       {
           t = t->next;
       }
       if (t != NULL) 
       {
           newnode->next = t->next;  // Set new node's next to t's next
           t->next = newnode;        // Link t to new node
           n++; 
       } 
       else 
       {
           printf("Position is out of range\n");
       }
   }
    // Increment the node count
}


void delete(int pos)
{

   if (pos == 1)
   {
       temp = head;
       head = head->next;
       n--;
   }
   else
   {
       int i;
       for (t = head, i = 1; i < pos - 1; i++, t = t->next)
           ;
       temp = t->next;
       t->next = temp->next;
       n--;
   }
   
   free(temp);
}

void delete1(int val)
{
   if (head->id == val)
   {
       head = head->next;
       n--;
   }
   else
   {
       for (temp = head; temp->next != NULL; temp = temp->next)
       {
           if (temp->next->id == val)
           {
               t = temp->next;
               temp->next = t->next;
               // free(t);
               n--;
               return;
           }
       }
   }
   printf("%d element not found :(\n", val);
}

void search(int val)
{
   int i;
   for (temp = head, i = 1; temp != NULL, i <= n; temp = temp->next, i++)
   {
       if (temp->id == val)
       {
           printf("%d element is found at %d position\n", temp->id, i);
           return;
       }
   }
   printf("%d element not found :(\n", val);
}


void main()
{
   int c = 1;

   while (c >= 1 && c <= 6)
   {
       printf("\nOperations on Singly Linked List : \n");
       printf("1: Create Singly Linked List\n");
       printf("2: Display Singly Linked List\n");
       printf("3: Insert by position\n");

       printf("4: delete by position\n");
       printf("5: delete by value\n");
       printf("6: search\n");
       printf("7: Exit\n");
       printf("\nEnter the operation\n");
       scanf("%d", &c);

       switch (c)
       {

       case 1:
           if (head != NULL)
               printf("Singly Linked List already Exists :|\n");
           else
           {
               printf("enter the number of nodes:-\n");
               scanf("%d", &n);
               if (n <= 0)
                   printf("you cannot enter 0 element\n");
               else
                   createNode(n);
           }

           break;
       case 2:
           display();
           break;
       case 3:
           if (head == NULL)
               printf("Singly Linked List is Empty :(\n");
           else
           {
               printf("enter position\n");
               scanf("%d", &pos);
               if (pos < 1 || pos > n + 1)
                   printf("You have entered invalid position for insertion :( \n");
               else
                   insert(pos);
           }
           break;
       case 4:
           if (head == NULL)
               printf("Singly Linked List is Empty :(\n");
           else
           {
               printf("enter position\n");
               scanf("%d", &pos);
               if (pos < 1 || pos > n || head == NULL)
                   printf("You have entered invalid position for deletion :(\n");
               else
                   delete (pos);
           }
           break;
       case 5:
           if (head == NULL)
               printf("Singly Linked List is Empty :(\n");
           else
           {
               printf("enter value\n");
               scanf("%d", &val);
               delete1(val);
           }
           break;
       case 6:
           if (head == NULL)
               printf("Singly linked list is empty :(\n");
           else
           {
               printf("enter value\n");
               scanf("%d", &val);
               search(val);
           }
           break;

       case 7:
           exit(0);

       default:
           printf("you entered invalid operation :(\n");
       }
       if (head == NULL)
           printf("Singly Linked List is Empty :(\n");
       else
           display();
       printf("no. of nodes = %d\n", n);
   }
}

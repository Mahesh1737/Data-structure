#include <stdio.h>
#include <stdlib.h>
#define max 10

struct node
{
    int data;
    struct node *next;
}*rear,*front,*temp;

void init();
int dequeue();
void enqueue();
void display();
//int isfull();
int isempty();
//int queue[max];
int n,val;
void main()
{
    int ch = 1;
    init();
    while (ch >= 1 && ch <= 5)
    {
        printf("\nSTATIC QUEUE USING ARRAY\n");
        printf("1. enqueue :\n");
        printf("2. dequeue :\n");
        printf("3. display :\n");
       // printf("4. isfull :\n");
        printf("4. isempty :\n");
        printf("5. exit :\n");
        printf("enter  the any above option:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element to innsrt :\n");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            if (isempty())
                printf("queue is already empty\n");
            else
                printf("Dequeue element :  %d \n",dequeue());
            break;
        case 3:
            if (isempty())
                printf("queue is empty\n");
            else
                display();
            break;
        // case 4:
        //     if (isfull())
        //         printf("queue is full\n");
        //     else
        //         printf("queue is not full");
        //     break;
        case 4:
            if (isempty())
                printf("queue is empty\n");
            else
                printf("queue is not empty\n");
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID OPERATION IS ENTEREd\n");
            break;
        }
        display();
    }
}
void init()
{
    front=rear=NULL;
}
void enqueue(int n)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if (front==NULL)
       front=rear=temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
int dequeue()
{
    val=front->data;
    front=front->next;
    if (front==NULL)
       rear=NULL;
    return val;
}
void display()
{
    struct node *temp;
    temp=front;
    printf("QUEUE IS: FRONT--> ");
    while(temp!=NULL)
    {
      printf(" %d ",temp->data);
      temp=temp->next;
    }
    printf(" REAR \n");
}
// int isfull()
// {
//     if(rear ==max-1)
//       return 1;
//     else
//       return 0;
// }
int isempty()
{
    if(rear==NULL)
      return 1;
    else 
      return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define max 5
void init();
void push();
void pop();
void peek();
void display();
int isfull();
int isempty();
int n, i, top, val;
int stack[max];
void main()
{
    int ch = 1;
    init();
    while (ch >= 1 && ch <= 6)
    {
        printf("\n STATIC IMPLEMENTATION OF THE STACK\n");
        printf("1 :to push \n");
        printf("2 :to display \n");
        printf("3 :to pop \n");
        printf("4 :to peek \n");
        printf("5 :to check it is empty\n");
        printf("6 :to check it is full\n");
        printf("7 : exit\n");
        printf("\n ENTER THE OPTION FROM ABOVE \n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            if (isfull())
            {
                printf("stack is full\n");
            }
            else
            {
                printf("enter the element :\n");
                scanf("%d", &n);
                push(n);
            }
            break;
        case 2:
            if (isempty())
            {
                printf("stack is empty\n");
            }
            else
            {
                display();
            }
            break;
        case 3:
            if (isempty())
            {
                printf("stack is empty\n");
            }
            else
            {
                pop();
            }
            break;
        case 4:
            if (isempty())
            {
                printf("stack is empty\n");
            }
            else
            {
                peek();
            }
            break;
        case 5:
            if (isempty())
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("stack is not empty\n");
            }
            break;
        case 6:
            if (isfull())
            {
                printf("stack is full\n");
            }
            else
            {
                printf("stack is not full\n");
            }
            break;
        case 7:
            exit(0);
            break;
        }
        display();
    }
}
void init()
{
    top = -1;
}
void push(int n)
{
    top++;
    stack[top] = n;
}
void display()
{
    printf("\n STACK TOP-->");
    for (i = top; i >= 0; i--)
    {
        printf(":: %d ", stack[i]);
    }
}
void peek()
{
    printf("top element :%d\n", stack[top]);
}
void pop()
{
    val = stack[top];
    top--;
    printf("popped element = %d\n", val);
}
int isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
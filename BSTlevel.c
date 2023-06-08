#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} * root, *temp, *new1, *new2;

struct node *create()
{
    struct node *temp = malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node *root, struct node *new1)
{
    if (root->data < new1->data)
    {
        if (root->right == NULL)
            root->right = new1;
        else
            insert(root->right, new1);
    }
    else if (root->data > new1->data)
    {
        if (root->left == NULL)
            root->left = new1;
        else
            insert(root->left, new1);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void display(struct node *root)
{
    printf("\nPREORDER TRAVERSAL:");
    preorder(root);
    printf("\nINORDER TRAVERSAL:");
    inorder(root);
    printf("\nPOSTORDER TRAVERSAL:");
    postorder(root);
}

int printlevel(struct node *root, int level, int *count)
{
    if (root == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
        (*count)++;
    }
    else if (level > 1)
    {
        printlevel(root->left, level - 1, count);
        printlevel(root->right, level - 1, count);
    }
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int right = Height(root->right);
        int left = Height(root->left);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}
int printtree(struct node *root)
{
    int H = Height(root);
    printf("Total Level : %d\n", H);
    for (int i = 1; i <= H; i++)
    {
        int count = 0;
        printf("Level %d: ", i);
        printlevel(root, i, &count);
        printf("|count : %d|\n", count);
    }
}

void main()
{
    int ch = 1, n, i, h, r;
    struct node *root = NULL;
    while (ch >= 1 && ch <= 6)
    {
        printf("\nBST OPERATIONS : \n");
        printf("\n1. create : \n2. display : \n3. exit : \n4. insert : \n5. Print Total level: \n6. count of Level: \n");
        printf("\nenter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (root != NULL)
            {
                printf("BST is already exist :");
            }
            else
            {
                printf("enter number of nodes : ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                {
                    new2 = create();
                    printf("enter the data for %d node: ", i);
                    scanf("%d", &new2->data);
                    if (root == NULL)
                        root = new2;
                    else
                        insert(root, new2);
                }
            }
            break;
        case 2:
            if (root == NULL)
            {
                printf("BST is empty \n");
            }
            else
            {
                printf("BST traversal: ");
                display(root);
            }
            break;
        case 3:
            exit(0);
        case 4:
            if (root == NULL)
            {
                printf("BST is already present\n");
            }
            else
            {
                new1 = create();
                printf("enter data : ");
                scanf("%d", &new1->data);
                if (root == NULL)
                    root = new1;
                else
                    insert(root, new1);
            }
            break;
        case 5:
            h = Height(root);
            printf("Total level : %d", h);
            break;
        case 6:
            if (root == NULL)
            {
                printf("BST is empty ");
            }
            else
            {
                printtree(root);
            }
            break;
        default:
            printf("\nwrong choice enter\n");
            break;
        }
    }
}

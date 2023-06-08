#include <stdio.h>
#include <stdlib.h>

// A BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*new1,*new2;

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into BST
struct Node* insert(struct Node* root, int val)
{
    if(root==NULL)
    {
        return newNode(val);
    }
    if(root->data < val)
    {
        root->right=insert(root->right,val);
    }
    else if(root->data > val)
    {
        root->left=insert(root->left, val);
    }
    return root;
}

// Function to display nodes at each level and count the nodes at each level in a BST
void displayLevelsAndCounts(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    int level = 1;
    int currentLevelNodes = 1;
    int nextLevelNodes = 0;
    int count = 0;
    printf("Level %d: ", level);
    queue[rear++] = root;
    while (front != rear) {
        struct Node* node = queue[front++];
        currentLevelNodes--;
        printf("%d ", node->data);
        count++;
        if (node->left != NULL) {
            queue[rear++] = node->left;
            nextLevelNodes++;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
            nextLevelNodes++;
        }
        if (currentLevelNodes == 0) {
            printf("(Count: %d)\n", count);
            level++;
            currentLevelNodes = nextLevelNodes;
            nextLevelNodes = 0;
            count = 0;
            if (currentLevelNodes > 0) {
                printf("Level %d: ", level);
            }
        }
    }
    printf("Total levels: %d\n", level - 1);
}

// Driver code
int main() {
    struct Node* root = NULL;
    int choice, data,val,n;

    while (1) {
        printf("1. Create BST \n");
        printf("2. Display nodes at each level and count nodes at each level\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("enter data : ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 2:
            displayLevelsAndCounts(root);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
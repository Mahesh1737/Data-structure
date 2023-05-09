#include<stdio.h>
#include<stdlib.h>

struct bst 
{
    int data;
    struct bst *lc,*rc;
}*temp,*root,*t1,*t2,*new1,*new2;

int n,cnt,lcnt;
void init(void);
struct bst *create();
// void bsttraverse(struct bst *);
void inorder(struct bst *);
void preorder(struct bst *);
void postorder(struct bst *);
void insert(struct bst *, struct bst *);
struct bst *search(struct bst *, int);
struct bst *succ(struct bst *);
struct bst *deleteNode(struct bst *, int);

void init()
{
    root=NULL;
}
struct bst *create()
{
    struct bst *temp=(struct bst *)malloc(sizeof(struct bst));
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}
void insert(struct bst *r,struct bst *new1)
{
    if(new1->data < r->data)
    {
        if(r->lc==NULL)
          r->lc=new1;
        else 
          insert(r->lc,new1);  
    }
    if(new1->data >r->data)
    {
        if(r->rc==NULL)
          r->rc=new1;
        else 
          insert(r->rc,new1);  
    }

}
void inorder(struct bst *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lc);
        printf("%d  ",temp->data);
        inorder(temp->rc);
    }
}

void preorder(struct bst *temp)
{
    if(temp!=NULL)
    {
        printf("%d  ",temp->data);
        preorder(temp->lc);
        preorder(temp->rc);
    }
}
void postorder(struct bst *temp)
{
    if(temp != NULL)
    {
        postorder(temp->lc);
        postorder(temp->rc);
        printf("%d  ",temp->data);
    }
}
void btreetraverse(struct bst *root)
{ 
    printf("\n Preorder Traversal : ");
    preorder(root);
    printf("\n Inorder Traversal : ");
    inorder(root);
    printf("\n Postorder Traversal : ");
    postorder(root);
}
struct bst *search(struct bst *root,int key )
{
    t1=root;
    while(t1 != NULL)
    {
        if (key==t1->data)
            return t1;
        else if( key< t1->data)
            search(t1->lc,key);
        else if (key > t1->data)
            search(t1->rc,key);
    }
    return  NULL;
}
// struct bst *delete(struct bst *root,int key)
// {
//     if (root==NULL)
//        return NULL;
//     if (root->lc==NULL && root->rc==NULL)
//        return NULL;
//     if (key  < root->data)
//       root->lc=delete(root->lc,key);
//     else if (key > root->data)
//       root->rc=delete(root->rc,key);
//     else
//     {
//       t1=succ(root);
//       t1->data=root->data;
//       root=delete(root,t1->data);
//       free(t1);  
//     }
//     return root;
// }


struct bst *deleteNode(struct bst *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->lc = deleteNode(root->lc, data);
    else if (data > root->data)
        root->rc = deleteNode(root->rc, data);
    else
    {
        if (root->lc == NULL)
        {
            struct bst *temp = root->rc;
            free(root);
            return temp;
        }
        else if (root->rc == NULL)
        {
            struct bst *temp = root->lc;
            free(root);
            return temp;
        }

        struct bst *temp = root->rc;
        while (temp->lc != NULL)
        {
            temp = temp->lc;
        }
        root->data = temp->data;
        root->rc = deleteNode(root->rc, temp->data);
    }

    return root;
}


struct bst *succ(struct bst *temp)
{
    temp=temp->lc;
    while(temp->rc!=NULL)
    {
         temp=temp->rc;
    }
    return temp;
}

int count(struct bst *temp)
{
    if (temp!= NULL)
    {
        cnt++;
        count(temp->lc);
        count(temp->rc);
    }
    return cnt;
}
int countleaf(struct bst *temp)
{
    if (temp!= NULL)
    {
        if(temp->lc==NULL && temp->rc==NULL)
          lcnt++;
        countleaf(temp->lc);
        countleaf(temp->rc);
    }
    return lcnt;
}
// nt count(struct node *root)
// {
//   if(root==NULL)
//     return 0;
//   else
//     return(1+count(root->left)+count(root->right));  
// }
// int countleaf(struct bst *root)
// {
//   if(root->lc==NULL&&root->rc==NULL)  
//     return 1;
//   return  1+countleaf(root->lc)+countleaf(root->rc)  ;
// }
// int countleaf(struct bst *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int leaf_count = 0;
//     if (root->lc == NULL && root->rc == NULL)
//     {
//         leaf_count = 1;
//     }
//     leaf_count += countleaf(root->lc);
//     leaf_count += countleaf(root->rc);
//     return leaf_count;
// }

void main()
{
    int op=1,val,i;
    init();
    while (op>=1 && op<=7)
    {
        cnt=0,lcnt=0;
        printf("\n BINARY SEARCH TREE IMPLEMENTATION \n");
        printf("\n  1 : create bst");
        printf("\n  2 : display bst");
        printf("\n  3 : insert node in bst");
        printf("\n  4 : search node in bst");
        printf("\n  5 : delete node in bst");
        printf("\n  6 : count all nodes in bst");
        printf("\n  7 : count leaf nodes in bst");
        printf("\n Enter the desired option :");
        scanf("%d",&op);

        switch (op)
        {
        case 1:if (root != NULL)
                   printf("\n Bst already exist"); 
               else
               {
                   printf("\n Enter number of nodes to be enntered : ");
                   scanf("%d",&n);
                   if(n<0)
                   {
                    printf("\n Invalid no of nodes ..");
                   }
                   else
                   {
                      for(i=1;i<=n;i++)
                      {
                        new2=create();
                        printf("\n Enter data for node %d : ",i);
                        scanf("%d",&new2->data);
                        if (root == NULL)
                           root=new2;
                        else
                           insert(root,new2);
                      }
                   }
               }
               break;
         case 2:if (root == NULL)
                   printf("\n Bst does not exist"); 
                else
                   btreetraverse(root);
                break;
        case 3 :t2=create();
                printf("\n Enter data for node  : ");
                scanf("%d",&t2->data);
                if(root==NULL)
                     root=t2;
                else
                    insert(root,t2);
                break;
        case 4: if (root == NULL)
                   printf("\n Bst does not exist"); 
               else
               {
                printf("\n Enter data of node to search : ");
                scanf("%d",&val);
                t1=search(root,val);
                if(t1==NULL)
                  printf("\n Node not found \n");
                else
                   printf("\n node found \n");
               }
               break;
        case 5: if (root == NULL)
                   printf("\n Bst does not exist"); 
               else
               {
                printf("\n Enter data of node to delete : ");
                scanf("%d",&val);
                t1=deleteNode(root,val);
               }
               break;   
        case 6: if (root == NULL)
                   printf("\n Bst does not exist"); 
               else
               {
                  cnt=count(root);
                  printf("\n Total nodes : %d",cnt);
               }
               break; 
        case 7: if (root == NULL)
                   printf("\n Bst does not exist"); 
               else
               {
                  lcnt=countleaf(root);
                  printf("\n Total leaf nodes : %d",lcnt);
               }
               break;                
        default:printf("\n Enter valid option");
            break;
        }
    }
}
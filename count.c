#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void printarray(int arr[], int n)
{
    int i;
    printf("elements are :");
    for (i=0;i<n;i++)
    {
        printf(" %d\t ",arr[i]);
    }
    printf("\n");
}
int maximum(int arr[], int n)
{
    int i, max= INT_MIN;
    for(i=0;i<n;i++)
    {
        if(max < arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
void count(int arr[], int n)
{
    int i,j;
    int max=maximum(arr, n);

    int* count=(int*)malloc((max+1)*sizeof(int*));

    for(i=0;i<max+1;i++)
    {
       count[i]=0;
    }

    for(i=0;i<n;i++)
    {
       count[arr[i]]=count[arr[i]]+1;
    }
    i=0;
    j=0;
    while(i<=max)
    {
        if(count[i]>0)
        {
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
            i++;
    }
}
int main()
{
    int i,n,arr[10];
    printf("enter the size of the dataset :");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("enter the %d element of the dataset :",i);
        scanf("%d",&arr[i]);
    }
    printarray(arr, n);
    count(arr, n);
    printarray(arr, n);
    return 0;
}
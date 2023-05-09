#include<stdio.h>
#include<stdlib.h>
void printarray(int arr[], int n)
{
    int i;
    printf("elements are :");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void bubble(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            }
        }
    }
}
int main()
{
    int n,i,arr[10];
    printf("\n enter the size of the dataset :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter the %d element of the dataset :\n",i);
        scanf("%d",&arr[i]);
    }
    printarray(arr, n);
    bubble(arr, n);
    printarray(arr, n);
}
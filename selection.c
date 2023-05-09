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
void selection(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        int ind=i;
        for(j=i+1;j<n;j++)
        {
          if(arr[j]<arr[ind])
          {
            ind=j;
          }
        temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
        }
        
    }
}
int main()
{
    int i,n,randarrray[10];
    printf("\nenter the size of the dataset :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        randarrray[i]=rand() %100;
    }
    printarray(randarrray, n);
    selection(randarrray, n);
    printarray(randarrray, n);
}
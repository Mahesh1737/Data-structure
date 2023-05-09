#include<stdio.h>
#include<stdlib.h>
void printarray(int arr[], int n)
{
    int i;
    printf("elements are :\n");
    for(i=0;i<n;i++)
    {
       printf("%d\t",arr[i]);
    }
    printf("\n");
}
int binarysearch(int arr[],int n, int x)
{
    int mid,low,high;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==x)
        {
          return mid;
        }
        if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int n,i,x,arr[10];
    printf("\n enter the size of the dataset :");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("enter the %d element of the array : ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            printf("\nkindly enter the sorted array");
            return 0;
        }
    }

    printf("\nenter the element you want to find :");
    scanf("%d",&x);
    printarray(arr,n);
    int searchindex= binarysearch(arr,n,x);
    if(searchindex==-1)
    {
        printf("\n element not found\n");
    }
    else
    {
        printf("\n %d element found at the %d position \n",x,searchindex+1);
        return 0;
    }
}
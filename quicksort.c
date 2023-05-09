#include<stdio.h>
#include<stdlib.h>
void printarray(int arr[], int n)
{
    int i;
    printf("elements are :");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int partition(int arr[], int low, int high)
{
    int temp,i,j,pivot;
    i=low+1;
    j=high;
    pivot=arr[low];
    do
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
        }
    } while (i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int arr[], int low, int high)
{
    int i,j,k;
    if(low<high)
    {
        k=partition(arr, low, high);
        quicksort(arr, low,k-1);
        quicksort(arr,k+1,high);
    }
} 
int main()
{
    int i,n,arr[10];
    printf("\n enter the size of the dataset :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nenter the %d element of the dataset :\n",i);
        scanf("%d",&arr[i]);
    }
    printarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr, n);

    return 0;
}
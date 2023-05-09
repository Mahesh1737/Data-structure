#include<stdio.h>
#include<stdlib.h>
void printarray(int arr[], int n)
{
    int i;
    printf("elements are :",i);
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void merge(int arr[],int mid, int low, int high)
{
    int i,j,k,b[20];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid &&  j<=high)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else{
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=b[i];
    }
}
void mergesort(int arr[], int low, int high)
{
    int mid;
    if(low<high)
    {
       mid=(low+high)/2;
       mergesort(arr, low, mid);
       mergesort(arr, mid+1, high);
       merge(arr,mid, low,high); 
    }
}
int main()
{
    int n,arr[10],i;
    //int arr[]={78,44,88,11,33,22};
    //int n=6;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the %d element of the dataset : ",i);
        scanf("%d",&arr[i]);
    }
 
    printarray(arr,n);
    mergesort(arr,0,n-1);
    printarray(arr,n);

    return 0;
}
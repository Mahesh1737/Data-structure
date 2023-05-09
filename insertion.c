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
void insertion(int arr[], int n)
{
    int i,j,key;
    for(i=1;i<n-1;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n,i,arr[10];
    printf("\n enter the size of dataset :");
    scanf("%d",&n);
    int randarray[n];
    for(i=0;i<n;i++)
    {
      randarray[i]= rand() %100;
    }
    printarray(randarray, n);
    insertion(randarray, n);
    printarray(randarray, n);
}
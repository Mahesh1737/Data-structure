#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,x;

    printf("\nenter the size of dataset :");
    scanf("%d",&n);
    int randarray[n];
    int found=0;
    for (i=0;i<n;i++)
    {
        randarray[i]= rand() %100;
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        printf("\n elements number %d::%d",i,randarray[i]);
    }
    printf("\nenter the element you want to find ?:");
    scanf("%d",&x);

    for (i=0;i<n;i++)
    {
        if(randarray[i]==x)
        {
            printf("\n %d element found at %d position",i+1,randarray[i]);
            found=1;
        }
    }
    if(found==0)
    {
        printf("\nelement not found");
    }
    return 0;
}
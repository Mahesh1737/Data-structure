#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, x;
    printf("\n enter the size of the dataset :");
    scanf("%d", &n);
    int randarray[n];
    for (i = 0; i < n; i++)
    {
        randarray[i] = rand() % 100;
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("\nelements number %d::%d",i,randarray[i]);
    }
    printf("\n enter the elements you want to find :");
    scanf("%d", &x);

    int last = randarray[n - 1];
    randarray[n - 1] = x;
    i = 0;
    while (randarray[i] != x)
    {
        i++;
    }
    randarray[n - 1] = last;
    if (i < n - 1 || randarray[i] == x)
    {
        printf("\n %d element found at the %d position", randarray[i],i);
    }
    else
    {
        printf("\n element not found");
    }
    return 0;
}
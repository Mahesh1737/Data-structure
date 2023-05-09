#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    printf("\nElements are : ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
/* Function to swap two elements in an array */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to heapify a subtree rooted with node i */
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // Left child
    int r = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

/* Function to perform heap sort on an array */
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0;i<n;i++)
    {
       printf("enter %d element : ",i);
       scanf("%d",&arr[i]);
    }
    printf("\n%d Random Elements of Array  : ",n);
    
    printArray(arr, n);
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}

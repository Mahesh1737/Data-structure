#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[10];
    int roll;
    float per;
};

int binarySearch(struct student students[], int n, int key){
    int low=0, high=n-1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(students[mid].roll==key){
            return mid;
        }
        else if(students[mid].roll<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n,key;
    printf("Enter the total number of the student : ");
    scanf("%d",&n);

    struct student students[n];

    printf("Enter the student roll no in sorted order: \n");

    for (int i=0;i<n;i++)
    {
        printf("Enter the roll number of the student: ");
        scanf("%d",&students[i].roll);
        printf("Enter the name of the student: ");
        scanf("%s",&students[i].name);
        printf("Enter the percentage of the student: ");
        scanf("%f",&students[i].per);
    }

    printf("Student Details are as follows: \n");
    for (int i=0;i<n;i++)
    {
        printf("\nRoll number of the student: %d",students[i].roll);
        printf("\nName of the student: %s",students[i].name);
        printf("\nPercentage of the student: %f",students[i].per);
    }

    printf("\nEnter the roll no of the student to search : ");
    scanf("%d",&key);

    int binary = binarySearch(students,n,key);

    if(binary!=-1)
    {
        printf("%d student is found at the %d position\n",key, binary);
        printf("\nRoll number of the student: %d",students[binary].roll);
        printf("\nName of the student: %s",students[binary].name);
        printf("\nPercentage of the student: %f",students[binary].per);
    }
    else{
        
        printf("%d student is found no found\n",key);
    }

    return 0;
}


// PS D:\maheshhh> cd "d:\maheshhh\" ; if ($?) { gcc binary.c -o binary } ; if ($?) { .\binary }
// Enter the total number of the student : 5
// Enter the student roll no in sorted order: 
// Enter the roll number of the student: 12
// Enter the name of the student: gdfgfdg
// Enter the percentage of the student: 99
// Enter the roll number of the student: 22
// Enter the name of the student: dfgfdg
// Enter the percentage of the student: 88
// Enter the roll number of the student: 33
// Enter the name of the student: dfgfdgfdsg
// Enter the percentage of the student: 66
// Enter the roll number of the student: 44
// Enter the name of the student: dfgfdgfd
// Enter the percentage of the student: 45
// Enter the roll number of the student: 55
// Enter the name of the student: dfgdfsg
// Enter the percentage of the student: 65
// Student Details are as follows: 

// Roll number of the student: 12
// Name of the student: gdfgfdg
// Percentage of the student: 99.000000
// Roll number of the student: 22
// Name of the student: dfgfdg
// Percentage of the student: 88.000000
// Roll number of the student: 33
// Name of the student: dfgfdgfdsg
// Percentage of the student: 66.000000
// Roll number of the student: 44
// Name of the student: dfgfdgfd
// Percentage of the student: 45.000000
// Roll number of the student: 55
// Name of the student: dfgdfsg
// Percentage of the student: 65.000000
// Enter the roll no of the student to search : 44
// 44 student is found at the 3 position

// Roll number of the student: 44
// Name of the student: dfgfdgfd
// Percentage of the student: 45.000000
// PS D:\maheshhh>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition for car information
struct car {
    char name[50];
    float price;
    char manufacturer[50];
    int seating_capacity;
    float engine_capacity;
    struct car *next, *prev;
} *headl = NULL, *headr = NULL;

// Function declarations
void create();
void display();
void insert(int pos);
void deleteByPosition(int pos);
void deleteByName(char *name);
void searchByName(char *name);
void reverseList();

// Global variable
int n;  // Number of nodes

// Function to create a doubly linked list for car information
void create() {
    struct car *temp, *t;
    printf("Enter the number of cars: ");
    scanf("%d", &n);

    // First node creation
    temp = malloc(sizeof(struct car));
    temp->next = temp->prev = NULL;
    printf("Enter car 1 details:\n");
    printf("Name: ");
    scanf("%s", temp->name);
    printf("Price: ");
    scanf("%f", &temp->price);
    printf("Manufacturer: ");
    scanf("%s", temp->manufacturer);
    printf("Seating Capacity: ");
    scanf("%d", &temp->seating_capacity);
    printf("Engine Capacity: ");
    scanf("%f", &temp->engine_capacity);
    headl = headr = t = temp;

    // Creating the rest of the nodes
    for (int i = 2; i <= n; i++) {
        temp = malloc(sizeof(struct car));
        temp->next = temp->prev = NULL;
        printf("Enter car %d details:\n", i);
        printf("Name: ");
        scanf("%s", temp->name);
        printf("Price: ");
        scanf("%f", &temp->price);
        printf("Manufacturer: ");
        scanf("%s", temp->manufacturer);
        printf("Seating Capacity: ");
        scanf("%d", &temp->seating_capacity);
        printf("Engine Capacity: ");
        scanf("%f", &temp->engine_capacity);
        
        temp->prev = t;
        t->next = temp;
        t = temp;
        headr = temp;
    }

    display();
}

// Function to display the list of cars from left to right and right to left
void display() {
    if (headl == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    printf("\nDoubly linked list of cars (left to right):\nHeadl-->\n");
    struct car *temp = headl;
    while (temp != NULL) {
        printf("Car: %s, Price: %.2f, Manufacturer: %s, Seating Capacity: %d, Engine Capacity: %.2f\n", 
               temp->name, temp->price, temp->manufacturer, temp->seating_capacity, temp->engine_capacity);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nDoubly linked list of cars (right to left):\nHeadr-->\n");
    temp = headr;
    while (temp != NULL) {
        printf("Car: %s, Price: %.2f, Manufacturer: %s, Seating Capacity: %d, Engine Capacity: %.2f\n", 
               temp->name, temp->price, temp->manufacturer, temp->seating_capacity, temp->engine_capacity);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to insert a car at a specific position
void insert(int pos) {
    struct car *temp, *t;
    temp = malloc(sizeof(struct car));

    printf("Enter car details:\n");
    printf("Name: ");
    scanf("%s", temp->name);
    printf("Price: ");
    scanf("%f", &temp->price);
    printf("Manufacturer: ");
    scanf("%s", temp->manufacturer);
    printf("Seating Capacity: ");
    scanf("%d", &temp->seating_capacity);
    printf("Engine Capacity: ");
    scanf("%f", &temp->engine_capacity);

    if (pos == 1) {
        temp->next = headl;
        temp->prev = NULL;
        headl->prev = temp;
        headl = temp;
    } else {
        t = headl;
        for (int i = 1; i < pos - 1 && t != NULL; i++) {
            t = t->next;
        }
        if (t == NULL) {
            printf("Invalid position!\n");
            return;
        }
        temp->next = t->next;
        temp->prev = t;
        if (t->next != NULL) {
            t->next->prev = temp;
        }
        t->next = temp;
        if (temp->next == NULL) {
            headr = temp;
        }
    }

    n++;
    display();
}

// Function to delete a car by position
void deleteByPosition(int pos) {
    if (headl == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct car *temp;
    if (pos == 1) {
        temp = headl;
        headl = headl->next;
        if (headl != NULL) {
            headl->prev = NULL;
        } else {
            headr = NULL;
        }
        free(temp);
    } else {
        struct car *t = headl;
        for (int i = 1; i < pos - 1 && t != NULL; i++) {
            t = t->next;
        }
        if (t == NULL || t->next == NULL) {
            printf("Invalid position!\n");
            return;
        }
        temp = t->next;
        t->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = t;
        } else {
            headr = t;
        }
        free(temp);
    }

    n--;
    display();
}

// Function to delete a car by name
void deleteByName(char *name) {
    struct car *temp = headl;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Car %s not found in the list.\n", name);
        return;
    }

    if (temp == headl) {
        headl = temp->next;
        if (headl != NULL) {
            headl->prev = NULL;
        } else {
            headr = NULL;
        }
    } else if (temp == headr) {
        headr = temp->prev;
        headr->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    n--;
    display();
}

// Function to search for a car by name
void searchByName(char *name) {
    struct car *temp = headl;
    int pos = 1;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Car %s found at position %d.\n", name, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Car %s not found.\n", name);
}

// Function to reverse the doubly linked list of cars
void reverseList() {
    struct car *temp = NULL;
    struct car *current = headl;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        headl = temp->prev;
    }

    display();
}

// Main function to execute the operations
int main() {
    int choice, pos;
    char name[50];

    while (1) {
        printf("\n1. Create Car List\n2. Display Car List\n3. Insert Car\n4. Delete Car by Position\n5. Delete Car by Name\n6. Search Car by Name\n7. Reverse Car List\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert(pos);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteByPosition(pos);
            break;
        case 5:
            printf("Enter car name to delete: ");
            scanf("%s", name);
            deleteByName(name);
            break;
        case 6:
            printf("Enter car name to search: ");
            scanf("%s", name);
            searchByName(name);
            break;
        case 7:
            reverseList();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}



// Output :

// PS D:\maheshMore\Data Structure> cd "d:\maheshMore\Data Structure\" ; if ($?) { gcc doubly.c -o doubly } ; if ($?) { .\doubly }

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 1
// Enter the number of cars: 2
// Enter car 1 details:
// Name: honda
// Price: 150000
// Manufacturer: mahesh
// Seating Capacity: 5
// Engine Capacity: 56000
// Enter car 2 details:
// Name: harrier
// Price: 2000000
// Manufacturer: saurabh
// Seating Capacity: 6
// Engine Capacity: 450000

// Doubly linked list of cars (left to right):
// Headl-->
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 2

// Doubly linked list of cars (left to right):
// Headl-->
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 3
// Enter position to insert: 1
// Enter car details:
// Name: thar
// Price: 2000000
// Manufacturer: mahindra
// Seating Capacity: 5
// Engine Capacity:
// 890000

// Doubly linked list of cars (left to right):
// Headl-->
// Car: thar, Price: 2000000.00, Manufacturer: mahindra, Seating Capacity: 5, Engine Capacity: 890000.00
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// Car: thar, Price: 2000000.00, Manufacturer: mahindra, Seating Capacity: 5, Engine Capacity: 890000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 4
// Enter position to delete: 1

// Doubly linked list of cars (left to right):
// Headl-->
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// Car: honda, Price: 150000.00, Manufacturer: mahesh, Seating Capacity: 5, Engine Capacity: 56000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 5
// Enter car name to delete: honda

// Doubly linked list of cars (left to right):
// Headl-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 6
// Enter car name to search: honda
// Car honda not found.

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 6
// Enter car name to search: harrier
// Car harrier found at position 1.

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 7

// Doubly linked list of cars (left to right):
// Headl-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// Doubly linked list of cars (right to left):
// Headr-->
// Car: harrier, Price: 2000000.00, Manufacturer: saurabh, Seating Capacity: 6, Engine Capacity: 450000.00
// NULL

// 1. Create Car List
// 2. Display Car List
// 3. Insert Car
// 4. Delete Car by Position
// 5. Delete Car by Name
// 6. Search Car by Name
// 7. Reverse Car List
// 8. Exit
// Enter your choice: 8
// PS D:\maheshMore\Data Structure>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DATA STRUCTURE USED: Singly Linked List
 * Each student record is a "Node" containing student data and a pointer to the next node.
 */
struct Student {
    int roll;
    char name[30];
    float marks;
    struct Student* next;
};

// Global head pointer to store the starting address of the linked list
struct Student* head = NULL;

// 1. Add a new student to the list
void addStudent() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);
    newNode->next = NULL;

    // If the list is empty, make new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Otherwise, traverse to the end and insert
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("--> Student added successfully!\n");
}

// 2. Display all student records
void displayStudents() {
    if (head == NULL) {
        printf("\n--> No student records found!\n");
        return;
    }

    struct Student* temp = head;
    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

// 3. Search a student by Roll Number
void searchStudent() {
    if (head == NULL) {
        printf("\n--> List is empty!\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\n--> Student Found!\n");
            printf("    Roll No : %d\n", temp->roll);
            printf("    Name    : %s\n", temp->name);
            printf("    Marks   : %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("--> Student with Roll No %d not found.\n", roll);
}

// 4. Delete a student by Roll Number
void deleteStudent() {
    if (head == NULL) {
        printf("\n--> List is empty!\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    struct Student* temp = head;
    struct Student* prev = NULL;

    // If the head node itself is to be deleted
    if (temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("--> Student deleted successfully!\n");
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL) {
        printf("--> Student with Roll No %d not found.\n", roll);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("--> Student deleted successfully!\n");
}

// 5. Calculate class statistics (Total, Average, Highest)
void classStatistics() {
    if (head == NULL) {
        printf("\n--> No records available for statistics.\n");
        return;
    }

    int count = 0;
    float sum = 0.0f;
    float highest = head->marks;
    char topper[30];
    strcpy(topper, head->name);

    struct Student* temp = head;
    while (temp != NULL) {
        count++;
        sum += temp->marks;
        if (temp->marks > highest) {
            highest = temp->marks;
            strcpy(topper, temp->name);
        }
        temp = temp->next;
    }

    printf("\n--- Class Statistics ---\n");
    printf("Total Students : %d\n", count);
    printf("Average Marks  : %.2f\n", sum / count);
    printf("Highest Score  : %.2f by %s\n", highest, topper);
}

// 6. Main function with menu
int main() {
    int choice;

    while (1) {
        printf("\n=========================================\n");
        printf("    STUDENT MARKS MANAGEMENT SYSTEM      \n");
        printf("=========================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Class Statistics\n");
        printf("6. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                classStatistics();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\n[!] Invalid choice! Enter 1 to 6.\n");
        }
    }

    return 0;
}

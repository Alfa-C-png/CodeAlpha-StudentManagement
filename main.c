#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    int id;
    char name[50];
    int age;
    char department[50];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    // Step 1: Show menu to the user
    printf("===== CodeAlpha Student Management System =====\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Update Student Information\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Add Student
            if(studentCount < MAX_STUDENTS) {
                printf("Enter Name: ");
                scanf(" %[^\n]", students[studentCount].name);
                printf("Enter ID: ");
                scanf("%d", &students[studentCount].id);
                printf("Enter Age: ");
                scanf("%d", &students[studentCount].age);
                printf("Enter Department: ");
                scanf(" %[^\n]", students[studentCount].department);
                studentCount++;
                printf("Student added successfully!\n");
            } else {
                printf("Student list is full!\n");
            }
            break;

        case 2: // View All Students
            if(studentCount == 0) {
                printf("No students to display.\n");
            } else {
                for(int i = 0; i < studentCount; i++) {
                    printf("ID: %d, Name: %s, Age: %d, Department: %s\n",
                        students[i].id, students[i].name, students[i].age, students[i].department);
                }
            }
            break;

        case 3: // Search Student by ID
            {
                int searchId, found = 0;
                printf("Enter ID to search: ");
                scanf("%d", &searchId);
                for(int i = 0; i < studentCount; i++) {
                    if(students[i].id == searchId) {
                        printf("ID: %d, Name: %s, Age: %d, Department: %s\n",
                            students[i].id, students[i].name, students[i].age, students[i].department);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Student not found.\n");
                }
            }
            break;

        case 4: // Update Student Information
            {
                int updateId, found = 0;
                printf("Enter ID to update: ");
                scanf("%d", &updateId);
                for(int i = 0; i < studentCount; i++) {
                    if(students[i].id == updateId) {
                        printf("Enter new Name: ");
                        scanf(" %[^\n]", students[i].name);
                        printf("Enter new Age: ");
                        scanf("%d", &students[i].age);
                        printf("Enter new Department: ");
                        scanf(" %[^\n]", students[i].department);
                        printf("Student updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("Student not found.\n");
            }
            break;

        case 5: // Delete Student
            {
                int deleteId, found = 0;
                printf("Enter ID to delete: ");
                scanf("%d", &deleteId);
                for(int i = 0; i < studentCount; i++) {
                    if(students[i].id == deleteId) {
                        for(int j = i; j < studentCount - 1; j++) {
                            students[j] = students[j + 1];
                        }
                        studentCount--;
                        printf("Student deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("Student not found.\n");
            }
            break;

        case 6: // Exit
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
            return 1;
    }

    return 0;
}

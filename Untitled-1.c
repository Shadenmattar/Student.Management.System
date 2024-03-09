

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100


typedef struct{
    char name[50];
    int id;
    char gender;
    int academicYear;
    float GPA;
}student;
 student students[MAX_STUDENTS]=
{
{.id=1234567,.name="Yasmen Ayman",.GPA=3.5,.academicYear=3,.gender='F'}, 
{.id=1122334,.name="Mohamed Mohsen",.GPA=3.2,.academicYear=4,.gender='M'},
{.id=7654321,.name="Shaden Mohamed",.GPA=3.8,.academicYear=2,.gender='F'}
};

 student students[MAX_STUDENTS];
int numStudents = 3;



struct RemovalInfo {
    int idToRemove;
    int foundIndex;
};


void addStudent() {
    

    printf("Enter student name (First Last): ");
    scanf("%s %s", students[numStudents].name ,students[numStudents].name );
    
    printf("Enter student ID (7-digit unique number): ");
   char idString[8]; // Assuming the maximum length of input is 20 characters
    scanf("%s",&idString);

   // Check for valid student ID length
    if (strlen(idString) != 7)
    {
    printf("Error: Please enter a 7-digit number.\n");
    return;
    }

    // Convert the input string to integer
    students[numStudents].id = atoi(idString);
    
    // Check for unique ID
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].id == students[numStudents].id) 
        {
            printf("Error: Student ID must be unique.\n");
            return;
        }
    }

    printf("Enter student gender (M/F): ");
    scanf(" %c", &students[numStudents].gender);
    
// Check for valid gender
    if (students[numStudents].gender != 'M' && students[numStudents].gender != 'F') {
        printf("Error: Gender must be 'M' for Male or 'F' for Female.\n");
        return;
    }
    
    printf("Enter academic year (1-5): ");
    scanf("%d", &students[numStudents].academicYear);

    // Check for valid academic year
    if (students[numStudents].academicYear < 1 || students[numStudents].academicYear > 5) {
        printf("Error: Academic year must be between 1 and 5.\n");
        return;
    }

    printf("Enter GPA (0.0-4.0): ");
    scanf("%f", &students[numStudents].GPA);

    // Check for valid GPA
    if (students[numStudents].GPA < 0.0 || students[numStudents].GPA > 4.0) {
        printf("Error: GPA must be between 0.0 and 4.0.\n");
        return;
    }

    // Add student to the array
    students[numStudents++] = students[numStudents];
    printf("Student added successfully.\n");
}

void removeStudent() {
    // Implementation to remove a student
    struct RemovalInfo removalInfo;

    printf("Enter student ID (7-digit unique number): ");
    char idString[20]; // Assuming the maximum length of input is 20 characters
    scanf("%s", idString);

    // Check for valid student ID length
    if (strlen(idString) != 7) {
        printf("Error: Please enter a 7-digit number.\n");
        return;
    }

    // Convert the input string to integer
    removalInfo.idToRemove = atoi(idString);

    // Check for student ID existence
    removalInfo.foundIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == removalInfo.idToRemove) {
            removalInfo.foundIndex = i;
            break;
        }
    }

    // If student ID not found, print error message
    if (removalInfo.foundIndex == -1) {
        printf("ID not found: Student ID %d does not exist in the System.\n", removalInfo.idToRemove);
        return;
    }

    // Remove the student by shifting elements in the array
    for (int i = removalInfo.foundIndex; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    numStudents--; // Decrement the number of students
    printf("Operation Successful: Student with ID %d removed successfully.\n", removalInfo.idToRemove);
}



void retrieveStudent() {
    int choice, id;
    char name[50];

    printf("Enter 0 for getting data by ID or 1 for name:\n");
    scanf("%d", &choice);

    switch(choice) {
        case 0: {
            printf("Enter student ID: ");
            scanf("%d", &id);
            for (int i = 0; i < numStudents; i++) {
                if (students[i].id == id) {
                    printf("\nStudent Name: %s\n", students[i].name);
                    printf("Student ID: %d\n", students[i].id);
                    printf("Gender: %c\n", students[i].gender);
                    printf("Academic Year: %d\n", students[i].academicYear);
                    printf("GPA: %.2f\n", students[i].GPA);
                    return;
                }
            }
            printf("Student not found.\n");
            break;
        }
        case 1: {
            puts("Enter name: ");
            gets(name);
            gets(name);
            //scanf(" %s", name);
            for (int i = 0; i <numStudents; i++) {
                if (strcmp(students[i].name, name) == 0)
                 {
                    printf("\nStudent Name: %s\n", students[i].name);
                    printf("Student ID: %d\n", students[i].id);
                    printf("Gender: %c\n", students[i].gender);
                    printf("Academic Year: %d\n", students[i].academicYear);
                    printf("GPA: %.2f\n", students[i].GPA);
                      return;
                    
                }
            }
            printf("Student not found.\n");
            break;
        }
        default:
            printf("Undefined choice.\n");
    }
    
}

void updateStudent() {
    int id, choise2, index = -1;

    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter 0 to update academic year or 1 to update GPA: ");
        scanf("%d", &choise2);

        switch(choise2) {
            case 0: {
                printf("Enter your updated academic year: ");
                scanf("%d", &students[index].academicYear);
                if(students[index].academicYear<1 || students[index].academicYear>5)
                {
                    printf("Students year should be between 1 and 5\n");
                    break;
                }
                printf("Updated successfully!\n");
                break;
            }
            case 1: {
                printf("Enter your GPA: ");
                scanf("%f", &students[index].GPA);
                if(students[index].GPA<0 || students[index].GPA>4)
                {
                    printf("Students GPA should be between 0 and 4\n");
                    break;
                }
                printf("Updated successfully!\n");
                break;
            }
            default:
                printf("Undefined choice.\n");
        }
    } else {
        printf("ID not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Retrieve Student's data\n");
        printf("4. Update Student's data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                retrieveStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5);

    return 0;
}
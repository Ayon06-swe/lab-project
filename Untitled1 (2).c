#include <stdio.h>
#include <string.h>

struct Task {
    char description[100];
    int isCompleted;  
};

void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount >= 100) {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[*taskCount].description); 
    tasks[*taskCount].isCompleted = 0; 
    (*taskCount)++;

    printf("Task added successfully!\n");
}

void markTaskComplete(struct Task tasks[], int taskCount) {
    int taskNumber;

    printf("Enter task number to mark as completed: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[taskNumber - 1].isCompleted = 1;
    printf("Task marked as completed!\n");
}

void displayTasks(struct Task tasks[], int taskCount) {
    printf("\n------ To-Do List ------\n");

    if (taskCount == 0) {
        printf("No tasks available!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].isCompleted ? "Completed" : "Pending");
    }
}

int main() {
    struct Task tasks[100]; 
    int taskCount = 0;
    int choice;

    do {
        printf("\nTo-Do List Manager\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                markTaskComplete(tasks, taskCount);
                break;
            case 3:
                displayTasks(tasks, taskCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

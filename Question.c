#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // Required for wait()

int main() {
    char name[50];
    char reg_no[50];
    int age;

    // Parent process taking input
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin); // Using fgets for safer input

    printf("Enter registration number: ");
    fgets(reg_no, sizeof(reg_no), stdin); // Using fgets for safer input

    printf("Enter age: ");
    scanf("%d", &age);
    getchar(); // Consume newline left in buffer after scanf

    pid_t pid = fork(); // Creating child process

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) { 
        // Child process
        printf("\nChild Process Output:\n");
        printf("Name: %s", name);
        printf("Reg No: %s", reg_no);
        printf("Age: %d\n", age);
    }
    else {
        wait(NULL); // Parent waits for child to finish
        printf("\nParent Process: Child completed execution.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createChildProcesses(int n) {
    if (n <= 0) {
        return;
    }

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This is the child process
        printf("Child process created with PID: %d\n", getpid());
        createChildProcesses(n - 1);
        exit(0);
    } else {
        // This is the parent process
        wait(NULL); // Wait for the child to complete
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 1) {
        printf("Invalid input. Please provide a positive integer.\n");
        return 1;
    }

    createChildProcesses(n - 1); // We subtract 1 to create (2^n - 1) child processes

    return 0;
}

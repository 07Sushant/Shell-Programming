#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void createChildProcesses(int n) {
    if (n == 0) {
        return;
    }

    for (int i = 0; i < (1 << n) - 1; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            // Child process
            printf("Child process %d (PID: %d) created\n", i + 1, getpid());
            break;  // Terminate the loop in the child process
        }
    }

    // Parent process
    for (int i = 0; i < (1 << n) - 1; i++) {
        wait(NULL); // Wait for child processes to finish
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Please provide a positive integer value for n.\n");
        return EXIT_FAILURE;
    }

    printf("Creating (2^%d - 1) = %d child processes...\n", n, (1 << n) - 1);
    createChildProcesses(n);

    return EXIT_SUCCESS;
}

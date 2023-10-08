#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  // Create process P2
  pid_t pid2 = fork();
  if (pid2 == 0) {
    // P2
    // Create process P4
    pid_t pid4 = fork();
    if (pid4 == 0) {
      // P4
      // Simulate orphan process
      getppid(); // Read parent PID
      exit(0); // Exit without waiting for parent
    }

    // P2
    // Wait for child process P4 to terminate
    waitpid(pid4, NULL, 0);

    // Create process P5
    pid_t pid5 = fork();
    if (pid5 == 0) {
      // P5
      // Simulate zombie process
      exit(0); // Exit without being reaped by parent
    }

    // P2
    // Wait for child process P5 to terminate
    waitpid(pid5, NULL, 0);
  } else if (pid2 > 0) {
    // P1
    // Wait for child process P2 to terminate
    waitpid(pid2, NULL, 0);
  } else {
    // Fork failed
    perror("fork");
    exit(1);
  }

  return 0;
}





// NOTES

// Process P1 creates process P2 using the fork() system call.
// Process P2 creates process P4 using the fork() system call.
// Process P4 simulates an orphan process by exiting without waiting for its parent.
// Process P2 waits for process P4 to terminate using the waitpid() system call.
// Process P2 creates process P5 using the fork() system call.
// Process P5 simulates a zombie process by exiting without being reaped by its parent.
// Process P2 waits for process P5 to terminate using the waitpid() system call.
// Process P1 waits for process P2 to terminate using the waitpid() system call.
// After the program terminates, process P4 will be an orphan process and process P5 will be a zombie process.

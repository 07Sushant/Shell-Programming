#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid1, pid2, pid3;

  // Create process P1
  pid1 = fork();
  if (pid1 == 0) {
    printf("Process P1 created with PID %d and parent PID %d\n", getpid(), getppid());
  } else if (pid1 > 0) {
    // Create process P2 as a child of P1
    pid2 = fork();
    if (pid2 == 0) {
      printf("Process P2 created with PID %d and parent PID %d\n", getpid(), getppid());
    } else if (pid2 > 0) {
      // Create process P3 as a child of P2
      pid3 = fork();
      if (pid3 == 0) {
        printf("Process P3 created with PID %d and parent PID %d\n", getpid(), getppid());
      }
    }
  }

  // Wait for all child processes to finish before exiting
  wait(NULL);
  wait(NULL);
  wait(NULL);

  return 0;
}

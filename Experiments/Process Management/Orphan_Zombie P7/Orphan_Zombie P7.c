#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  pid_t pid;

  // Create P2
  pid = fork();
  if (pid < 0) {
    perror("Error creating P2");
    return 1;
  } else if (pid == 0) {
    printf("P2 created\n");

    // Create P4 (orphan)
    pid = fork();
    if (pid < 0) {
      perror("Error creating P4");
      return 1;
    } else if (pid == 0) {
      printf("P4 created\n");
      exit(0);
    } else {
      wait(NULL);
      printf("P4 terminated\n");
    }

    // Create P5
    pid = fork();
    if (pid < 0) {
      perror("Error creating P5");
      return 1;
    } else if (pid == 0) {
      printf("P5 created\n");

      // Create P6
      pid = fork();
      if (pid < 0) {
        perror("Error creating P6");
        return 1;
      } else if (pid == 0) {
        printf("P6 created\n");
      } else {
        wait(NULL);
        printf("P6 terminated\n");
      }
      exit(0);
    } else {
      wait(NULL);
      printf("P5 terminated\n");
    }

    exit(0);
  } else {
    // Create P3
    pid = fork();
    if (pid < 0) {
      perror("Error creating P3");
      return 1;
    } else if (pid == 0) {
      printf("P3 created\n");

      // Create P7 (zombie)
      pid = fork();
      if (pid < 0) {
        perror("Error creating P7");
        return 1;
      } else if (pid == 0) {
        printf("P7 created\n");
        while (1) {
          sleep(100);
        }
      } else {
        wait(NULL); // P3 becomes a zombie waiting for P7
        printf("P7 terminated\n");
      }

      exit(0);
    } else {
      wait(NULL);
      wait(NULL);
      printf("All child processes terminated\n");
    }
  }

  return 0;
}

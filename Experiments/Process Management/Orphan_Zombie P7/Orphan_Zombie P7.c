#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
  pid_t pid;

  // Create P2
  pid = fork();
  if (pid < 0) {
    perror("process P2 nahi ban payi");
    return 1;
  } else if (pid == 0) {
    printf("P2 created\n");

    // Create P4 (orphan)
    pid = fork();
    if (pid < 0) {
      perror("process P4 nahi ban payi");
      return 1;
    } else if (pid == 0) {
      printf("P4 bangyi (Orphan) \n");
      exit(0);
    } else {
      wait(NULL);
      printf("P4 terminated\n");
    }

    // Create P5
    pid = fork();
    if (pid < 0) {
      perror("process P5 nahi ban payi");
      return 1;
    } else if (pid == 0) {
      printf("P5 created\n");

      // Create P6
      pid = fork();
      if (pid < 0) {
        perror("process P6 nahi ban payi");
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
      perror("process P3 nahi ban payi");
      return 1;
    } else if (pid == 0) {
      printf("P3 created\n");

      // Create P7 (zombie)
      pid = fork();
      if (pid < 0) {
        perror("process P2 nahi ban payi");
        return 1;
      } else if (pid == 0) {
        printf("P7 created (Zombie) \n");
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
      printf("Sare processes terminated hogye\n");
    }
  }

  return 0;
}


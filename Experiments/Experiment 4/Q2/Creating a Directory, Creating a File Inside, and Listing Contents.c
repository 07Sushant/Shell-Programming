#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Specify the full path to the desktop directory
    const char *desktopPath = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir";

    // Create a directory on the desktop
    if (mkdir(desktopPath, 0777) == -1) {
        perror("dir nahi bani");
        return 1;
    }

    // Create a file inside the directory
    const char *filePath = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir/my_file.txt";
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("file nahi bani");
        return 1;
    }
    fprintf(file, "Hello, this is a test file!\n");
    fclose(file);

    // List the contents of the directory
    printf("Contents of the directory:\n");
system("ls -l /home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir");


    return 0;
}


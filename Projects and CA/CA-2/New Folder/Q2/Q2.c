#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    const char *desktopPath = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir";


    if (mkdir(desktopPath, 0777) == -1) {
        perror("dir nahi bani");
        return 1;
    }


    const char *filePath = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir/my_file.txt";
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("file nahi bani");
        return 1;
    }
    fprintf(file, "Hello, this is a test file!\n");
    fclose(file);


    printf("Contents of the directory:\n");
system("ls -l /home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q2/new_dir");


    return 0;
}


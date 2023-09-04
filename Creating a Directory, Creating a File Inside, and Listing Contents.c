#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Create a directory on the desktop
    if (mkdir("~/Desktop/my_directory", 0777) == -1) {
        perror("Error creating directory");
        return 1;
    }

    // Create a file inside the directory
    FILE *file = fopen("~/Desktop/my_directory/my_file.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fprintf(file, "Hello, this is a test file!\n");
    fclose(file);

    // List the contents of the directory
    system("ls -l ~/Desktop/my_directory");

    return 0;
}

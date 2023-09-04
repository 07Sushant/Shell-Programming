#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Specify the full path to the desktop directory
    const char *desktopPath = "/home/your_username/Desktop/my_directory";

    // Create a directory on the desktop
    if (mkdir(desktopPath, 0777) == -1) {
        perror("Error creating directory");
        return 1;
    }

    // Create a file inside the directory
    const char *filePath = "/home/your_username/Desktop/my_directory/my_file.txt";
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    fprintf(file, "Hello, this is a test file!\n");
    fclose(file);

    // List the contents of the directory
    system("ls -l /home/your_username/Desktop/my_directory");

    return 0;
}

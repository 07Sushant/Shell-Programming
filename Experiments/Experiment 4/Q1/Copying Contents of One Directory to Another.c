#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *source_dir, *dest_dir;
    struct dirent *entry;
    struct stat file_info;
    char source_path[256], dest_path[256];
    const char *source_directory = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q1";  // Replace with your actual source directory
    const char *dest_directory = "/home/kali/Desktop/OS LAB/Shell-Programming/Experiments/Experiment 4/Q1/Check";  // Replace with your actual destination directory

    // Open the source directory
    source_dir = opendir(source_directory);
    if (source_dir == NULL) {
        perror("source dir nahi open hui");
        return 1;
    }

    // Create the destination directory
    if (mkdir(dest_directory, 0777) == -1) {
        perror("check nam ki folder nahi bani");
        return 1;
    }

    // Read and copy files from source to destination
    while ((entry = readdir(source_dir)) != NULL) {
        snprintf(source_path, sizeof(source_path), "%s/%s", source_directory, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_directory, entry->d_name);

        if (lstat(source_path, &file_info) == 0) {
            int source_fd, dest_fd;
            char buffer[4096];
            ssize_t bytes_read;

            source_fd = open(source_path, O_RDONLY);
            dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

            while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
                write(dest_fd, buffer, bytes_read);
            }

            close(source_fd);
            close(dest_fd);
        }
    }

    // Close directories
    closedir(source_dir);

    return 0;
}


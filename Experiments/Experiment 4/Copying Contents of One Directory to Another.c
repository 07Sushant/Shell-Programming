#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
    DIR *source_dir, *dest_dir;
    struct dirent *entry;
    struct stat file_info;
    char source_path[256], dest_path[256];

    // Open the source directory
    source_dir = opendir("~/source_directory");
    if (source_dir == NULL) {
        perror("Error opening source directory");
        return 1;
    }

    // Create the destination directory
    if (mkdir("~/destination_directory", 0777) == -1) {
        perror("Error creating destination directory");
        return 1;
    }

    // Read and copy files from source to destination
    while ((entry = readdir(source_dir)) != NULL) {
        snprintf(source_path, sizeof(source_path), "~/source_directory/%s", entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "~/destination_directory/%s", entry->d_name);

        if (stat(source_path, &file_info) == 0) {
            int source_fd, dest_fd;
            char buffer[4096];
            ssize_t bytes_read;

            source_fd = open(source_path, O_RDONLY);
            dest_fd = open(dest_path, O_WRONLY | O_CREAT, 0644);

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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src_fd, dest_fd;
    char buffer[4096];
    ssize_t bytesRead;
    off_t fileSize;
    
    src_fd = open("input_first_half.txt", O_RDONLY);
    if (src_fd == -1) return 1;
    
    fileSize = lseek(src_fd, 0, SEEK_END);
    lseek(src_fd, 0, SEEK_SET);
    
    dest_fd = open("output_first_half.txt", O_CREAT | O_WRONLY, 0644);
    if (dest_fd == -1) return 1;
    
    bytesRead = read(src_fd, buffer, fileSize / 2);
    write(dest_fd, buffer, bytesRead);
    
    close(src_fd);
    close(dest_fd);
    
    return 0;
}

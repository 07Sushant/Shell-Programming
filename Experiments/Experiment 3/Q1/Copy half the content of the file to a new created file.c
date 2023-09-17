#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int src_fd, dest_fd;
    char buffer[4096];
    ssize_t bytesRead;
    off_t fileSize;
    
    // konsi file ko read krna hai 
    src_fd = open("Reading_content.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("file missing hai ya open nahi ho rahi");
        return 1;
    }
    
    // file ki size calculate krna 
    fileSize = lseek(src_fd, 0, SEEK_END);
    lseek(src_fd, 0, SEEK_SET);
    
    // konsi file me copy krna hai
    dest_fd = open("Copied_Content.txt", O_CREAT | O_WRONLY, 0644);
    if (dest_fd == -1) {
        perror("File nahi ban payi");
        close(src_fd);
        return 1;
    }
    
    // midpoint nikalo
    off_t midpoint = fileSize / 2;
    
    // read kaha se krna hai offset set kro
    lseek(src_fd, midpoint, SEEK_SET);
    
    // Copy the second half of the file
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytesRead);
    }
    
    // Close both files
    close(src_fd);
    close(dest_fd);
    
    return 0;
}

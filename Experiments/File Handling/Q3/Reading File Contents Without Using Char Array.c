#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int input_fd;
    char byte;
    
    input_fd = open("reading-display.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("file nahi mil rahi");
        return 1;
    }
    
    while (read(input_fd, &byte, 1) > 0) {
        write(STDOUT_FILENO, &byte, 1);
    }
    
    close(input_fd);
    
    return 0;
}

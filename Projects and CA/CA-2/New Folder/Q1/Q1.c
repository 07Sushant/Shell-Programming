#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int input_fd;
    char read_var;
    
    input_fd = open("read_file.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("file nahi mil rahi");
        return 1;
    }
    
    while (read(input_fd, &read_var, 1) > 0) {
        write(STDOUT_FILENO, &read_var, 1);
    }
    
    close(input_fd);
    
    return 
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


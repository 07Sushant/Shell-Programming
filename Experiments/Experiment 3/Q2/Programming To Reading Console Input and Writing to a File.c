#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int output_fd;
    char input;
    
    output_fd = open("Write in file.txt", O_CREAT | O_WRONLY, 0644);
    if (output_fd == -1) {
        perror("Apne file hi nahi banayi hai sir");
        return 1;
    }
    
    while (1) {
        scanf("%c", &input);
        if (input == '$') {
            break;
        }
        write(output_fd, &input, 1);
    }
    
    close(output_fd);
    
    return 0;
}

//Sushant
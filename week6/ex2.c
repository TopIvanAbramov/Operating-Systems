#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char* str = "Hello";
    char str2[100];
    
    int fd[2];
    
    pipe(fd);
    
    if (pipe(fd) < 0) //Error occured
        exit(1);
    
    if (fork() > 0) {
        close(fd[0]);
        write(fd[1], str, strlen(str) + 1);
        close(fd[1]);
    }
    else {
        close(fd[1]);
        read(fd[0], str2, strlen(str) + 1);
        printf("Copied string: %s\n", str2);
        close(fd[0]);
    }
    return 0;
}

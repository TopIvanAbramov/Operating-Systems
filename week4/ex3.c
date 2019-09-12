#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void read_command(char* command) {
    scanf("%[^\n]%*c", command);
}

int main() //this is a solution for 3-4 tasks
{
    int pid;
    
    while(1) {
        char* command;
        read_command(command);
        
        pid = fork();
        if (pid == 0) {
            system(command);
        }
    }
    return 0;
}

#include <printf.h>
#include <stdlib.h>
#include <zconf.h>
#include <signal.h>


int main() {
    int fd[2];
    
    if (pipe(fd) < 0) //Error occured
    exit(1);
    
    int pid = fork();
    
    if (pid == 0) {
        
        while(1) {
            printf("I am alife\n");
            sleep(1);
        }
    }
    else {
        sleep(10);
        kill(pid, SIGTERM); //Kill child process
        printf("Child process killed");
    }
    
    
    return 0;
}


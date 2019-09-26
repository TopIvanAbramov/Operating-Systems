#include <printf.h>
#include <stdlib.h>
#include <zconf.h>
#include <signal.h>

void handler() {
    printf("%s", "Print some message");
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    int fd[2], child_pid1, child_pid2, temp, child2_status;
    
    if (pipe(fd) < 0) //Error occured
    exit(1);
    
    printf("First child created\n");
    
    child_pid1 = fork();
    
    if (child_pid1 == 0) {
        
        close(fd[1]);
        read(fd[0], &temp, sizeof(int));
        printf("First child: Pid of the second child: %d\n", temp);
    
        sleep(10);
        
        printf("First child: I stopped second child\n");
        kill(temp, SIGSTOP);

        sleep(5);
        printf("First child: I continued second child\n");
        kill(temp, SIGCONT);
        sleep(5);
        printf("First child: I killed second child\n");
        kill(temp, SIGTERM);
        
    }
    else {
        printf("Second child created\n");
        
        child_pid2 = fork();
        
        if (child_pid2 == 0) {
            while (1) {
                printf("Second child: I am alive\n");
                sleep(2);
            }
        }
        else {
            close(fd[0]);
            write(fd[1], &child_pid2, sizeof(int));
            close(fd[1]);
            
            waitpid(child_pid2, &child2_status, 0);
            printf("Main process: First child killed: %d", child2_status);
            kill(child_pid2, SIGTERM);
        }
        
    }
    
    
    return 0;
}

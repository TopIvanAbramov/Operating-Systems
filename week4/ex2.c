#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int pid;
    
    for (int i = 0;  i < 3; i++) {
        pid = fork();
        printf("%d\n", pid);
        sleep(5);
     }
    
    system("pstree");
}


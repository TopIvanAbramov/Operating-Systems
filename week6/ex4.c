#include <printf.h>
#include <stdlib.h>
#include <zconf.h>

void handler_SIGKILL() {
    printf("%s", "SIGKILL hadler");
    exit(0);
}


void handler_SIGSTOP() {
    printf("%s", "SIGSTOP handler");
    exit(0);
}


void handler_SIGUSR1() {
    printf("%s", "SIGUSR1 handler");
    exit(0);
}

int main() {
    signal(SIGKILL, handler_SIGKILL);
    signal(SIGSTOP, handler_SIGSTOP);
    signal(SIGUSR1, handler_SIGUSR1);
    
    int pid = fork();
    
    while (1) {
    }
    
    return 0;
}

/*
MBP-Ivan:week6 ivan$ gcc -std=c11 ex4.c  && ./a.out&
[1] 3727
MBP-Ivan:week6 ivan$ kill -SIGUSR1 3727
[1]+  User defined signal 1: 30 gcc -std=c11 ex4.c && ./a.out

 The last line means that 1st background task ([1]) recieved ([+]) a user defined signal 1
 and shows what command created a process
*/

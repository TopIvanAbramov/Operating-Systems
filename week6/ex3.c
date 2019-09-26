#include <printf.h>
#include <stdlib.h>
#include <zconf.h>

void handler() {
    printf("%s", "Print some message");
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    while(1) {
        pause();
    }
    return 0;
}


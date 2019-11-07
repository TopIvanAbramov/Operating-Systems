#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //generate random string containing only letters and numbers
    
    system("LC_CTYPE=C tr -dc A-Za-z0-9 < /dev/urandom | head -c 10 | tee ex1.txt");
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    
    char* temp;
    int byte = 1024 * 1024  * 10;
    
    for  (int i = 0; i <  10; i++)  {
        temp = (char*) malloc(byte);
        memset(temp, 0, byte);
        i++;
        sleep(1);
    }
    
    return 0;
}

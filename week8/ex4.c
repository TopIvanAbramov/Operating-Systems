#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    
    char* temp;
    int byte = 1024 * 1024  * 10;
    struct rusage r_usage;
    
    for  (int i = 0; i <  10; i++)  {
        temp = (char*) malloc(byte);
        memset(temp, 0, byte);
        
        getrusage(RUSAGE_SELF,&r_usage);
        printf("Resident set size = %ld\nShared text memory size = %ld\n",r_usage.ru_maxrss,  r_usage.ru_ixrss);
        
        i++;
        sleep(1);
    }
    return 0;
}

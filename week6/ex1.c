#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define str char*

int main()
{
    int p[2];
    
    str str1 = "hello, world";
    char str2[strlen(str1)];

    
    if (pipe(p) < 0) //Error occured
        exit(1);
    
    write(p[1], str1, strlen(str1));
    
    read(p[0], str2, strlen(str1));
    printf("%s\n", str2);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    
    struct stat mystat = {};
    int file = open("ex1.txt", O_RDWR);
    char* text = "This is a nice day";
    
    size_t textsize = strlen(text) + 1; //size of the file
    lseek(file, textsize-1, SEEK_SET);  //stretch the file size to the size of text to write
    write(file, "", 1);
    
    char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0); //map file
    
    
    for (size_t i = 0; i < textsize; i++) {
            map[i] = text[i];
    }
    
    msync(map, textsize, MS_SYNC); //write it to disk
    munmap(map, textsize); //free the mmapped memory
    
    
    close(file); //close the file
    
    return 0;
}

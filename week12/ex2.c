#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#define SIZE 1024

void tee(int append_option, char* file_name) {
    ssize_t numBytes;
    char buffer[SIZE];
    memset(buffer, 0, SIZE);

    
    FILE* file;
    if (append_option == 1) {
        file = fopen(file_name, "a");
    }
    else {
        file = fopen(file_name, "w");
    }


    while ((numBytes = read(0, buffer, SIZE)) > 0) {  // while input from pipe exists
        
        fputs(buffer, file); //write input to output file
        fprintf(stdout, "%s", buffer); //print input
        memset(buffer, 0, sizeof(buffer)); //clear buffer
    }
    
    fclose(file);
}


int main(int argc, char *argv[]) {
    char* file_name;
    int append_option = 0;
    
    
    if (argc == 3 || argc == 4) {
        if (argc == 3) {
            file_name = argv[2];
        }
        else {
            if ((strcmp(argv[1], "tee") == 0) && ((strcmp(argv[2], "-a") == 0))) {
               append_option = 1;
               file_name = argv[3];
            }
            else {
                printf("Invalid command-line option. Valid command: tee <file> [-a] ");
            }

            
        }
        tee(append_option, file_name);
    }
    else {
        printf("Invalid command. Valid command: tee <file> [-a] ");
    }
    

    return 0;
}

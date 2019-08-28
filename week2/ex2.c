#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char* string) {   //function return the reversed string
    char* reversed_string = (char*) calloc(strlen(string), sizeof(char));
    int  j = 0;
    
    for (int i = strlen(string) - 1; i >= 0; i--) {
        reversed_string[j] = string[i];
        j++;
    }
    
    reversed_string[j] =  '\0';
    return reversed_string;
}

int main() {
    
    char* string;
    scanf("%s", string); //read a string
    
    printf("%s\n", reverse(string));
    
    return 0;
}

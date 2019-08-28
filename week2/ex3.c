#include <stdio.h>
#include <limits.h>

void print_triangle(int n) { //function prints a right-side-up triangle of height n and width 2n-1
    
    int temp = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++){
            printf(" ");
        }
        
        for (int j = 1; j <= temp; j++) {
            printf("*");
        }
        temp += 2;
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    
    char* string;
    int n;
    
    sscanf(argv[1], "%d", &n); // convert a string to int and assign to  n
    printf("%d\n", n);
    
    print_triangle(n);
    
    return 0;
}

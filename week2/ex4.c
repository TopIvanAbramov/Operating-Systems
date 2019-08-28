#include <stdio.h>

void swap(int* a, int* b) { //function swaps the value of two integers
    int temp =  *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b); //read integers from the command line
    
    swap(&a, &b);
    printf("%d %d\n", a, b);
    
    return 0;
}

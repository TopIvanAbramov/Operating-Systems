#include <stdio.h>
#include <limits.h>

int main() {
    int a; float b; double c;
    
    a = INT_MAX;
    b =  5.5;
    c =  5.44434;
    
    printf("%d  %f  %lf\n", a, b, c);
    printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("1");
    
    return 0;
}

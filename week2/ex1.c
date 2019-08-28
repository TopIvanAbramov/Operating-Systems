#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a; float b; double c;
    
    a = INT_MAX;
    b =  FLT_MAX;
    c =  DBL_MAX;
    
    printf("%d  %f  %lf\n", a, b, c);
    printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("1");
    
    return 0;
}

#include <stdio.h>
#include <limits.h>

void print_triangle_v1(int  n) {
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= temp; j++) {
            printf("*");
        }
        
        if (i <= n / 2) {
            temp += 1;
        }
        else {
            temp -= 1;
        }
        
        printf("\n");
    }
}

void print_triangle_v2(int  n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}


void print_rectangle(int  n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    print_triangle_v1(n);
    
    print_triangle_v2(n);
    
    print_rectangle(n);
    return 0;
}

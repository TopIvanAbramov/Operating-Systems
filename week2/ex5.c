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

int main(int argc, char *argv[]) {
    
    int n, type;
    
    sscanf(argv[1], "%d", &n); // convert a string to int and assign to  n
    
    printf("""Please, choose the type of figure to  print: \n \
           1 - Triangle version1 \n \
           2 - Triangle version2 \n \
           3 - Rectangle version1\n""");
    
    scanf("%d", &type);
    
    switch(type) {
        case 1 : {
            print_triangle_v1(n);
            break;
        }
            
            
        case 2 : {
            print_triangle_v2(n);
            break;
        }
            
        case 3  : {
            print_rectangle(n);
            break;
        }
            
    }
    
    
    return 0;
}

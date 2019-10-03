#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int* arr;
    int n;
    
    scanf("%d", &n);
    
    arr = (int*) calloc(n, sizeof(int));    //allocate memory for an array
    
    printf("%d\n", n);
    
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);  //deallocate array
    
    return 0;
}

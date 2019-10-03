
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimal(a, b) (((a)<(b))?(a):(b))

void* new_realloc(void* ptr, int old_size, int new_size) {
    if (new_size > 0) {
        void* new_ptr = (void*) malloc(new_size);
        
        for (int i = 0; i < minimal(old_size, new_size); i++) {
            ((char*)new_ptr)[i] = ((char*)ptr)[i];
        }
        
        free(ptr);
        return new_ptr;
    }
    else {
        free(ptr);
        return NULL;
    }
}

int main() {
    int n1, n2;

    scanf("%d: ", &n1);
    int* arr = malloc(n1 * sizeof(int));
    
    for (int i = 0; i < n1; i++) {
        arr[i] = i  * 2 - 1;
        printf("%d ", arr[i]);
    }

    scanf("%d", &n2);

    arr = (int*) new_realloc(arr, n1 * sizeof(int), n2 * sizeof(int));

    for (int i = 0; i < n2; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
}

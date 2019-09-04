#include <stdio.h>
#include <stdlib.h>

int* bubble_sort(int** a, int k) {
    
    int temp;
    int* arr = *a;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    
    int j;
    
    printf("Enter number of elements in array\n");
    scanf("%d", &j);
    int* a = (int*) calloc(j, sizeof(int));
    
    printf("Enter elements of array:\n");
    for (int i = 0; i < j; i++) {   //allocate integers in array
        scanf("%d",  &a[i]);
    }
    
    printf("\n");
    
    a = bubble_sort(&a, j);
    
    printf("Sorted array:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ",  a[i]);
    }
}

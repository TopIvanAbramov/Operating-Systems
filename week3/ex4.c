#include <stdio.h>
#include <stdlib.h>

int* quick_sort(int* a, int start, int end) {
    
    if (start < end) {
        int left = start;
        int right = end;
        int middle = a[(left + right) / 2];
        
        do
        {
            while (a[left] < middle) {
                left++;
            }
            
            while (a[right] > middle) {
                right--;
            }
            
            if (left <= right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                right--;
                left++;
            }
        } while (left <= right);
        
        quick_sort(a, start, right);
        quick_sort(a, left, end);
    }
    
    return a;
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
    
    quick_sort(a, 0, j - 1);
    
    printf("Sorted array:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ",  a[i]);
    }
}


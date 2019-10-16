#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int number_of_bits(int n) {     //return  umber of bits per number
    return (int) log2 (n) + 1;
}

//print current table: page number age of page
void print_table(int n, unsigned int arr[2][n]) {
    printf("\n________\n");
    printf("Page Age\n");
    for (int i = 0; i < n; i++) {
        printf("%u  %u\n", arr[0][i], arr[1][i]);
    }
}


int main() {
    
    int n, i, hit, miss, min_age, min_index, temp, new_page;
    FILE* file;
    
    file = fopen("input.txt", "r");
    
    if (file == NULL)
    {
       printf("Error while opening the file.\n");   //input file does not exist
        return 1;
    }
    else {
        printf("Enter number of frames: ");
        scanf("%d", &n);
        
        //2 dimensional array of pairs: page number and program counter
        unsigned int counters[2][n];
        memset(counters, 0, sizeof(unsigned int) * 2 * n);
        
        //print_table(n, counters);
        
        while (!feof (file)) {
            fscanf (file, "%d", &new_page);         //read page number from file
            
            temp = -1;
            min_age = INT_MAX;
            min_index = 0;
            
            for (i = 0; i < n; i++) {
                if (counters[0][i] == new_page)  {  //new page is in working set
                    temp = i;
                }
                
                if (counters[1][i] <= min_age) {     //find a page with minimal age
                    min_age = counters[1][i];
                    min_index = i;
                }
                counters[1][i] = counters[1][i] >> 1; //shift right counters
            }
            
            if (temp == -1) {
                counters[0][min_index] = new_page;
                counters[1][min_index] = 2147483648;
    
                miss++;
            }
            else {
                counters[1][temp] = counters[1][temp] | (1 << number_of_bits(counters[1][temp]));
                
                hit++;
            }
            
            //print_table(n, counters);
            //printf("Current hit rate: %d\nCurrent miss rate: %d\n\n", hit,  miss);
        }
        
        //print_table(n, counters);
        printf("Hit rate: %d\nMiss rate: %d\nHit/Miss: %lf\n", hit,  miss,  (double) hit/miss);
    }

    
    return 0;
}

/*
 
 10 frames:
 
 Hit rate: 11
 Miss rate: 990
 Hit/Miss: 0.011111
 
 50 frames:
 
 Hit rate: 36
 Miss rate: 965
 Hit/Miss: 0.037306
 
 100 frames:
 
 Hit rate: 36
 Miss rate: 965
 Hit/Miss: 0.037306
 */

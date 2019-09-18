#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include<time.h>

int jar[10];                    //jar
int size = 0;
pthread_mutex_t mutex;          //mutex initialization
pthread_cond_t condc, condp;

void printArr(int arr[]) {
    int i = 0;
    if (size > 0) {
        printf("Size: %d\n", size);
        while (i != size) {
            printf("%d ", jar[i]);
            i++;
        }
        printf("\n");
    }
    else {
        printf("Size: %d\n", size);
    }
}

void *producer(void *vararg) {
    while (1) {
        pthread_mutex_lock(&mutex);     //lock accesss
        
        while (size != 0) {
            pthread_cond_wait(&condp,&mutex);
        }
        size = 3;
        
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mutex);   //unlock access
        
        printf("You produced three pies\n");
        printf("\n");
        jar[size] = rand() % 100 + 1;
    }
    
    pthread_exit(0);
    
    return NULL;
}

void *consumer(void *vararg) {
    
    while (1) {
        pthread_mutex_lock(&mutex);     //lock accesss
        
        while (size == 0) {
            pthread_cond_wait(&condc,&mutex);
        }
        size = 0;
        
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mutex);   //unlock access
        
        printf("You ate one pie\n");
        //printf("\n");
        jar[size] = 0;
        //size--;
    }
    
    pthread_exit(0);
    
    
    
    return NULL;
}

int main() {
    for (int i = 0; i < 10; i++) {
        jar[i] = 0;
    }
    
    
    srand(time(0));
    printArr(jar);
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    
    pthread_t id0;
    pthread_t id1;
    pthread_t id2;
    pthread_t id3;
    
    //printf("%d \n", (int) id0);
    
    pthread_create(&id0, NULL, producer, NULL);
    //pthread_create(&id1, NULL, producer, NULL);
    
    
    pthread_create(&id2, NULL, consumer, NULL);
    //pthread_create(&id3, NULL, consumer, NULL);
    
    
    pthread_join(id0, NULL);
    //pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    //pthread_join(id3, NULL);
    
    pthread_mutex_destroy(&mutex);  //destroy mutex
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    
    
    printArr(jar);
    
    
    return 0;
}

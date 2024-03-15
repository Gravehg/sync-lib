#include <stdio.h>
#include <stdlib.h>
#include "synclib.h"
#include <unistd.h>



void *test_semaphore();


semaphore sem;

int main(){
    int nthreads = 4;
    pthread_t threads[nthreads];

    semaphore_init(&sem, 1);
    for(int i = 0; i < nthreads; i++){
        pthread_create(&threads[i],NULL, test_semaphore, NULL);
    }

    for (int i = 0; i < nthreads; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    semaphore_destroy(&sem);
    return 0;
}

void *test_semaphore(){
printf("Thread %ld attempting to acquire semaphore\n", pthread_self());
  semaphore_acquire(&sem);
  printf("Thread %ld acquired semaphore\n", pthread_self());
  sleep(2); // simulate some work
  printf("Thread %ld releasing semaphore\n", pthread_self());
  semaphore_release(&sem);
  printf("Thread %ld released semaphore\n", pthread_self());
  return NULL;
}
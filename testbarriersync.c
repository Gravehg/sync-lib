#include <stdio.h>
#include <stdlib.h>
#include "synclib.h"



barrier b;

void* say_hi();
void* say_bye();

int main(){
    int nthreads = 4;

    pthread_t threads[nthreads];

    barrier_init(&b,nthreads);

    for(int i = 0; i < nthreads; i++){
        pthread_create(&threads[i],NULL, say_hi, NULL);
    }

    for(int i = 0; i < nthreads; i++){
        pthread_join(threads[i],NULL);
    }
}

void* say_hi(){
    printf("Hello from: %ld!\n", pthread_self());
    barrier_wait(&b);
    say_bye();
}

void* say_bye(){
    printf("Goodbye from thread %ld\n", pthread_self());
}
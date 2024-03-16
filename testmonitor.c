#include "synclib.h"
#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include <unistd.h>

Monitor mon;

void *testMonitor();
void doSomething();
int testing = 0;

int main(){
    int nthreads = 4;
    pthread_t threads[nthreads];

    monitor_init(&mon);
    
    for(int i = 0; i < nthreads; i++){
        pthread_create(&threads[i],NULL, testMonitor, NULL);
    }

    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    monitor_destroy(&mon);
    return 0;
}

void *testMonitor(){
    printf("Blocking thread with monitor\n");
    monitor_enter(&mon);
    printf("Thread %ld entered. \n", pthread_self());   
    sleep(2);
    printf("Unblocking thread with monitor\n");
    monitor_exit(&mon);
    printf("Thread %ld exited. \n", pthread_self());
    return NULL;
}

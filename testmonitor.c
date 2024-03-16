#include "synclib.h"
#include <stdio.h>
#include "pthread.h"

Monitor mon;

void *testMonitor();

int main(){
    int nthreads = 4;
    pthread_t threads[4];

    monitor_init(&mon);
    
    for(int i = 0; i < nthreads; i++){
        pthread_create(&threads[i],NULL, testMonitor, NULL);
    }

}

void* testMonitor(){
    monitor_enter(&mon);
}
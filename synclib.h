#ifndef _SYNCLIB_H__
#define _SYNCLIB_H__

#include <pthread.h>
//Barrier structure
typedef struct {
  int count;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} barrier;

//Semaphore structure
typedef struct {
  int n;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} semaphore;



typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t condition;
    int data;
} Monitor;


//Barrier API calls
void barrier_init(barrier *b, int count);
void barrier_destroy(barrier *b);
void barrier_wait(barrier *b);

//Semaphore API calls
void semaphore_init(semaphore *sem, int n);
void semaphore_acquire(semaphore *sem);
void semaphore_release(semaphore *sem);
void semaphore_destroy(semaphore *sem);

//Monitor API calls
void monitor_init(Monitor *mon);
void monitor_modify_data(Monitor *mon, int new_data);
int monitor_read_data(Monitor *mon);

#endif
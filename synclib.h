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
void monitor_wait(Monitor *mon);
void monitor_signal(Monitor *mon);
void monitor_enter(Monitor *mon);
void monitor_exit(Monitor *mon);
void monitor_destroy(Monitor *mon);


#endif
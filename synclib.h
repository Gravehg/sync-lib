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

//Barrier API calls
void barrier_init(barrier *b, int count);
void barrier_destroy(barrier *b);
void barrier_wait(barrier *b);

//Semaphore API calls
void semaphore_init(semaphore *sem, int n);
void semaphore_acquire(semaphore *sem);
void semaphore_release(semaphore *sem);
void semaphore_destroy(semaphore *sem);

#endif
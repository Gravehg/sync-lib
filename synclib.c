#include <stdlib.h>
#include "synclib.h"

void barrier_init(barrier *b, int count) {
  b->count = count;
  pthread_mutex_init(&(b->mutex), NULL);
  pthread_cond_init(&(b->cond), NULL);
}

void barrier_destroy(barrier *b) {
  pthread_mutex_destroy(&(b->mutex));
  pthread_cond_destroy(&(b->cond));
}

void barrier_wait(barrier *b) {
  pthread_mutex_lock(&(b->mutex));
  b->count--;
  while (b->count > 0) {
    pthread_cond_wait(&(b->cond), &(b->mutex));
  }
  pthread_cond_broadcast(&(b->cond));
  pthread_mutex_unlock(&(b->mutex));
}

void semaphore_init(semaphore *sem, int initial_value) {
  pthread_mutex_init(&(sem->mutex), NULL);
  pthread_cond_init(&(sem->cond), NULL);
  sem->n = initial_value;
}

void semaphore_acquire(semaphore *sem) {
  pthread_mutex_lock(&(sem->mutex));
  while (sem->n <= 0) {
    pthread_cond_wait(&(sem->cond), &(sem->mutex));
  }
  sem->n--;
  pthread_mutex_unlock(&(sem->mutex));
}

void semaphore_release(semaphore *sem) {
  pthread_mutex_lock(&(sem->mutex));
  sem->n++;
  pthread_cond_signal(&(sem->cond));
  pthread_mutex_unlock(&(sem->mutex));
}

void semaphore_destroy(semaphore *sem){
    pthread_mutex_destroy(&(sem->mutex));
    pthread_cond_destroy(&(sem->cond));
}
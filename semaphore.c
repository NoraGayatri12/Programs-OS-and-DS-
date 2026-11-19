#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t sem; // Semaphore variable

// Thread function 1

void task1(void* arg) {

printf("Task 1 is waiting to enter critical section.\n");

sem_wait(&sem); // wait() operation

printf("Task 1 has entered the critical section.\n");

sleep(2); // Simulate work

printf("Task 1 is leaving the critical section.\n");

sem_post(&sem); // signal() operation

return NULL;

}

// Thread function 2

void task2(void* arg) {

printf("Task 2 is waiting to enter critical section.\n");

sem_wait(&sem); // wait() operation

printf("Task 2 has entered the critical section.\n");

sleep(2); // Simulate work

printf("Task 2 is leaving the critical section.\n");

sem_post(&sern); // signal() operation

return NULL;

}
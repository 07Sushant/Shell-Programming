#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_THREADS 3

int shared = 0;
sem_t semaphore; // Declare a semaphore

void *thread_func(void *arg) {
    int id = *(int *) arg;
    int local = 0;

    // Wait for the semaphore before accessing the shared variable.
    sem_wait(&semaphore);

    for (int i = 0; i < 1000000; i++) {
        local = shared;
        local++;
        shared = local;
    }

    // Signal the semaphore after accessing the shared variable.
    sem_post(&semaphore);

    printf("Thread %d: shared = %d\n", id, shared);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Init  semaphore to 1.
    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of shared = %d\n", shared);

    // Destroy the semaphore when done.
    sem_destroy(&semaphore);

    return 0;
}

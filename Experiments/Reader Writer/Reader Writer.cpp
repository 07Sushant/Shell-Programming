#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_variable = 0;
int readers = 0;
sem_t mutex, wrt;

void *reader(void *arg) {
    while (1) {
        sem_wait(&mutex);
        readers++;
        if (readers == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        // Reading the shared variable
        printf("Reader reads: %d\n", shared_variable);

        sem_wait(&mutex);
        readers--;
        if (readers == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);
    }
}

void *writer(void *arg) {
    while (1) {
        sem_wait(&wrt);
        // Writing to the shared variable
        shared_variable++;
        printf("Writer writes: %d\n", shared_variable);
        sem_post(&wrt);
    }
}

int main() {
    pthread_t reader_threads[3], writer_thread;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < 3; i++) {
        pthread_create(&reader_threads[i], NULL, reader, NULL);
    }

    pthread_create(&writer_thread, NULL, writer, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    pthread_join(writer_thread, NULL);

    return 0;
}

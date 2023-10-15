#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBERS 10

int numbers[MAX_NUMBERS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

int sum = 0;
int max = 0;
int min = 0;

pthread_mutex_t mutex;

void *calculateStatistics(void *arg) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        pthread_mutex_lock(&mutex);

        sum += numbers[i];

        if (numbers[i] > max) {
            max = numbers[i];
        }

        if (numbers[i] < min || i == 0) {
            min = numbers[i];
        }

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread, NULL, calculateStatistics, NULL);
    pthread_join(thread, NULL);

    printf("Average: %f\n", (float)sum / MAX_NUMBERS);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    pthread_mutex_destroy(&mutex);

    return 0;
}

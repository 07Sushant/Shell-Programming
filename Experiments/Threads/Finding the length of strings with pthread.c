#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_STRINGS 5
#define MAX_STRING_LENGTH 100

char strings[MAX_STRINGS][MAX_STRING_LENGTH] = {
    "Hello",
    "World!",
    "How",
    "are",
    "you?"
};

int lengths[MAX_STRINGS];

void *calculateStringLength(void *arg) {
    int index = *((int *)arg);
    lengths[index] = strlen(strings[index]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_STRINGS];
    int thread_args[MAX_STRINGS];

    for (int i = 0; i < MAX_STRINGS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, calculateStringLength, &thread_args[i]);
    }

    for (int i = 0; i < MAX_STRINGS; i++) {
        pthread_join(threads[i], NULL);
        printf("Length of string %d: %d\n", i, lengths[i]);
    }

    return 0;
}

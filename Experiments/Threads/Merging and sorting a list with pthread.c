#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

int numbers[MAX_NUMBERS] = {9, 5, 1, 4, 2, 7, 6, 8, 3, 0};
int merged[MAX_NUMBERS];
int sorted[MAX_NUMBERS];

pthread_t threads[3];

void *sortHalf(void *arg) {
    int thread_num = *((int *)arg);
    int start = thread_num * (MAX_NUMBERS / 2);
    int end = start + (MAX_NUMBERS / 2);
    int temp;

    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

void mergeSort() {
    for (int i = 0; i < MAX_NUMBERS / 2; i++) {
        sorted[i] = numbers[i];
    }

    int i = 0, j = MAX_NUMBERS / 2, k = 0;

    while (i < MAX_NUMBERS / 2 && j < MAX_NUMBERS) {
        if (sorted[i] <= numbers[j]) {
            merged[k++] = sorted[i++];
        } else {
            merged[k++] = numbers[j++];
        }
    }

    while (i < MAX_NUMBERS / 2) {
        merged[k++] = sorted[i++];
    }

    while (j < MAX_NUMBERS) {
        merged[k++] = numbers[j++];
    }
}

int main() {
    int thread_args[3] = {0, 1, 2};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, sortHalf, &thread_args[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    mergeSort();

    printf("Sorted and Merged List: ");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

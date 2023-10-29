#include <stdio.h>
#include <pthread.h>
#include <chrono>  // Include the chrono library
#include <thread>  // Include the thread library

int count = 0;
pthread_mutex_t box_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fullBox = PTHREAD_COND_INITIALIZER;
pthread_cond_t emptyBox = PTHREAD_COND_INITIALIZER;

int N; // Chocolates Ki Quantity
int chocolateNumber = 1; // Konsa Chocolate Khaya Bache ne

void* child_thread(void* arg) {
    printf("Starting Process Synchronization...\n");
    while (1) {
        pthread_mutex_lock(&box_mutex);
        while (count == 0) {
            pthread_cond_signal(&emptyBox);
            pthread_cond_wait(&fullBox, &box_mutex);
        }
        // Simulate getting and eating a chocolate
        printf("Bache ne %d Chocolate uthaya aur kharaha hai.\n", chocolateNumber);
        chocolateNumber++; // Increment the chocolate number

        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        count--;
        pthread_cond_signal(&fullBox); // Optional
        pthread_mutex_unlock(&box_mutex);
    }
}

void* mother_thread(void* arg) {
    pthread_mutex_lock(&box_mutex);
    // Starting me Bacha Box empty karega
    count += N;
    pthread_cond_signal(&fullBox);
    pthread_mutex_unlock(&box_mutex);

    while (1) {
        pthread_mutex_lock(&box_mutex);
        while (count > 0) {
            pthread_cond_wait(&emptyBox, &box_mutex);
        }
        // Mummy Box ko refill karenge!
        printf("Mother: Refilling the box with %d chocolates.\n", N);
        count += N;
        pthread_cond_signal(&fullBox);
        pthread_mutex_unlock(&box_mutex);
    }
}

int main() {
    printf("Box me kitne Chocolate hai? \n: ");
    scanf("%d", &N);

    pthread_t child, mother;

    // Create child and mother threads
    pthread_create(&child, NULL, child_thread, NULL);
    pthread_create(&mother, NULL, mother_thread, NULL);

    //Thread ka end hone ka wait karete hein (infinite)
    pthread_join(child, NULL);
    pthread_join(mother, NULL);

    return 0;
}

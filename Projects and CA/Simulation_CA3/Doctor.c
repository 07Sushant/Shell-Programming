#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_PATIENTS 2

sem_t mutex_patient, mutex_doctor, patient_ready, treatment_ready;
char shared_memory[100]; // Shared memory buffer
int current_patient = 1;

void* patient(void* arg) {
int patient_id = *(int*)arg;

while (1) {
// Check if it's the patient's turn
if (current_patient == patient_id) {
// Entering the doctor's office
char symptoms[100];
printf("Patient %d: Enter your symptoms: ", patient_id);
fgets(symptoms, sizeof(symptoms), stdin);

// Validate the user input
if (strlen(symptoms) == 0) {
printf("Invalid symptoms.\n");
continue;
}

// Update shared memory with symptoms
sem_wait(&mutex_patient);
snprintf(shared_memory, sizeof(shared_memory), "Symptoms: %s", symptoms);
sem_post(&mutex_doctor);
sem_post(&patient_ready); // Notify the doctor that the patient is ready for treatment

// Wait for the doctor's treatment
sem_wait(&treatment_ready);

// Access treatment details from shared memory
printf("Patient %d received treatment: %s\n", patient_id, shared_memory);

// Allow the other patient to take their turn
current_patient = 3 - patient_id; // Toggle between 1 and 2
}
}
return NULL;
}

void* doctor(void* arg) {
while (1) {
// Check if it's the doctor's turn
if (current_patient == 0) {
// Wait for a patient to be ready
sem_wait(&patient_ready);

// Access patient's symptoms from shared memory
sem_wait(&mutex_doctor);
printf("Doctor: %s\n", shared_memory);
sem_post(&mutex_doctor);

// Ask for treatment details
printf("Doctor: Provide treatment details: ");
fgets(shared_memory, sizeof(shared_memory), stdin);

// Validate the user input
if (strlen(shared_memory) == 0) {
printf("Invalid treatment details.\n");
continue;
}

// Ask for recovery time
printf("Doctor: Provide recovery time (in seconds): ");
int recovery_time;
scanf("%d", &recovery_time);
getchar(); // Consume newline character

// Validate the user input
if (recovery_time < 0) {
printf("Invalid recovery time.\n");
continue;


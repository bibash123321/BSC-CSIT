#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 5   // Number of readers before writer runs
#define TOTAL_READERS 10
#define TOTAL_WRITERS 2

sem_t rw_mutex;     // Controls access between readers/writers
sem_t mutex;        // Protects reader_count
sem_t batch_lock;   // Prevents new readers after 5 reads until writer runs

int reader_count = 0;
int read_batch = 0;

void* reader(void* arg) {
    int id = *((int*)arg);
    free(arg);

    sem_wait(&batch_lock); // Wait until allowed to read in this batch
    sem_post(&batch_lock); // Release immediately so other readers in batch can enter

    sem_wait(&mutex);
    reader_count++;
    if (reader_count == 1) {
        sem_wait(&rw_mutex);
    }
    sem_post(&mutex);

    // Reading
    printf("Reader %d is reading...\n", id);
    sleep(1);

    sem_wait(&mutex);
    reader_count--;
    read_batch++;
    if (reader_count == 0) {
        sem_post(&rw_mutex);
    }

    if (read_batch == MAX_READERS) {
        printf("5 readers finished. Waiting for writer...\n");
        sem_wait(&batch_lock); // Block new batch until writer runs
    }

    sem_post(&mutex);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *((int*)arg);
    free(arg);

    sem_wait(&rw_mutex);

    printf("Writer %d is writing...\n", id);
    sleep(2);

    read_batch = 0;         // Reset reader batch count
    sem_post(&batch_lock);  // Allow next readers batch

    sem_post(&rw_mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t r[TOTAL_READERS], w[TOTAL_WRITERS];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&batch_lock, 0, 1); // Initially allow reading

    // Create reader threads
    for (int i = 0; i < TOTAL_READERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&r[i], NULL, reader, id);
        usleep(100000); // small gap for realism
    }

    // Create writer threads
    for (int i = 0; i < TOTAL_WRITERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&w[i], NULL, writer, id);
        usleep(500000); // small gap for realism
    }

    // Wait for all threads
    for (int i = 0; i < TOTAL_READERS; i++) {
        pthread_join(r[i], NULL);
    }
    for (int i = 0; i < TOTAL_WRITERS; i++) {
        pthread_join(w[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    sem_destroy(&batch_lock);

    return 0;
}

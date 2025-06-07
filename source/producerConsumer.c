#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>

#define SHM_NAME "/prod_cons_shm"

typedef struct {
    int buffer;
    sem_t empty;
    sem_t full;
} SharedMemory;

/*31: 
Implement a simple producer-consumer problem using two processes. 
Use POSIX shared memory and semaphores to synchronize 
the producer writing an integer to a buffer and the consumer reading it
*/

int main() {
    // Crea la memoria condivisa
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedMemory)); // Alloca spazio
    SharedMemory *shm = mmap(NULL, sizeof(SharedMemory), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Inizializza i semafori (1 indica condivisione tra processi)
    sem_init(&shm->empty, 1, 1); // buffer inizialmente vuoto
    sem_init(&shm->full, 1, 0);  // nulla da consumare all'inizio

    pid_t pid = fork();

    if (pid == 0) {
        // 👷‍♂️ Processo CONSUMER
        for (int i = 0; i < 5; i++) {
            sem_wait(&shm->full);  // aspetta che ci sia qualcosa da leggere
            int value = shm->buffer;
            printf("Consumer (PID %d) read: %d\n", getpid(), value);
            sem_post(&shm->empty); // segnala che il buffer è libero
            sleep(1); // Simula elaborazione
        }
        exit(0);
    } else {
        // 👨‍🏭 Processo PRODUCER
        for (int i = 0; i < 5; i++) {
            sem_wait(&shm->empty); // aspetta che il buffer sia libero
            shm->buffer = i * 10;
            printf("Producer (PID %d) wrote: %d\n", getpid(), shm->buffer);
            sem_post(&shm->full);  // segnala che c'è un nuovo dato
            sleep(1); // Simula produzione
        }

        wait(NULL); // attende che il figlio finisca

        // Cleanup: semafori e memoria condivisa
        sem_destroy(&shm->empty);
        sem_destroy(&shm->full);
        munmap(shm, sizeof(SharedMemory));
        shm_unlink(SHM_NAME);
        printf("Producer (PID %d): done and cleaned up.\n", getpid());
    }

    return 0;
}

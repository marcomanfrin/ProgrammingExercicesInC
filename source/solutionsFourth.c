
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

#define SHM_NAME "/my_shm"
#define SEM_PROD "/sem_prod"
#define SEM_CONS "/sem_cons"

// 31. Producer-consumer using POSIX shared memory and semaphores
void producer_consumer() {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));
    int *shm_ptr = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sem_t *sem_prod = sem_open(SEM_PROD, O_CREAT, 0666, 1);
    sem_t *sem_cons = sem_open(SEM_CONS, O_CREAT, 0666, 0);

    pid_t pid = fork();

    if (pid == 0) { // Consumer
        sem_wait(sem_cons);
        printf("Consumer read: %d\n", *shm_ptr);
        sem_post(sem_prod);
        exit(0);
    } else if (pid > 0) { // Producer
        sem_wait(sem_prod);
        *shm_ptr = 42;
        printf("Producer wrote: 42\n");
        sem_post(sem_cons);
        wait(NULL);
        munmap(shm_ptr, sizeof(int));
        shm_unlink(SHM_NAME);
        sem_close(sem_prod);
        sem_close(sem_cons);
        sem_unlink(SEM_PROD);
        sem_unlink(SEM_CONS);
    }
}

// 32. Pipe communication
void pipe_communication() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid == 0) {
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
        exit(0);
    } else {
        close(fd[0]);
        const char *msg = "Hello from parent!";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
        wait(NULL);
    }
}

// 33. Simple thread
void *print_thread(void *arg) {
    printf("Hello from thread\n");
    return NULL;
}

// 34. Thread with argument
void *thread_with_arg(void *arg) {
    int val = *(int *)arg;
    printf("Thread received: %d, multiplied: %d\n", val, val * 2);
    return NULL;
}

// 35. Print even and odd using two threads
int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *print_even(void *arg) {
    while (counter <= 20) {
        pthread_mutex_lock(&lock);
        if (counter % 2 == 0) {
            printf("Even: %d\n", counter);
            counter++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *print_odd(void *arg) {
    while (counter <= 20) {
        pthread_mutex_lock(&lock);
        if (counter % 2 != 0) {
            printf("Odd: %d\n", counter);
            counter++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// 36. Unsynchronized counter
int global_counter = 0;

void *increment_counter(void *arg) {
    for (int i = 0; i < 1000000; i++)
        global_counter++;
    return NULL;
}

int main() {
    printf("Exercise 31:\n");
    producer_consumer();

    printf("\nExercise 32:\n");
    pipe_communication();

    printf("\nExercise 33:\n");
    pthread_t t1;
    pthread_create(&t1, NULL, print_thread, NULL);
    pthread_join(t1, NULL);

    printf("\nExercise 34:\n");
    pthread_t t2;
    int val = 5;
    pthread_create(&t2, NULL, thread_with_arg, &val);
    pthread_join(t2, NULL);

    printf("\nExercise 35:\n");
    pthread_t even_thread, odd_thread;
    pthread_create(&even_thread, NULL, print_even, NULL);
    pthread_create(&odd_thread, NULL, print_odd, NULL);
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    printf("\nExercise 36:\n");
    pthread_t th1, th2;
    global_counter = 0;
    pthread_create(&th1, NULL, increment_counter, NULL);
    pthread_create(&th2, NULL, increment_counter, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("Final counter value: %d (Expected: 2000000)\n", global_counter);

    return 0;
}

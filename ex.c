#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

/* 29: 
Write a program that creates a child process using fork(). 
The parent process should print its PID and the childʼs PID. 
The child should print its own PID and PPID. Make sure the parent waits for the child to finish
*/
void fork_and_wait() {
    pid_t pid = fork();  // crea un nuovo process
    if (pid < 0) {
        // Errore nella creazione del processo
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // Processo figlio
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        exit(0);  // il figlio termina
    } else {
        // Processo padre
        printf("Parent process: PID = %d, child PID = %d\n", getpid(), pid);
        wait(NULL);  // attende che il figlio termini
        printf("Child has finished\n");
    }
}

/* 30:
Write a program that creates two child processes. 
Each child should run a CPU-intensive loop printing a message every second. 
Observe the interleaving of output to understand process scheduling
*/

void two_children_v2() {
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // Primo figlio
        for (int i = 0; i < 5; i++) {
            printf("Child 1 (PID %d): iteration %d\n", getpid(), i + 1);
            sleep(1); // Simula carico CPU + rende l’output leggibile
        }
        exit(0);
    }

    // Solo il padre arriva qui e crea il secondo figlio
    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Secondo figlio
        for (int i = 0; i < 5; i++) {
            printf("Child 2 (PID %d): iteration %d\n", getpid(), i + 1);
            sleep(1);
        }
        exit(0);
    }

    // Solo il padre arriva qui
    wait(NULL); // attende primo figlio
    wait(NULL); // attende secondo figlio
    printf("Parent (PID %d): both children have finished.\n", getpid());
}



int main() {
    two_children();
    return 0;
}

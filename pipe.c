#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    // Crea la pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // 👶 Codice del FIGLIO
        close(pipefd[1]); // Chiude l'estremità di scrittura

        // Legge il messaggio dal padre
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(pipefd[0]); // Chiude l'estremità di lettura
        exit(0);
    } else {
        // 👨 Codice del PADRE
        close(pipefd[0]); // Chiude l'estremità di lettura

        // Scrive un messaggio al figlio
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]); // Chiude l'estremità di scrittura
        wait(NULL);       // Attende il figlio
    }

    return 0;
}

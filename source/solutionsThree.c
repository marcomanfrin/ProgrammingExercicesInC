
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// 21. Copy contents of input.txt to copy.txt
void copy_file() {
    FILE *src = fopen("input.txt", "r");
    FILE *dest = fopen("copy.txt", "w");
    if (!src || !dest) {
        printf("Error opening files.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);
    fclose(src);
    fclose(dest);
}

// 22. Count lines, words, and characters in a text file
void count_file_stats(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file.\n");
        return;
    }
    int lines = 0, words = 0, chars = 0;
    char ch, prev = ' ';
    while ((ch = fgetc(f)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if ((ch == ' ' || ch == '\n' || ch == '\t') && (prev != ' ' && prev != '\n' && prev != '\t'))
            words++;
        prev = ch;
    }
    fclose(f);
    words += 1;
    lines += 1;
    printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
}

// 23. Append new text to existing file
void append_file() {
    FILE *f = fopen("output.txt", "a");
    if (!f) {
        printf("Cannot open file.\n");
        return;
    }
    fprintf(f, "Appended line.\n");
    fclose(f);
}

// 24. Check file permissions
void check_file_permissions(const char *filename) {
    printf("Checking permissions for %s\n", filename);
    printf("Readable: %s\n", access(filename, R_OK) == 0 ? "Yes" : "No");
    printf("Writable: %s\n", access(filename, W_OK) == 0 ? "Yes" : "No");
    printf("Executable: %s\n", access(filename, X_OK) == 0 ? "Yes" : "No");
}

// 25. Write and read binary file
void binary_file_demo() {
    int arr[5] = {10, 20, 30, 40, 50};
    FILE *f = fopen("data.bin", "wb");
    fwrite(arr, sizeof(int), 5, f); // TODO: review
    fclose(f);

    int read_arr[5];
    f = fopen("data.bin", "rb");
    fread(read_arr, sizeof(int), 5, f);
    fclose(f);

    for (int i = 0; i < 5; i++)
        printf("%d ", read_arr[i]);
    printf("\n");
}

// 26. Append log entries with timestamps
void append_log() {
    FILE *f = fopen("log.txt", "a");
    if (!f) return;
    time_t t = time(NULL); // TODO: remeber time
    fprintf(f, "Log entry at: %s", ctime(&t));
    fclose(f);
}

// 27. List all files in a directory
void list_directory(const char *dirname) {
    DIR *dir = opendir(dirname); // TODO: posix
    if (!dir) {
        printf("Cannot open directory.\n");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);
    closedir(dir);
}

// 28. Print PID and PPID
void print_pid() {
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
}

// 29. Create child process and wait
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

// 30. Two child processes with CPU-intensive loop
void two_children() {
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            for (int j = 0; j < 5; j++) {
                printf("Child %d (PID: %d) - working...\n", i + 1, getpid());
                sleep(1);
            }
            exit(0);
        }
    }
    for (int i = 0; i < 2; i++) wait(NULL);
}
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
    printf("Exercise 21:\n");
    copy_file();

    printf("\nExercise 22:\n");
    count_file_stats("input.txt");

    printf("\nExercise 23:\n");
    append_file();

    printf("\nExercise 24:\n");
    check_file_permissions("output.txt");

    printf("\nExercise 25:\n");
    binary_file_demo();

    printf("\nExercise 26:\n");
    append_log();

    printf("\nExercise 27:\n");
    list_directory(".");

    printf("\nExercise 28:\n");
    print_pid();

    printf("\nExercise 29:\n");
    fork_and_wait();

    printf("\nExercise 30:\n");
    two_children();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

/*
Write a C program that prints the Process ID (PID) and Parent Process ID (PPID) of the running process
*/


int main() {
    pid_t pid;
    pid = fork (); 
    pid_t ppid = getpid();
    printf("PID: %d, PPID: %d\n", pid, ppid);
    return 0;
}

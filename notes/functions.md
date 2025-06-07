# 📘 Funzioni Standard in C e le loro Librerie

## stdio.h — Standard Input/Output

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `printf`      | Stampa formattata su stdout                   |
| `fprintf`     | Stampa formattata su uno stream (FILE*)       |
| `sprintf`     | Stampa formattata in una stringa              |
| `scanf`       | Legge dati formattati da stdin                |
| `fscanf`      | Legge da uno stream                           |
| `sscanf`      | Legge da una stringa                          |
| `putchar`     | Scrive un carattere su stdout                 |
| `puts`        | Scrive una stringa con newline                |
| `getchar`     | Legge un carattere da stdin                   |
| `fgets`       | Legge una stringa da uno stream               |
| `fputs`       | Scrive una stringa su uno stream              |
| `fopen`       | Apre un file                                  |
| `fclose`      | Chiude un file                                |
| `fread`       | Legge blocchi binari da file                  |
| `fwrite`      | Scrive blocchi binari su file                 |
| `fseek`       | Sposta il cursore nel file                    |
| `ftell`       | Ottiene la posizione corrente nel file        |
| `rewind`      | Riporta all’inizio del file                   |
| `feof`        | Verifica fine file                            |
| `ferror`      | Verifica errori nello stream                  |

---

## stdlib.h — Standard Library Functions

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `malloc`      | Alloca memoria dinamica                       |
| `calloc`      | Alloca memoria inizializzata a zero           |
| `realloc`     | Ridimensiona un blocco di memoria             |
| `free`        | Libera memoria allocata                       |
| `exit`        | Termina il programma                          |
| `atoi`        | Converte stringa in intero                    |
| `atof`, `atol`| Converte stringa in float/long                |
| `strtol`      | String to long con controllo                  |
| `system`      | Esegue un comando della shell                 |
| `rand`        | Numero casuale                                |
| `srand`       | Seed per rand                                 |

---

## string.h — Manipolazione di Stringhe

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `strlen`      | Lunghezza di una stringa                      |
| `strcpy`      | Copia una stringa                             |
| `strncpy`     | Copia con limite di lunghezza                 |
| `strcat`      | Concatena stringhe                            |
| `strncat`     | Concatena con limite                          |
| `strcmp`      | Confronta stringhe                            |
| `strncmp`     | Confronta con limite                          |
| `strchr`      | Trova un carattere                            |
| `strrchr`     | Trova ultima occorrenza del carattere         |
| `strstr`      | Trova sottostringa                            |
| `memcpy`      | Copia blocchi di memoria                      |
| `memmove`     | Copia sicura con sovrapposizione              |
| `memset`      | Imposta blocchi di memoria                    |
| `memcmp`      | Confronta memoria                             |

---

## time.h — Gestione del Tempo

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `time`        | Tempo corrente (epoch time)                   |
| `ctime`       | Converte `time_t` in stringa                  |
| `localtime`   | Converte `time_t` in struct tm                |
| `strftime`    | Formatta data/ora                             |
| `clock`       | Tempo CPU usato dal programma                 |

---

## ctype.h — Classificazione di Caratteri

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `isalpha`     | Verifica se è una lettera                     |
| `isdigit`     | Verifica se è una cifra                       |
| `isspace`     | Verifica se è uno spazio                      |
| `ispunct`     | Verifica punteggiatura                        |
| `toupper`     | Converte in maiuscola                         |
| `tolower`     | Converte in minuscola                         |

---

## math.h — Matematica

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `pow`         | Potenza                                       |
| `sqrt`        | Radice quadrata                               |
| `sin`         | Seno                                          |
| `cos`         | Coseno                                        |
| `tan`         | Tangente                                      |
| `log`         | Logaritmo naturale                            |
| `log10`       | Logaritmo in base 10                          |
| `fabs`        | Valore assoluto                               |
| `ceil`        | Arrotonda per eccesso                         |
| `floor`       | Arrotonda per difetto                         |

---

## pthread.h — Thread POSIX (Linux)

| Funzione           | Descrizione                              |
|--------------------|------------------------------------------|
| `pthread_create`   | Crea un thread                           |
| `pthread_exit`     | Termina un thread                        |
| `pthread_join`     | Attende la fine di un thread             |
| `pthread_mutex_*`  | Gestione mutex                          |
| `pthread_cond_*`   | Gestione condition variable              |

---

## dirent.h — Directory (POSIX)

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `opendir`     | Apre una directory                            |
| `readdir`     | Legge una voce della directory                |
| `closedir`    | Chiude la directory                           |

---

## unistd.h — Funzioni di Sistema POSIX (Linux)

| Funzione      | Descrizione                                   |
|---------------|-----------------------------------------------|
| `fork`        | Crea un processo figlio                       |
| `exec`        | Esegue un nuovo programma                     |
| `getpid`      | PID del processo                              |
| `getppid`     | PID del processo padre                        |
| `sleep`       | Attende per secondi                           |
| `usleep`      | Attende per microsecondi                      |
| `read`        | Lettura da file descriptor                    |
| `write`       | Scrittura su file descriptor                  |
| `pipe`        | Crea una pipe per comunicazione               |

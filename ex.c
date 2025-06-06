#include <stdio.h>
#include <stdlib.h>

/*
20
Write a program that opens the file output.txt, 
reads its content, and prints it on the screen
*/

int main() {
    FILE *f = fopen("output.txt", "r");
    char c;
    while ((c=fgetc(f))!=EOF){
        putchar(c);
    }
    fclose(f);
    return 0;
}

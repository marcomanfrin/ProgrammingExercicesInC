#include <stdio.h>
//TEMP FILE: here i do exercices then move it to solutions

/*
Write a program that takes a string input from the user, and prints the string backwards 
using pointer manipulation only (no indexing)
*/

void print_reverse(char *str){
    char* end = str;
    do {end++;} while(*end != '\0');
    end--;

    while (end >= str){
        printf("%c", *end);
        end--;
    }
} 

int main() {
    char input[100];
    printf("Inserisci una stringa: ");
    fgets(input, sizeof(input), stdin);

    print_reverse("ciao mondo");
    return 0;
}

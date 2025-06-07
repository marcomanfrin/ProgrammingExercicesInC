
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 11. Print string backwards using pointer only
void print_reverse(char *str) {
    char *end = str;
    while (*end != '\0') end++;
    end--;
    while (end >= str) {
        putchar(*end);
        end--;
    }
    putchar('\n');
}

// 12. Pointer to pointer demo
void pointer_to_pointer_demo() {
    int x = 5;
    printf("Value of x before modification: %d\n", x);
    int *p = &x;
    int **pp = &p;
    **pp = 10;
    printf("Value of x after modification: %d\n", x);
}

// 13. Allocate array with malloc and print
void malloc_array() {
    int *arr = /*(int *)*/malloc(10 * sizeof(int)); // cast isnt mandatory
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

// 14. Realloc array to double size and print
void realloc_array() {
    int *arr = (int *)malloc(10 * sizeof(int));
    if (!arr) return;

    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;

    arr = realloc(arr, 20 * sizeof(int)); // TODO: remember to assign realloc result
    if (!arr) return;

    for (int i = 10; i < 20; i++)
        arr[i] = i + 1;

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

// 15. Swap two integers using pointers
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 16. strlen using pointer arithmetic
int my_strlen(char *str){
    int len = 0;
    while (*str!='\0'){
        len++;
        str++;
    }
    return len;
}

// 17. 2D array access using pointer-to-pointer
void print_2d_array(int (*arr)/*[]*/[3], int rows) { // TODO: rewiew this
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 3; j++)
            printf("arr[%d][%d] = %d\n", i, j, *(*(arr + i) + j));
}

// 18. Function pointer to add and multiply
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// 19. Create a file and write a message
void write_file() {
    FILE *f = fopen("output.txt", "w");
    if (!f) {
        printf("File open failed\n");
        return;
    }
    fprintf(f, "Hello, File System!\n");
    fclose(f);
}

// 20. Read file and print content
void read_file() {
    FILE *f = fopen("output.txt", "r");
    if (!f) {
        printf("File open failed\n");
        return;
    }
    char ch;
    while ((ch = fgetc(f)) != EOF)
        putchar(ch);
    fclose(f);
}

int main() {
    printf("Exercise 11:\n");
    print_reverse("pointer");

    printf("\nExercise 12:\n");
    pointer_to_pointer_demo();

    printf("\nExercise 13:\n");
    malloc_array();

    printf("\nExercise 14:\n");
    realloc_array();

    printf("\nExercise 15:\n");
    int a = 5, b = 10;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    printf("\nExercise 16:\n");
    printf("Length: %d\n", my_strlen("hello"));

    printf("\nExercise 17:\n");
    int mat[2][3] = {{1,2,3}, {4,5,6}};
    print_2d_array(mat, 2);

    printf("\nExercise 18:\n");
    int (*fptr)(int, int);
    fptr = add;
    printf("Add: %d\n", fptr(3,4));
    fptr = multiply;
    printf("Multiply: %d\n", fptr(3,4));

    printf("\nExercise 19:\n");
    write_file();

    printf("\nExercise 20:\n");
    read_file();

    return 0;
}

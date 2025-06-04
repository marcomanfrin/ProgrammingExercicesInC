
#include <stdio.h>
#include <string.h>

// 1. Check if a number is positive, negative, or zero using if-else and switch
void check_number_if_else(int n) {
    if (n > 0)
        printf("Positive\n");
    else if (n < 0)
        printf("Negative\n");
    else
        printf("Zero\n");
}
void check_number_switch(int n) {
    switch (n) {
        case -1:
            printf("Negative\n");
            break;
        case 0:
            printf("Zero\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        default:
            printf("Number not supported in switch (only -1, 0, 1)\n");
    }
}

// 2. GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 3. Recursive factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 4. Fibonacci iterative and recursive
void stampaFibonacci(int n) {
    int a = 0, b = 1, next, i;

    if (n <= 0) {
        printf("Numero non valido.\n");
        return;
    }

    printf("Sequenza di Fibonacci (%d numeri):\n", n);

    for (i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
}
void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// 5. Palindrome check
void check_palindrome(char str[]) {
    int i = 0;
    int len = 0;
    while (str[len] != '\0') len++;
    len--; // exclude null terminator

    int is_palindrome = 1;
    while (i < len) {
        if (str[i] != str[len]) {
            is_palindrome = 0;
            break;
        }
        i++;
        len--;
    }
    if (is_palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}
int isPalindrome(char str[]) {
    int len = strlen(str); // Calcola una sola volta la lunghezza
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Non è un palindromo
        }
    }
    return 1; // È un palindromo
}

// 6. Calculator
float calculate(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default: return 0;
    }
}
int sum(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    if (b == 0) {
        printf("Division by zero error\n");
        return 0; // Handle division by zero
    }
    return a / b;
}
int calculateInt(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return sum(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            printf("Invalid operator\n");
            return 0; // Handle invalid operator
    }
}

// 7. Bubble sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 8. Matrix multiplication
void multiply_matrices(int a[][10], int b[][10], int res[][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Invalid matrix dimensions for multiplication\n");
        return;
    }

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

// 9. Pointer dereferencing
void pointer_demo() {
    int x = 42;
    int *p = &x;
    printf("Value using variable: %d\n", x);
    printf("Value using pointer: %d\n", *p);
}

// 10. Traverse array using pointer
void traverse_with_pointer() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(p + i));
    }
}
void trevers_with_pointer_2(){
    int len=5;
    int a[5] = {2, 0, 0, 4, 6}; // Declare and initialize an array of 5 integers
    int *p = a; // Pointer to the first element of the array

    for(int i=0;i<len;i++){
        printf("element %d: %d\n", i+1, *p);
        p++;
    }
}

int main() {
    printf("Exercise 1:\n");
    check_number_if_else(0);
    check_number_switch(1);

    printf("\nExercise 2:\n");
    printf("GCD of 48 and 18 is %d\n", gcd(48, 18));

    printf("\nExercise 3:\n");
    printf("Factorial of 5 is %d\n", factorial(5));

    printf("\nExercise 4:\n");
    fibonacci_iterative(10);
    printf("Fibonacci recursive of 6 is %d\n", fibonacci_recursive(6));

    printf("\nExercise 5:\n");
    check_palindrome("radar");

    printf("\nExercise 6:\n");
    printf("Calc 3.0 + 4.0 = %.2f\n", calculate(3.0, 4.0, '+'));

    printf("\nExercise 7:\n");
    int arr[5] = {5, 2, 4, 1, 3};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\nExercise 8:\n");
    int a[2][10] = {{1, 2}, {3, 4}};
    int b[2][10] = {{5, 6}, {7, 8}};
    int res[2][10];
    multiply_matrices(a, b, res, 2, 2, 2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    printf("\nExercise 9:\n");
    pointer_demo();

    printf("\nExercise 10:\n");
    traverse_with_pointer();

    return 0;
}

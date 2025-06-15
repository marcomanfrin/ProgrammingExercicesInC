### Exercices for the exam of OS programming

These exercices are designed to support learning and are a great help in preparing for the final exam. The more challenging exercises also serve as an in-depth exploration for those who wish to deepen their understanding beyond the core material

1. Write a C program that takes an integer and prints whether it is positive, negative, or zero using if-else statements. Then, rewrite the same using a switch statement for values -1, 0, and 1.
2. Write a function that takes two integers and returns their greatest common
divisor (GCD). Use this function in a main program where you read two integers and print their GCD
3. Implement a recursive function to compute the factorial of a number 
4. Write a function that prints the first N Fibonacci numbers. Use iteration and recursion variants
5. Write a program that reads a string and checks if it is a palindrome (reads the same forwards and backwards). You can treat the string as a char array without pointers
6. Implement a calculator program that takes two numbers and an operator (+, -, *, /) and returns the result. Use functions to separate logic
7. Write a function to sort an integer array using bubble sort. Test it with user input 
8. Implement multiplication of two matrices (size defined by the user). Check the validity of the sizes
9. Declare an integer variable and an integer pointer. Assign the address of the variable to the pointer. Print the variable's value using both the variable name and dereferencing the pointer
10. Create an integer array of 5 elements. Use a pointer to traverse the array and print each  element using pointer arithmetic (incrementing the pointer) 
11. Write a program that takes a string input from the user, and prints the string backwards using pointer manipulation only (no indexing)
12. Write a program that declares a pointer to an integer pointer. Assign values such that changing the value via the pointer-to-pointer changes the original integer variable. Print the values to verify
13. Write a program that allocates memory for an array of 10 integers using malloc(), fills the array with the first 10 natural numbers, prints them, and then frees the memory
14. Modify the previous program to double the size of the array using realloc(), fill the new slots with the next 10 natural numbers, print all 20 numbers, then free the memory
15. Implement a function that swaps two integers using pointers. The function should take two integer pointers as parameters and swap the values they point to. Demonstrate this in the main program
16. Implement your own strlen(). Write a function that calculates the length of a string using pointer arithmetic only, without indexing
17. Declare a 2D array of integers and access elements using pointer-to-pointer notation. Print the entire 2D array using this method
18. Write a program that declares a function pointer to a function that takes two integers and returns an integer. Use it to point to functions implementing addition and multiplication and demonstrate calling through the pointer
19. Write a program that creates a text file called output.txt and writes a simple message inside it, e.g. "Hello, File System!ˮ
20. Write a program that opens the file output.txt created in Exercise 1, reads its content, and prints it on the screen
21. Write a program that copies the content of a text file (input.txt) into another file (copy.txt)
22. Write a program that reads a text file and counts the number of lines, words, and characters it contains
23. Modify the program from Exercise 1 to append a new line of text to the existing file without overwriting the current content
24. Write a program that receives a file name as input and checks if the file is readable, writable, and executable by the current user
25. Create a program that writes an array of integers to a binary file and then reads back the data from the binary file to verify correctness
26. Write a program that appends log entries (with timestamps) to a log file every time it is run
27. Write a program that lists all files in a given directory (use POSIX functions, so this is Linux/Unix specific)
28. Write a C program that prints the Process ID (PID) and Parent Process ID (PPID) of the running process
29. Write a program that creates a child process using fork(). The parent process should print its PID and the childʼs PID. The child should print its own PID and PPID. Make sure the parent waits for the child to finish
30. Write a program that creates two child processes. Each child should run a CPU-intensive loop printing a message every second. Observe the interleaving of output to understand process scheduling
31. Implement a simple producer-consumer problem using two processes. Use POSIX shared memory and semaphores to synchronize the producer writing an integer to a buffer and the consumer reading it
32. Write a program that creates a pipe for communication between a parent and a child process. The parent sends a message string to the child through the pipe, and the child reads and prints it
33. Write a program that creates a new thread using pthread_create. The thread should print “Hello from threadˮ and terminate. The main program should wait for the thread to finish using pthread_join
34. Modify the previous program to pass an integer argument to the thread function. The thread should print the received number multiplied by 2
35. Write the two thread functions print_even and print_odd so that each prints the even and odd numbers respectively from 0 to 20. Each number should be printed on its own line
36. Write a program that creates two threads incrementing a shared global counter 1 million times each without synchronization. Run multiple times and observe the final counter value. Explain why it differs from the expected value
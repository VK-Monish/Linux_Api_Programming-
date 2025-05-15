/*
Multiple fork() Calls Demonstration in C

This program demonstrates the effect of calling fork() multiple times.
Each call to fork() creates a new child process, doubling the number of running processes.

---

Program Behavior:
- Calls fork() three times, creating 8 processes in total (2^3).
- Each process prints the value of the global variable 'i', which is 0.
- Outputs may be interleaved or appear concatenated since all processes write concurrently.
- No newline is printed after the value, so output might be jumbled.

Requirements:
- POSIX-compliant OS (Linux, Unix, macOS).
- C compiler such as GCC.

How to Compile:
    gcc multiple_fork.c -o multiple_fork

How to Run:
    ./multiple_fork

Expected Output:
- The digit '0' printed 8 times (order may vary).
- Outputs might appear mixed because processes run asynchronously.

Notes:
- Each fork duplicates the calling process, resulting in exponential growth in process count.
- The global variable 'i' is shared by value, but each process has its own copy.
- Adding '\n' after the printf output is recommended for clearer output.

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int i = 0; 
int main()
{
  fork();
  fork();
  fork();
  printf("%d",i);
}

/*
Simple fork() Return Value Demonstration in C

This program creates a child process using fork() and prints the return value of fork().

---

Program Behavior:
- Calls fork() once to create a child process.
- Prints the return value of fork() in both parent and child processes.
- In the parent process, fork() returns the child's PID (positive integer).
- In the child process, fork() returns 0.
- If fork() fails, it returns -1 (not handled explicitly here).

Requirements:
- POSIX-compliant OS (Linux, Unix, macOS).
- C compiler like GCC.

How to Compile:
    gcc fork_return_value.c -o fork_return_value

How to Run:
    ./fork_return_value

Expected Output:
- Two lines printed (order may vary):
    - One line with 0 (from the child process)
    - One line with a positive integer (child PID, from the parent process)

Notes:
- The output order is non-deterministic due to concurrent execution.
- Fork failure is not handled in this simple example.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  pid_t p = fork();
  printf("%d\n",p);
}

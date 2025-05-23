/*
 * File: basic_fork_example.c
 * Description:
 *   A simple C program demonstrating the use of `fork()` to create a child process.
 *   The parent process waits (sleeps) for 12 seconds after printing its message,
 *   while the child process immediately prints its own message.
 *
 * Functionality:
 *   - Uses `fork()` to create a new child process.
 *   - Child process prints: "I am the child process".
 *   - Parent process prints: "Hello I am the parent process" and then sleeps for 12 seconds.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc basic_fork_example.c -o basic_fork_example
 *
 *   2. Run the program:
 *      ./basic_fork_example
 *
 * Sample Output:
 *   I am the child process
 *   Hello I am the parent process
 *   (Then a 12-second pause before the parent process exits.)
 *
 * Notes:
 *   - `fork()` returns 0 in the child process and the PID of the child in the parent.
 *   - The condition `pid > 1` in the parent may skip valid PID 1 in rare special environments.
 *     Typically, `pid > 0` is used to identify the parent.
 *   - This program is useful to observe the behavior of concurrent execution.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
    printf("I am the child process\n");
  }
  else if(pid > 1)
  {
    printf("Hello I am the parent process\n");
    sleep(12);
  }
}

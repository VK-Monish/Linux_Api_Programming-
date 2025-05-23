/*
 * File: sigfpe_handler_example.c
 * Description:
 *   Demonstrates handling the floating point exception signal (SIGFPE) in C.
 *   The program triggers a division by zero to cause SIGFPE and catches it with a custom handler.
 *
 * Functionality:
 *   - Sets a signal handler `handle()` for SIGFPE using `signal()`.
 *   - Performs an integer division by zero, causing a floating point exception.
 *   - The signal handler prints an error message and terminates the program gracefully.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc sigfpe_handler_example.c -o sigfpe_handler_example
 *
 *   2. Run the program:
 *      ./sigfpe_handler_example
 *
 * Expected Output:
 *   Floating point error
 *
 * Notes:
 *   - SIGFPE is sent to a process when it performs an erroneous arithmetic operation like division by zero.
 *   - The custom handler prevents the default abrupt termination by printing a message and calling `exit(1)`.
 *   - This is useful for safely handling arithmetic exceptions in critical applications.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle()
{
  printf("Floating point error");
  exit(1);
}

int main() 
{
  signal(SIGFPE, handle);
  int a=5,b=0;
  int c= a/b;
}


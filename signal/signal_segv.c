/*
 * File: sigsegv_handler_example.c
 * Description:
 *   Demonstrates handling of segmentation fault (SIGSEGV) signals in C.
 *   The program intentionally causes a segmentation fault by dereferencing a NULL pointer.
 *   A custom signal handler catches the fault, prints an informative message, and exits gracefully.
 *
 * Functionality:
 *   - Installs a signal handler `handler()` for SIGSEGV using `signal()`.
 *   - Dereferences a NULL pointer to cause a segmentation fault.
 *   - The handler prints an explanation about the fault and a correct usage example.
 *   - The program then exits with a failure status.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc sigsegv_handler_example.c -o sigsegv_handler_example
 *
 *   2. Run the program:
 *      ./sigsegv_handler_example
 *
 * Expected Output:
 *   Segmentation fault occurred due to accessing an invalid memory location.
 *   Example of correct usage:
 *   int    a = 10
 *   int *ptr = &a
 *
 * Notes:
 *   - SIGSEGV occurs when a process attempts invalid memory access, like dereferencing NULL.
 *   - Handling SIGSEGV allows graceful program termination and user-friendly messages.
 *   - Accessing NULL pointers is a common cause of segmentation faults in C.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler()
{
  printf("Segmentation fault occurred due to accessing an invalid memory location.\n");
  printf("Example of correct usage:\n");
  printf("int    a = 10\n");
  printf("int *ptr = &a\n");
  exit(-1);
}

int main()
{
  signal(SIGSEGV,handler);

  int *ptr = NULL;
  *ptr = 100;
}

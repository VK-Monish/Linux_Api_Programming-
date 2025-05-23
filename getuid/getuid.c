/*
 * File: getuid_example.c
 * Description:
 *   Demonstrates the use of the `getuid()` system call in C.
 *   The program prints the real user ID of the process executing the program.
 *
 * Functionality:
 *   - Calls `getuid()` to retrieve the user ID of the current user.
 *   - Prints the user ID to the standard output.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc getuid_example.c -o getuid_example
 *   2. Run the program:
 *      ./getuid_example
 *   3. The output will be the numeric user ID of the user running the program.
 *
 * Notes:
 *   - `getuid()` returns the real user ID of the calling process.
 *   - Useful for programs that need to check or log which user is running them.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("getuid %d\n",getuid());
}

/*
 * File: system_call_example.c
 * Description:
 *   Demonstrates the use of the `system()` function in C to execute an external program.
 *   This program runs the executable "./a.out" from the current directory.
 *
 * Functionality:
 *   - Calls the system shell to execute the command "./a.out".
 *   - The program waits until "./a.out" finishes execution.
 *
 * How to Use:
 *   1. Ensure there is an executable file named "a.out" in the same directory.
 *   2. Compile this program:
 *      gcc system_call_example.c -o system_call_example
 *   3. Run the program:
 *      ./system_call_example
 *   4. The output and behavior depend on what "./a.out" does.
 *
 * Notes:
 *   - The `system()` function invokes the command processor (shell) to run the command.
 *   - It is a simple way to run external programs but is less secure and less flexible than exec family calls.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  system("./a.out");
}

/*
 * File: ignore_signals_example.c
 * Description:
 *   Demonstrates ignoring certain signals in a C program using the `signal()` function.
 *   The program attempts to ignore SIGINT (Ctrl+C) and SIGKILL signals.
 *   It continuously prints its process ID and a message every second.
 *
 * Functionality:
 *   - Installs signal handlers to ignore SIGINT and SIGKILL using `signal()`.
 *   - Enters an infinite loop, printing the PID and "monish" every second.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc ignore_signals_example.c -o ignore_signals_example
 *
 *   2. Run the program:
 *      ./ignore_signals_example
 *
 *   3. Try pressing Ctrl+C (SIGINT) to test if it is ignored.
 *      Note: SIGKILL cannot be caught or ignored by any process.
 *
 * Important Notes:
 *   - SIGINT can be caught or ignored by a process, so the program ignores Ctrl+C.
 *   - SIGKILL cannot be caught or ignored; the attempt to ignore it will fail silently.
 *   - The program will continue running until terminated by SIGKILL, SIGTERM, or other non-ignorable signals.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
  signal(SIGINT,SIG_IGN);
  signal(SIGKILL,SIG_IGN);
  
  while(1)
  {
    sleep(1);
    printf("%d\n",getpid());
    printf("monish\n");
  }
}

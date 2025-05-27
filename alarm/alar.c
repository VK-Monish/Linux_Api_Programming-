/*
 * File: alarm_signal_timer.c
 * Description:
 *   This program demonstrates the use of the SIGALRM signal in Linux.
 *   It sets a timer for 5 seconds using `alarm()` and waits for the signal.
 *   Once the alarm goes off, the registered signal handler (`handle`) is executed.
 *
 * How It Works:
 *   - `signal(SIGALRM, handle);` registers the `handle()` function as the signal handler.
 *   - `alarm(5);` schedules the SIGALRM signal to be delivered after 5 seconds.
 *   - `sleep(10);` makes the process sleep for 10 seconds to ensure the signal has time to trigger.
 *   - When the alarm goes off, `handle()` prints "The times up" and terminates the program with `exit(-1)`.

 * Output:
 *   wait for signal
 *   The times up
 *
 * Notes:
 *   - `exit(-1)` typically indicates an error. Use `exit(0)` for a normal exit if appropriate.
 *   - The signal may interrupt `sleep()`, so the program might not sleep the full 10 seconds.
 *   - `SIGALRM` is commonly used for timeouts and scheduling single-time events in programs.

 * Usage:
 *   Compile: gcc alarm_signal_timer.c -o alarm_timer
 *   Run: ./alarm_timer

 * Suggestions for Improvement:
 *   - Use `sigaction()` instead of `signal()` for more reliable and portable signal handling.
 *   - Print the current time before and after the alarm for demonstration purposes.
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handle()
{
  printf("The times up\n");
  exit(-1);
}

int main()
{
  signal(SIGALRM,handle);
  alarm(5);

  printf("wait for signal\n");
  sleep(10);
}

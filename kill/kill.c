/*
 * File: send_signal.c
 * Description:
 *   This program demonstrates how to send a signal to another process using the `kill()` system call.
 *   It attempts to send the `SIGTERM` signal (termination request) to a process with a specific PID.
 *
 * How It Works:
 *   - The target process ID (PID) is hardcoded as 37186.
 *   - `kill(pid, SIGTERM)` sends the termination signal to the process identified by `pid`.
 *   - If `kill()` returns -1, it means the signal sending failed (e.g., invalid PID, insufficient permissions).
 *   - On failure, an error message is printed using `perror()`.
 *   - On success, a confirmation message is printed.
 *
 * Output Example:
 *   Signal sent to process 37186
 *   or
 *   kill failed: No such process
 *
 * Notes:
 *   - `kill()` does not necessarily terminate the process; it sends the signal, and the process decides how to handle it.
 *   - The PID must be replaced with the actual target process ID on your system.
 *   - Common signals include SIGTERM (terminate), SIGKILL (force kill), SIGINT (interrupt), etc.
 *
 * Usage:
 *   Compile: gcc send_signal.c -o send_signal
 *   Run: ./send_signal
 *   Ensure the PID corresponds to a running process and you have permission to send signals to it.
 *
 * Suggestions:
 *   - Modify the program to accept the PID and signal as command-line arguments for flexibility.
 *   - Handle different signals or add signal validation.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
  int ki;
  pid_t pid = 37186;
  ki = kill(pid,SIGTERM);
  if (ki == -1) 
  {
    perror("kill failed");
    return 1;
  }
  printf("Signal sent to process %d\n", pid);
}

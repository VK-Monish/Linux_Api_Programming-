/*
 * File: orphan_process_demo.c
 * Description:
 *   Demonstrates orphan process behavior using `fork()` and `sleep()`.
 *   Shows how the child process's parent process ID (`ppid`) changes after
 *   the original parent exits, typically becoming `init` (PID 1).
 *
 * Functionality:
 *   - The program creates a child process using `fork()`.
 *   - The parent process prints its PID and exits immediately.
 *   - The child process prints its PID and PPID before and after a 15-second sleep.
 *   - This illustrates how the PPID changes if the parent terminates during the child's sleep.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc orphan_process_demo.c -o orphan_process_demo
 *
 *   2. Run the program:
 *      ./orphan_process_demo
 *
 * Sample Output:
 *   parent process         3456
 *   The child process      3457
 *   The child process ppid 3456
 *   Before
 *   (15-second pause)
 *   The child process      3457
 *   The child process ppid 1
 *   After
 *
 * Notes:
 *   - When the parent process exits before the child, the child becomes an orphan.
 *   - The orphaned child is reparented to the `init` process (usually PID 1).
 *   - This is a key concept in understanding process management in Unix/Linux systems.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t pid;
  pid = fork();
  if(pid > 0)
  {
    printf("parent process         %d\n",getpid());
  }
  else if (pid == 0)
  {
    printf("The child process      %d\n",getpid());
    printf("The child process ppid %d\n",getppid());
    printf("Before\n");
    sleep(15);
    printf("The child process      %d\n",getpid());
    printf("The child process ppid %d\n",getppid());
    printf("After\n");

  }
}

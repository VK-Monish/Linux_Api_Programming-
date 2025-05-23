/*
 * File: execl_fork_run.c
 * Description:
 *   Demonstrates the use of `fork()` and `execl()` system calls to execute
 *   an external program from a child process after forking.
 *
 * Functionality:
 *   - The program creates a child process using `fork()`.
 *   - The child process uses `execl()` to replace itself with the executable located at /home/moni/bin/a.out.
 *   - The parent process simply prints its own process ID.
 *
 * How to Use:
 *   1. Ensure that the executable `/home/moni/bin/a.out` exists and has execution permissions.
 *      Example `a.out` content:
 *
 *      ```c
 *      #include <stdio.h>
 *      int main() {
 *          printf("This is a.out executed by the child process.\n");
 *          return 0;
 *      }
 *      ```
 *
 *      Compile with:
 *      gcc aout_source.c -o /home/moni/bin/a.out
 *
 *   2. Compile this file using:
 *      gcc execl_fork_run.c -o execl_fork_run
 *
 *   3. Run the compiled binary:
 *      ./execl_fork_run
 *
 * Output Example:
 *   Parent process prints its PID:
 *     4567
 *   Child process prints the output from a.out:
 *     This is a.out executed by the child process.
 *
 * Notes:
 *   - `execl()` replaces the child process image, so no code after execl() in the child will run unless execl fails.
 *   - The first argument to `execl()` is the path to the executable.
 *   - The second argument is conventionally `argv[0]`, which in this case is "ls" (can be any name, not required to be accurate).
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
    execl("/home/moni/bin/a.out", "ls", NULL);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

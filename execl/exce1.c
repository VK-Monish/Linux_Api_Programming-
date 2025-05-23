/*
 * File: execl_example.c
 * Description:
 *   This program demonstrates the use of `fork()` and `execl()` system calls in C.
 *
 * Functionality:
 *   - The parent process forks a child process.
 *   - The child process uses `execl()` to replace its image with another executable (./a.out).
 *   - The parent process prints its own PID and continues execution.
 *
 * How to Use:
 *   1. Make sure there is an executable file named `a.out` in the same directory.
 *      Example `a.out` code:
 *
 *      ```c
 *      // a.out source
 *      #include <stdio.h>
 *      int main(int argc, char *argv[]) {
 *          printf("Child Process Executed: %s\n", argv[0]);
 *          return 0;
 *      }
 *      ```
 *
 *   2. Compile this program using:
 *      gcc execl_example.c -o execl_example
 *
 *   3. Run the program:
 *      ./execl_example
 *
 * Expected Output:
 *   - The parent prints its PID.
 *   - The child runs `a.out` and prints the message from that program.
 *
 * Notes:
 *   - `execl()` replaces the current process image with a new process image.
 *   - "./a.out" must be present and executable.
 *   - The first argument passed to `execl()` after the file path is conventionally the program name (`argv[0]`).
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
    execl("./a.out","hello", NULL);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

/*
 * File: execv_ls_example.c
 * Description:
 *   This program demonstrates the use of `fork()` and `execv()` system calls in C.
 *   It executes the `ls -l` command in the child process using the `execv()` function.
 *
 * Functionality:
 *   - The parent process forks a child process.
 *   - The child process replaces itself with the `/usr/bin/ls -l` command using `execv()`.
 *   - The parent process prints its own PID and terminates.
 *
 * How to Use:
 *   1. Compile the program:
 *      gcc execv_ls_example.c -o execv_ls_example
 *
 *   2. Run the program:
 *      ./execv_ls_example
 *
 * Expected Output:
 *   - The child process runs `ls -l`, listing files in the current directory.
 *   - The parent prints its process ID (PID), e.g.:
 *     4567
 *     (followed by the output of `ls -l` from the child)
 *
 * Notes:
 *   - `execv()` replaces the current process image with the specified program.
 *   - `argv[0]` should contain the full path to the command, `/usr/bin/ls` in this case.
 *   - The second argument to `execv()` is an array of arguments, ending with `NULL`.
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
  char *argv[]={"/usr/bin/ls","-l",NULL};
  if(pid == 0)
  {
    //int execv(const char *pathname, char *const argv[]);
    execv(argv[0],argv);
  }
  else
  {
    printf("%d\n",getpid());
  }
}


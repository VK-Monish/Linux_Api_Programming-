/*
 * File: execvp_ls_example.c
 * Description:
 *   This program demonstrates the use of `fork()` and `execvp()` system calls in C.
 *   It executes the `ls -l` command from the child process using `execvp()`.
 *
 * Functionality:
 *   - The program creates a child process using `fork()`.
 *   - The child process replaces its execution image with the `ls -l` command using `execvp()`.
 *   - The parent process prints its own process ID (PID) and exits.
 *
 * How to Use:
 *   1. Compile the program using:
 *      gcc execvp_ls_example.c -o execvp_ls_example
 *
 *   2. Run the program:
 *      ./execvp_ls_example
 *
 * Expected Output:
 *   - Output of `ls -l` (from the child process).
 *   - The parent process prints its PID (e.g., 4567).
 *
 * Notes:
 *   - `execvp()` searches for the command in the system's `PATH`, so only the command name ("ls") is needed.
 *   - The `argv` array must be null-terminated and the first element must be the command name itself.
 *   - After `execvp()` is called in the child, no further code in the child process runs unless the call fails.
 *
 * Example:
 *   Terminal output:
 *     4567
 *     total 8
 *     -rwxr-xr-x 1 user user  1234 May 23 12:00 execvp_ls_example
 *     ...
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
    //int execvp(const char *file, char *const argv[]);
    execvp("ls",argv);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

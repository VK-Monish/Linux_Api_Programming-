/*
 * File: exec_env_example.c
 * Description:
 *   This program demonstrates how to use fork and execvpe system calls
 *   to execute a new program with a custom environment from a child process.
 *
 * Usage:
 *   1. Compile the program: gcc exec_env_example.c -o exec_env_example
 *   2. Ensure that '/home/moni/bin/a.out' exists and is executable.
 *      This is the program that will be executed by the child process.
 *   3. Run the program: ./exec_env_example
 *
 * Program Behavior:
 *   - The parent process forks a child.
 *   - The child process executes the program "a.out" using execvpe,
 *     with a custom environment variable "MY_PATH=1234".
 *   - The parent process prints its PID and terminates.
 *
 * Example Output:
 *   Parent PID: 4321
 *   Child Process: MY_PATH = 1234   (Printed by a.out if it uses getenv)
 *
 * Notes:
 *   - The environment variable MY_PATH is set only for the child process.
 *   - The child executes /home/moni/bin/a.out, so make sure this path is correct.
 *   - execvpe is a GNU extension and might not be available on all systems.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
int main()
{
  char*argv[]={"/home/moni/bin/a.out",NULL};
  pid_t pid = fork();
  if (pid == 0)
  {
    char*evp[2] = {"MY_PATH=1234",NULL};
    execvpe("a.out",argv,evp);
  }
  else
  {
    printf("Parent PID: %d\n", getpid());
  }
}


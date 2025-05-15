/*
Fork with Parent and Child Process Identification in C

This program demonstrates the use of fork() to create a child process, with proper error handling.
It distinguishes between the parent and child processes by printing different messages.

---

Program Behavior:
- Calls fork() to create a child process.
- Checks if fork() failed and prints an error if so.
- If in the child process (fork() returns 0), prints a child-specific message.
- If in the parent process (fork() returns child's PID), prints a parent-specific message.

Requirements:
- POSIX-compliant operating system (Linux, Unix, macOS).
- C compiler (e.g., GCC).

How to Compile:
    gcc fork_parent_child.c -o fork_parent_child

How to Run:
    ./fork_parent_child

Expected Output (order may vary):
- "This called by the parent process : child process"  (from child process)
- "This is parent process"                             (from parent process)

Notes:
- Output order is non-deterministic due to concurrent execution of processes.
- Proper error handling included for fork() failure.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  pid_t p = fork();
  if (p<0)
  {
    perror("fork fail");
    exit(-1);
  }
  else if (p == 0)
  {
    printf("This called by the parent process : child process");
  }
  else
  {
    printf("This is parent process\n");
  }
}

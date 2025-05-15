/*
Simple fork() Demonstration in C

This program creates a new process using the fork() system call.
Both the parent and child processes will print "Hello world!" along with their process ID (PID).

---

Features:
- Creates a child process via fork().
- Prints the process ID of each process.
- Handles fork() failure with an error message.

Requirements:
- POSIX-compliant operating system (Linux, Unix, macOS).
- C compiler like GCC.

How to Compile:

    gcc fork_example.c -o fork_example

How to Run:

    ./fork_example

Expected Output (order may vary):

    Hello world!, process_id(pid) = 1234
    Hello world!, process_id(pid) = 1235

Note:
- Output order is not guaranteed because parent and child run concurrently.
- Each process prints its own PID.
- If fork fails, the program prints an error and exits.

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t p = fork();
    if(p<0){
      perror("fork fail");
      exit(1);
    }
    printf("Hello world!, process_id(pid) = %d \n",getpid());
    return 0;
}

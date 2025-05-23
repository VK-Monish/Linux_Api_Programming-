/*
 * File: fork_file_rw.c
 * Description: Demonstrates file read/write operations with forked child and parent processes.
 *
 * Usage:
 *   Compile: gcc fork_file_rw.c -o fork_file_rw
 *   Run: ./fork_file_rw <filename>
 *
 * Functionality:
 *   - The program opens or creates a file given as a command-line argument.
 *   - The parent process writes a string ("Hi iam Monish Kumar") into the file.
 *   - The child process, after fork, attempts to read from the same file and prints the content.
 *
 * Note:
 *   - The child opens the file independently after the fork.
 *   - The file descriptor `fd` in the child process is not used and closed unnecessarily.
 *   - Because of lack of synchronization, the child might read the file *before* the parent writes to it.
 *     Use `wait()` or other synchronization methods to ensure proper execution order if needed.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char*argv[]) 
{
  pid_t pid;
  int fd = open(argv[1], O_CREAT | O_RDWR);

  pid = fork();
  if (pid == 0) 
  {
    char buffer[100];
    int fd_read = open(argv[1], O_CREAT | O_RDWR);
    int n = read(fd_read,buffer, sizeof(buffer));
    printf("Child read: %s\n", buffer);
    close(fd);
  } 
  else 
  {
    char *sou = "Hi iam Monish Kumar";
    write(fd, sou, strlen(sou));
  }
}

/*
 * File: mkdir_example.c
 * Description:
 *   This program demonstrates how to create a new directory in C using the `mkdir()` system call
 *   from <sys/stat.h>. It attempts to create a directory named "hello" with permission 0766.
 *
 * Usage:
 *   Compile: gcc mkdir_example.c -o mkdir_example
 *   Run: ./mkdir_example
 *
 * Behavior:
 *   - If the directory "hello" does not already exist, it will be created with read, write, and execute
 *     permissions for the owner, and read and write permissions for group and others.
 *   - If the directory already exists or creation fails for another reason, an error message will be displayed
 *     using perror().
 *
 * Note:
 *   The permissions `0766` correspond to:
 *     - Owner: read, write, execute (7)
 *     - Group: read, write (6)
 *     - Others: read, write (6)
 */

#include <stdio.h>
#include <sys/stat.h>

int main(int argc,char*argv[])
{
  int fd;
  fd = mkdir("hello",0766);
  if(fd == -1)
  {
    perror("mkdir");
  }
}

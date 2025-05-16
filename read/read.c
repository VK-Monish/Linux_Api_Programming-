/*
 * file_read_example.c
 *
 * This program demonstrates basic file reading in C using low-level system calls:
 * `open()`, `read()`, and `close()`.
 *
 * Steps performed:
 * 1. Opens the file named "demo.c" in read-only mode using `open()`.
 * 2. Reads up to 1000 bytes from the file into a buffer using `read()`.
 * 3. Prints the contents of the buffer to standard output using `printf()`.
 *
 * Usage:
 *   gcc file_read_example.c -o file_read_example
 *   ./file_read_example
 *
 * Notes:
 * - This program expects that a file named "demo.c" exists in the current directory.
 * - It reads only up to the first 1000 bytes. If the file is longer, the rest is ignored.
 * - Always ensure the file descriptor (`fd`) is successfully opened before using it.
 * - The program currently does not close the file descriptor; for best practices,
 *   consider adding `close(fd);` after reading to release resources.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  int fd,openflag;
  char buf[1000];
  ssize_t bytescnt;
  fd = open("demo.c",O_RDONLY);
  if(fd == -1)
  {
    printf("error in opening file");
  }
  bytescnt = read(fd,buf,1000);
  printf("%s",buf);
}

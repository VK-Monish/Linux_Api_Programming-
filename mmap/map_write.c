/*
 * mmap_write_example.c
 *
 * This program demonstrates how to use memory-mapped files (`mmap`) in C.
 * 
 * Steps performed:
 * 1. Opens the file provided as a command-line argument in read-write mode.
 * 2. Truncates the file size to 100 bytes using `ftruncate()`.
 * 3. Maps the file into the process's memory using `mmap()`.
 * 4. Writes the string "Hello mmap" directly to the mapped memory.
 * 5. Uses `getchar()` to pause execution at key steps so you can inspect the memory/file.
 * 6. Unmaps the memory using `munmap()`.
 *
 * Usage:
 *   gcc mmap_write_example.c -o mmap_write_example
 *   ./mmap_write_example <filename>
 *
 * Notes:
 * - The target file must exist before running the program.
 * - After execution, the contents of the file will be modified.
 * - This example demonstrates `MAP_SHARED` mode, so changes are reflected in the file.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
  printf("pid %d\n", getpid());
  int fd = open(argv[1], O_RDWR);
  ftruncate(fd, 100);
  getchar(); 
  char *data = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  strcpy(data, "Hello mmap");
  getchar(); 
  munmap(data, 100);
}

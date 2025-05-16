/*
 * file_create_write.c
 *
 * Description:
 * This program demonstrates how to create a file and write content to it using 
 * low-level system calls in C: `open()` and `write()`.
 *
 * How it works:
 * 1. It defines the file open flags (`O_CREAT | O_WRONLY`) to create a file
 *    if it does not exist and open it in write-only mode.
 * 2. It sets the file permission bits to allow read/write for the owner and
 *    read for the group and others.
 * 3. The filename is expected as a command-line argument (`argv[1]`).
 * 4. It writes the string "School of linux" into the file.
 *
 * Compilation:
 *   gcc file_create_write.c -o file_create_write
 *
 * Usage:
 *   ./file_create_write <filename>
 *
 * Example:
 *   ./file_create_write output.txt
 *
 * Notes:
 * - Be sure to pass a filename as an argument, or the program will crash.
 * - Always check the return values of `open()` and `write()` in real applications.
 * - Use `close(fd);` after writing to release the file descriptor.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
  int fd,openflag;
  mode_t fileperm;
  char *buf = "School of linux";
  openflag  = O_CREAT | O_WRONLY ; 
  fileperm  = S_IRUSR | S_IWUSR | S_IRGPR | S_IWGPR | S_IROTH ;
//size_t write(int fd, const void buf[.count], size_t count);
  fd = open(argv[],openflag,fileperm);
}

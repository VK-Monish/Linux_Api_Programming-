/*
 * check_file_exists.c
 *
 * Description:
 * This program demonstrates how to check for the existence of a file using the
 * `open()` system call in C. It attempts to open a file named "moni.c" in read-only mode.
 *
 * How it works:
 * - The program uses `open()` with the `O_RDONLY` flag to attempt to open "moni.c".
 * - If the file does not exist or cannot be opened, `open()` returns -1.
 * - The program then prints "No such file" if the file cannot be opened.
 *
 * Compilation:
 *   gcc check_file_exists.c -o check_file_exists
 *
 * Usage:
 *   ./check_file_exists
 *
 * Notes:
 * - This is a simple way to check if a file is present.
 * - In a real-world application, consider using `access()` or `stat()` if you
 *   only need to check for existence without opening the file.
 * - It is good practice to include `<unistd.h>` and handle other possible errors too.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fd;
  fd = open("moni.c",O_RDONLY);
  if(fd == -1)
  {
    printf("No such file");
  }
}

/*
 * file_info_stat.c
 *
 * This program demonstrates the use of the `stat()` system call in C
 * to retrieve and display metadata about a file.
 *
 * Steps performed:
 * 1. Accepts a filename as a command-line argument.
 * 2. Uses `stat()` to get file information such as size, mode, UID, and GID.
 * 3. Prints the file name, size in bytes, file permissions (mode), user ID (UID),
 *    and group ID (GID) to the terminal.
 *
 * Usage:
 *   gcc file_info_stat.c -o file_info_stat
 *   ./file_info_stat <filename>
 *
 * Example:
 *   ./file_info_stat demo.txt
 *
 * Notes:
 * - The program expects the user to pass a valid filename as the first argument.
 * - It uses `perror()` to report any errors during the `stat()` system call.
 * - `st_mode` prints the raw mode value. To decode file type and permissions in a human-readable format,
 *   additional processing (e.g., using macros like `S_ISREG`, `S_IRUSR`, etc.) is required.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[])
{
  int fd;
  struct stat st;
  fd = stat(argv[1],&st);
  if(fd == -1)
  {
    perror("stat");
  }
  printf("File Name %s\n",argv[1]);
  printf("File size %ld\n",st.st_size);
  printf("file mode %d\n",st.st_mode);
  printf("File uid  %d\n",st.st_uid);
  printf("File gid  %d\n",st.st_gid);
}

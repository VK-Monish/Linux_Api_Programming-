/*
File Write with lseek Example in C

This program demonstrates how to open or create a file, move the file pointer to a specific position using `lseek`, and write data starting from that position.

---

Program Behavior:
- Opens the file "example.c" with read/write permissions; creates it if it does not exist.
- Sets file permissions to allow read, write, and execute for user and group.
- Moves the file pointer 10 bytes from the beginning of the file.
- Writes the string "school of linux" starting at the 10th byte offset.
- Closes the file descriptor.

Requirements:
- POSIX-compliant OS.
- C compiler (e.g., GCC).

How to Compile:
    gcc file_lseek_write.c -o file_lseek_write

How to Run:
    ./file_lseek_write

Notes:
- If "example.c" already exists, this will overwrite bytes starting at offset 10.
- `lseek` allows random access to files by setting the file descriptor's offset.
- File permissions set with `S_IRWXU | S_IRWXG` allow user and group to read, write, and execute.
- No error messages printed except returning 1 on open failure (can be improved).
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() 
{
    int fd = open("example.c", O_RDWR | O_CREAT,S_IRWXU | S_IRWXG);
    if (fd == -1) 
    {
      return 1;
    }
    lseek(fd, 10, SEEK_SET); // Move file pointer 10 bytes from beginning
    write(fd, "school of linux", 16);       // Write 'A' at the 10th byte
    close(fd);
}

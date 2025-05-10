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

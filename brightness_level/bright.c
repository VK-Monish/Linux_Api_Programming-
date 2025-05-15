/*
Brightness Percentage Reader in C

This program reads the current brightness level from
"/sys/class/backlight/amdgpu_bl1/brightness" on Linux systems
and prints it to the terminal.

---

Features:
- Reads brightness value from system file.
- Prints brightness value to the terminal.
- Handles errors if the file can't be opened or read.

Requirements:
- Linux system with backlight brightness info at
  /sys/class/backlight/amdgpu_bl1/brightness
- C compiler (e.g., GCC)

How to Compile:
gcc brightness_reader.c -o brightness_reader

How to Run:
./brightness_reader

Example Output:
50 is your laptop Brightness percentage

Notes:
- Buffer size is 4 to safely read values like 100 or more.
- Change the file path if your backlight device differs.
- Requires permission to read the brightness file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define Buffer_size 4
int main()
{
  char buf[Buffer_size];
  int fd;
  size_t read_bright;

  // int open(const char *pathname, int flags, .../* mode_t mode */ );
  
  fd = open("/sys/class/backlight/amdgpu_bl1/brightness",O_RDONLY);
  if(fd == -1)
  {
    perror("open");
    exit(-1);
  }

  // ssize_t read(int fd, void buf[.count], size_t count);

  read_bright = read(fd,buf,Buffer_size);
  if(read_bright == -1)
  {
    perror("Read");
    exit(-1);
  }

  printf(" is your laptop Brightness percentage");

  // ssize_t write(int fd, const void buf[.count], size_t count);

  write(1,buf,Buffer_size);

  close(fd);
}

/*
Battery Percentage Reader in C

This simple C program reads and displays your laptop's battery percentage on Linux systems by accessing the system file 
specified as a command-line argument or defaults to "/sys/class/power_supply/BAT0/capacity".

---

Features:
- Reads battery percentage from the given system file path.
- Prints the battery percentage to the terminal.
- Handles errors if the battery info file is not accessible.

Requirements:
- Linux system with battery info file.
- C compiler (e.g., GCC).

How to Compile:

    gcc battery_percentage.c -o battery_percentage

How to Run:

    ./battery_percentage                # Uses default battery path
    ./battery_percentage /path/to/file # Uses custom battery info path

Expected output example:

    75 is your laptop Battery percentage

Notes:
- The program reads only two bytes, so if your battery percentage is 100, the output might be incomplete.
- If your battery info path is different, provide it as a command-line argument.
- Make sure you have permission to access the battery info file.

Error Handling:
- Prints an error and exits if the battery capacity file cannot be opened or read.

Created by Monish Kumar.K
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#define Buffer_size 2
int main()
{
  char buf[Buffer_size];
  int fd;
  size_t read_batt;

  // int open(const char *pathname, int flags, .../* mode_t mode */ );
  
  fd = open("/sys/class/power_supply/BAT0/capacity",O_RDONLY);
  if(fd == -1)
  {
    perror("open");
    exit(-1);
  }

  // ssize_t read(int fd, void buf[.count], size_t count);

  read_batt = read(fd,buf,Buffer_size);
  if(read_batt == -1)
  {
    perror("Read");
    exit(-1);
  }

  printf(" is your laptop Battery percentage");

  // ssize_t write(int fd, const void buf[.count], size_t count);

  write(1,buf,Buffer_size);

  close(fd);
}

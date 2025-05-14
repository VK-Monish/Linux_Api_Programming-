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

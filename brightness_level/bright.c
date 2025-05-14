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

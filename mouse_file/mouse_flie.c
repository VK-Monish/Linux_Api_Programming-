#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>

#define Buffer_size 64

int main()
{
  char buf[Buffer_size];
  int fd;
  size_t read_mouse;
  struct input_event ev;
  // int open(const char *pathname, int flags, .../* mode_t mode */ );
  
  fd = open("/dev/input/event5",O_RDONLY);
  if(fd == -1)
  {
    perror("open");
    exit(-1);
  }

  // ssize_t read(int fd, void buf[.count], size_t count);

  while(1)
  {
    read_mouse = read(fd,&ev,sizeof(struct input_event));
    if(read_mouse == -1)
    {
      perror("Read");
      exit(-1);
    }
    if(ev.code == 272)
    {
      printf("Right click\n");
    }
    else if(ev.code == 273)
    {
      printf("Left click\n");
    }
    else if(ev.code == 274)
    {
      printf("Midlle button clicked\n");
    }
    else if(ev.code == 0 && ev.value == -1)
    {
      printf("moving X' direction\n");
    }
    else if(ev.code == 0 && ev.value == 1)
    {
      printf("moveing X direction\n");
    }
    else if(ev.code == 1 && ev.value == -1)
    {
      printf("moveing Y' direction\n");
    }
    else if (ev.code == 1 && ev.value == 1)
    {
      printf("moving Y direction\n");
    }
  } 
    close(fd);
}

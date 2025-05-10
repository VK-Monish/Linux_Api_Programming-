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

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fd;
  fd = open("moni1.c",O_RDONLY | O_CREAT)	;
  if(fd == -1)
  {
    printf("No such file");
  }
}

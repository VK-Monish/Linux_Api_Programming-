#include <stdio.h>
#include <sys/stat.h>

int main(int argc,char*argv[])
{
  int fd;
  fd = mkdir("hello",0766);
  if(fd == -1)
  {
    perror("mkdir");
  }
}

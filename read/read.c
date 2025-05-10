#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  int fd,openflag;
  char buf[1000];
  ssize_t bytescnt;
  fd = open("demo.c",O_RDONLY);
  if(fd == -1)
  {
    printf("error in opening file");
  }
  bytescnt = read(fd,buf,1000);
  printf("%s",buf);
}

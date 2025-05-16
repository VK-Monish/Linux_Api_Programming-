#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
  printf("pid %d\n", getpid());
  int fd = open(argv[1], O_RDWR);
  ftruncate(fd, 100);
  getchar(); 
  char *data = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  strcpy(data, "Hello mmap");
  getchar(); 
  munmap(data, 100);
}

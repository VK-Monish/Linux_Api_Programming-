#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
  char*str = "School of linux";
  printf("PID %d\n",getpid());
  getchar();
  
  //void *mmap(void addr[.length], size_t length, int prot, int flags,int fd, off_t offset);

  char*data = mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);

  strcpy(data,str);
  printf("%p %s\n",&data,data);
  getchar();
  munmap(data,strlen(data));
  getchar();
}

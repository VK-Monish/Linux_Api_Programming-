#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  pid_t p = fork();
  if (p<0)
  {
    perror("fork fail");
    exit(-1);
  }
  else if (p == 0)
  {
    printf("This called by the parent process : child process");
  }
  else
  {
    printf("This is parent process\n");
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
    printf("I am the child process\n");
  }
  else if(pid > 1)
  {
    printf("Hello I am the parent process\n");
    sleep(12);
  }
}

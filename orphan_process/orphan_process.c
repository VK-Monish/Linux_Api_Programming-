#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t pid;
  pid = fork();
  if(pid > 0)
  {
    printf("parent process         %d\n",getpid());
  }
  else if (pid == 0)
  {
    printf("The child process      %d\n",getpid());
    printf("The child process ppid %d\n",getppid());
    printf("Before\n");
    sleep(15);
    printf("The child process      %d\n",getpid());
    printf("The child process ppid %d\n",getppid());
    printf("After\n");

  }
}

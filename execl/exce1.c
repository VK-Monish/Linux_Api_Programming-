#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
    execl("./a.out","hello", NULL);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
    execl("/home/moni/bin/a.out", "ls", NULL);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

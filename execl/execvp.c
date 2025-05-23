#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
  pid_t pid;
  pid = fork();
  char *argv[]={"/usr/bin/ls","-l",NULL};
  if(pid == 0)
  {
    //int execvp(const char *file, char *const argv[]);
    execvp("ls",argv);
  }
  else
  {
    printf("%d\n",getpid());
  }
}

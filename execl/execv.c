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
    //int execv(const char *pathname, char *const argv[]);
    execv(argv[0],argv);
  }
  else
  {
    printf("%d\n",getpid());
  }
}


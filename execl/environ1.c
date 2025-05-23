#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
int main()
{
  char*argv[]={"/home/moni/bin/a.out",NULL};
  pid_t pid = fork();
  if (pid == 0)
  {
    char*evp[2] = {"MY_PATH=1234",NULL};
    execvpe("a.out",argv,evp);
  }
  else
  {
    printf("Parent PID: %d\n", getpid());
  }
}


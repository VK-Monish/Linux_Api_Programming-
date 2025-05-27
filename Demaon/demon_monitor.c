#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void sl_daemon()
{
  char *log_file= "/home/moni/love.c";
  int fd;
  int count = 0;
  while(1)
  {
    if(count < 30)
    {
      fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
      dprintf(fd,"Hello...I am monish and my roll number is: %d\n",getpid());
      if(fd == -1)
      {
	perror("open");
      }
    }

    else if(count == 30)
    {
      open(log_file,O_TRUNC);
    }
    count++;

    if(count > 30)
    {
      count = 0;
    }
    sleep(2);
  }
}

int main() 
{
  int i;
  pid_t pid;
  pid = fork();
  if(pid < 0 )
  {
    perror("fork");
  }
  if(pid>0)
  {
    printf("Parent process%d\n",getpid());
    exit(EXIT_SUCCESS);
  }
  i = sysconf(_SC_OPEN_MAX);
  for(i;i>=0; i--)
  {
    close(i);
  }
  sl_daemon();
}

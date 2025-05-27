#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
  pid_t pid = fork();
  if (pid < 0) 
  {
    perror("fork failed");
    exit(1);
  }
  if (pid > 0) 
  {
    printf("Child process running as daemon. PID: %d\n", pid);
    exit(0);
  }
  while (1) 
  {
    int fd  = open("/home/moni/ai.c", O_WRONLY | O_CREAT | O_APPEND,0644);
    if (fd) 
    {
      dprintf(fd, "Hello from daemon! PID = %d\n", getpid());
      close(fd);
    }
    sleep(1);
  }
}

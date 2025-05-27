#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
  int ki;
  pid_t pid = 37186;
  ki = kill(pid,SIGTERM);
  if (ki == -1) 
  {
    perror("kill failed");
    return 1;
  }
  printf("Signal sent to process %d\n", pid);
}


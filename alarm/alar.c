#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handle()
{
  printf("The times up\n");
  exit(-1);
}

int main()
{
  signal(SIGALRM,handle);
  alarm(5);

  printf("wait for signal\n");
  sleep(10);
}

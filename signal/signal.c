#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ctrl_c()
{
  printf("hello");
}

int main() 
{
  signal(SIGINT, ctrl_c);

  while(1)
  {
    printf("%d\n",getpid());
    sleep(2);
  }
}
